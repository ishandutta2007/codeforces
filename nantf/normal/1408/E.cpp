#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=222222,mod=998244353;
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
inline int qmo(int x){return x+(x>>31?mod:0);}
struct edge{
	int u,v,w;
	bool operator<(const edge &e)const{
		return w>e.w;
	}
}e[maxn];
int n,m,a[maxn],b[maxn],el,fa[maxn];
ll ans;
int getfa(int x){
	return x==fa[x]?x:fa[x]=getfa(fa[x]);
}
int main(){
	n=read();m=read();
	FOR(i,1,n) a[i]=read();
	FOR(i,1,m) b[i]=read();
	FOR(i,1,n){
		int l=read();
		while(l--){
			int x=read();
			e[++el]=(edge){i,x+n,a[i]+b[x]};
			ans+=a[i]+b[x];
		}
	}
	sort(e+1,e+el+1);
	FOR(i,1,n+m) fa[i]=i;
	FOR(i,1,el){
		int u=e[i].u,v=e[i].v,w=e[i].w;
		u=getfa(u);v=getfa(v);
		if(u==v) continue;
		fa[u]=v;
		ans-=w;
	}
	printf("%lld\n",ans);
}