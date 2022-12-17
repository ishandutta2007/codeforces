#include<bits/stdc++.h>
using namespace std;
using ll=long long;
inline ll read(){
	ll x=0;
	bool f=0;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-') f=1;
		c=getchar();
	}
	while(isdigit(c)){
		x=x*10+c-'0';
		c=getchar();
	}
	return f?-x:x;
}
const int maxn=1e5+5;
int n,m;
char a[maxn];
int pre[maxn][26],suc[maxn][26],ord[26];
int f[maxn][26],g[maxn][26],s[maxn];
bool vis[32];
int main(){
#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	scanf("%s",a+1);
	n=strlen(a+1);
	for(int i=0;i<26;i++) suc[n+1][i]=n+1;
	for(int i=n;i>0;i--){
		for(int j=0;j<26;j++) suc[i][j]=suc[i+1][j];
		suc[i][a[i]-'a']=i;
	}
	for(int i=1;i<=n;i++){
		int c=a[i]-'a';
		s[i]=s[pre[i-1][c]]^f[i-1][c];
		for(int j=0;j<26;j++) pre[i][j]=pre[i-1][j];
		pre[i][c]=i;
		for(int j=0;j<26;j++) ord[j]=j;
		sort(ord,ord+26,[i](int a,int b){
			return pre[i][a]>pre[i][b];
		});
		for(int j:ord){
			memset(vis,0,sizeof(vis));
			for(int k:ord) if(pre[i][k]>pre[i][j]){
				int x=suc[pre[i][j]+1][k];
				vis[f[i][k]^f[x-1][j]^s[pre[i][k]]^s[x]]=1;
			}
			while(vis[f[i][j]]) f[i][j]++;
		}
	}
	for(int i=n;i>0;i--){
		for(int j=0;j<26;j++) ord[j]=j;
		sort(ord,ord+26,[i](int a,int b){
			return suc[i][a]<suc[i][b];
		});
		for(int j:ord){
			memset(vis,0,sizeof(vis));
			for(int k:ord) if(suc[i][k]<suc[i][j]){
				int x=pre[suc[i][j]-1][k];
				vis[g[i][k]^g[x+1][j]^s[suc[i][k]]^s[x]]=1;
			}
			while(vis[g[i][j]]) g[i][j]++;
		}
	}
	m=read();
	while(m--){
		int l,r;
		l=read();
		r=read();
		bool flag=0;
		for(int i=0;i<26;i++) if(pre[r][i]>=l)
			flag|=!(f[r][i]^g[l][i]^s[pre[r][i]]^s[suc[l][i]]);
		printf(flag?"Alice\n":"Bob\n");
	}
#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
#endif
	return 0;
}