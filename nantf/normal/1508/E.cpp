#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=333333,mod=998244353;
#define MP make_pair
#define PB push_back
#define lson o<<1,l,mid
#define rson o<<1|1,mid+1,r
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline ll read(){
	char ch=getchar();ll x=0,f=0;
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
inline int qpow(int a,int b){
	int ans=1;
	for(;b;b>>=1,a=1ll*a*a%mod) if(b&1) ans=1ll*ans*a%mod;
	return ans;
}
int n,a[maxn],b[maxn],id1[maxn],c1,id2[maxn],c2,dep[maxn],fa[maxn],s[maxn];
vector<int> e[maxn];
inline bool cmp(int x,int y){return a[x]<a[y];}
void dfs(int u){
	id1[u]=++c1;
	FOR(i,0,(int)e[u].size()-1){
		int v=e[u][i];
		dep[v]=dep[u]+1;
		fa[v]=u;
		dfs(v);
	}
	id2[u]=++c2;
}
int main(){
	n=read();
	FOR(i,1,n) a[i]=b[i]=read();
	FOR(i,1,n-1){
		int u=read(),v=read();
		e[u].PB(v);
	}
	FOR(i,1,n) sort(e[i].begin(),e[i].end(),cmp);
	dfs(1);
	int x=a[1]-1;
	if(!x){
		FOR(i,1,n) if(a[i]!=id1[i]) return puts("NO"),0;
		puts("YES");
		puts("0");
		FOR(i,1,n) printf("%d ",id1[i]);
		return 0;
	}
	FOR(i,1,n) if(id2[i]==x){
		bool flag=false;
		int now=i;
		while(now) flag|=a[now]==x,now=fa[now];
		if(!flag) return puts("NO"),0;
	}
	FOR(i,1,n) if(a[i]==x){
		int now=i;
		while(fa[now]) swap(b[now],b[fa[now]]),now=fa[now];
		break;
	}
	FOR(i,1,n) if(b[i]<x){
		if(b[i]!=id2[i]) return puts("NO"),0;
		s[id1[i]]++;
	}
	ROF(i,n,1) s[i]+=s[i+1]; 
	FOR(i,1,n) if(b[i]>=x){
		if(b[i]!=id1[i]+s[id1[i]]) return puts("NO"),0;
	}
	puts("YES");
	ll ans=0;
	FOR(i,1,n) if(a[i]<=x) ans+=dep[i];
	printf("%lld\n",ans);
	FOR(i,1,n) printf("%d ",id1[i]);
}