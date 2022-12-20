#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll readint(){
	ll x=0;
	bool f=0;
	char c=getchar();
	while(!isdigit(c)&&c!='-') c=getchar();
	if(c=='-'){
		f=1;
		c=getchar();
	}
	while(isdigit(c)){
		x=x*10+c-'0';
		c=getchar();
	}
	return f?-x:x;
}
const int maxn=30+5,maxl=1e5+5;
int n,len[maxn],cur[maxn];
char tmp[maxl],*a[maxn];
int nxt[maxl],ext[maxl];
vector<int> g[maxl];
int vis[maxl];
bool dfs(int u){
	vis[u]=-1;
	for(int v:g[u])
		if(vis[v]<0) return 0;
		else if(!vis[v]&&!dfs(v)) return 0;
	vis[u]=1;
	return 1;
}
bool check(int L,int R){
	for(int i=0;i<=cur[n]+len[n];i++) vector<int>().swap(g[i]);
	for(int i=L;i<=R;i++){
		int l=0,r=0;
		nxt[1]=len[i];
		for(int j=2;j<=len[i];j++){
			nxt[j]=j<=r?min(nxt[j-l+1],r-j+1):0;
			while(j+nxt[j]<=len[i]&&a[i][j+nxt[j]]==a[i][nxt[j]+1]) nxt[j]++;
			if(j+nxt[j]-1>r){
				l=j;
				r=j+nxt[j]-1;
			}
		}
		for(int j=L;j<=R;j++){
			r=0;
			for(int k=1;k<=len[j];k++){
				ext[k]=k<=r?min(nxt[k-l+1],r-k+1):0;
				while(k+ext[k]<=len[j]&&ext[k]<len[i]&&a[j][k+ext[k]]==a[i][ext[k]+1]) ext[k]++;
				if(k+ext[k]-1>r){
					l=k;
					r=k+ext[k]-1;
				}
			}
			for(int k=1;k<=len[j];k++)
				if(len[j]-k+1<len[i]){
					if(ext[k]==len[j]-k+1) g[cur[j]+k].push_back(cur[i]+len[j]-k+2);
				}
				else if(len[j]-k+1>len[i]){
					if(ext[k]==len[i]) g[cur[j]+k].push_back(cur[j]+k+len[i]);
				}
				else if(ext[k]==len[i]&&k>1) g[cur[j]+k].push_back(0);
		}
	}
	for(int i=L;i<=R;i++) g[0].push_back(cur[i]+1);
	memset(vis,0,sizeof(vis));
	for(int i=0;i<=cur[n]+len[n];i++) if(!vis[i]&&!dfs(i)) return 0;
	return 1;
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	n=readint();
	a[0]=tmp;
	for(int i=1;i<=n;i++){
		a[i]=a[i-1]+len[i-1];
		cur[i]=cur[i-1]+len[i-1];
		scanf("%s",a[i]+1);
		len[i]=strlen(a[i]+1);
	}
	int l=1,ans=0;
	for(int i=1;i<=n;i++){
		while(!check(l,i)) l++;
		ans+=i-l+1;
	}
	printf("%d\n",ans);
	#ifdef LOCAL
	fprintf(stderr,"%d\n",(int)clock());
	#endif
	return 0;
}