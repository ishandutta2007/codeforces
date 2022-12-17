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
const int maxn=1.5e5+5;
int n,m;
vector<int> g[maxn],g2[maxn];
bool t[maxn];
int l[maxn],r[maxn];
bool vis[maxn][2];
void dfs1(int u,bool f){
	if(vis[u][f]) return;
	vis[u][f]=1;
	for(int v:g[u]) if(r[u+1]>=v-1) dfs1(v-1,!f);
}
void dfs2(int u,bool f){
	if(vis[u][f]) return;
	vis[u][f]=1;
	for(int v:g2[u+1]) if(l[u]<=v+1) dfs2(v,!f);
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	int T=readint();
	while(T--){
		n=readint();
		m=readint();
		for(int i=1;i<=n;i++){
			vector<int>().swap(g[i]);
			vector<int>().swap(g2[i]);
		}
		memset(t,0,sizeof(t));
		for(int i=1;i<=m;i++){
			int a,b;
			a=readint();
			b=readint();
			if(b==a+1) t[a]=1;
			else{
				g[a].push_back(b);
				g2[b].push_back(a);
			}
		}
		t[0]=t[n]=1;
		for(int i=1;i<=n;i++){
			if(i<n) g[i].push_back(n+1);
			if(i>1) g2[i].push_back(0);
		}
		for(int i=1;i<=n+1;i++) l[i]=t[i-1]?l[i-1]:i;
		if(!l[n+1]){
			printf("%lld\n",1ll*n*(n-1)/2);
			continue;
		}
		r[n+1]=n+1;
		for(int i=n;i>=0;i--) r[i]=t[i]?r[i+1]:i;
		memset(vis,0,sizeof(vis));
		dfs1(r[1],1);
		vis[r[1]][1]=0;
		dfs2(r[1],1);
		int cnt1=0,cnt2=0;
		for(int i=0;i<=r[1];i++) cnt1+=vis[i][1];
		for(int i=l[n]-1;i<=n;i++) cnt2+=vis[i][1];
		ll ans=1ll*cnt1*cnt2;
		cnt1=cnt2=0;
		for(int i=0;i<=r[1];i++) cnt1+=vis[i][0];
		for(int i=l[n]-1;i<=n;i++) cnt2+=vis[i][0];
		ans+=1ll*cnt1*cnt2;
		cnt1=cnt2=0;
		for(int i=0;i<=r[1];i++) cnt1+=vis[i][0]&&vis[i][1];
		for(int i=l[n]-1;i<=n;i++) cnt2+=vis[i][0]&&vis[i][1];
		ans-=1ll*cnt1*cnt2;
		auto chk=[](int x,int y){
			return (vis[x][0]&&vis[y-1][0])||(vis[x][1]&&vis[y-1][1]);
		};
		if(r[1]==l[n]-1)
			ans-=chk(r[1],r[1])+chk(l[n],l[n])+chk(r[1],l[n]);
		else if(r[1]==l[n]-2) ans-=chk(r[1]+1,r[1]+1);
		printf("%lld\n",ans);
	}
	#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
	#endif
	return 0;
}