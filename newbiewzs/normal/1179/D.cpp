#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
#include<queue>
#include<vector>
#include<map>
#include<bitset>
#include<set>
#include<cmath>
#include<ctime>
#include<random>
#define vi vector<int>
#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define bc(x) __builtin_popcount(x)
#define re register
#define il inline
#define pii pair<int,int>
#define pil pair<int,long long>
#define pll pair<long long,long long>
#define mem0(x) memset(x,0,sizeof(x))
#define mem0x3f(x) memset(x,0x3f,sizeof(x))
#define dbg(x) cerr<<"In Line "<< __LINE__<<" the "<<#x<<" = "<<x<<'\n';
#define dpi(x,y) cerr<<"In Line "<<__LINE__<<" the "<<#x<<" = "<<x<<" ; "<<"the "<<#y<<" = "<<y<<'\n';
#define dsi(x,y,z) cerr<<"In Line "<<__LINE__<<" the "<<#x<<" = "<<x<<" ; "<<"the "<<#y<<" = "<<y<<" the "<<#z<<" = "<<z<<'\n';
#define fer(i,a,b) for(int i=a;i<=b;i++)
#define erf(i,a,b) for(int i=b;i>=a;i--)
// #pragma GCC optimize(3)
#define int long long
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
namespace IO_BUFF{
	mt19937 rnd(time(0)^(ll)(new char));
	int rend(int x){
		return rnd()%x+1;
	}
	void rendom_shuffle(int *a,int len){
		shuffle(a+1,a+len+1,rnd);
	}
	const int BS=(1<<24)+5;char Buffer[BS],*HD,*TL;
	inline int gc(){
	    if(HD==TL) TL=(HD=Buffer)+fread(Buffer,1,BS,stdin);
	    return (HD==TL)?EOF:*HD++;
	}
	inline int inn(){
	    int x,ch,s=1;while((ch=gc())<'0'||ch>'9')if(ch=='-')s=-1;x=ch^'0';
	    while((ch=gc())>='0'&&ch<='9') x=(x<<1)+(x<<3)+(ch^'0');return x*s;
	}
	char ssss[19999999],tttt[20];int ssl,ttl;
    inline int print(int x)
    {
        if(x<0)ssss[++ssl]='-',x=(-x);
		if(!x) ssss[++ssl]='0';for(ttl=0;x;x/=10) tttt[++ttl]=char(x%10+'0');
        for(;ttl;ttl--) ssss[++ssl]=tttt[ttl];return ssss[++ssl]='\n';
    }
	inline int Flush(){return fwrite(ssss+1,sizeof(char),ssl,stdout),ssl=0,0;}
	int read(){
		char c=getchar();int x=1;int s=0;
		while(c<'0' || c>'9'){if(c=='-')x=-1;c=getchar();}
		while(c>='0' && c<='9'){
			s=s*10+c-'0';c=getchar();
		}
		return s*x;
	}
}using namespace IO_BUFF;
/*namespace CFConTest{
	const int mod=998244353;
	inline int add(const int &x,const int &y){
		return (x+y>=mod?x+y-mod:x+y);
	}
	inline int del(const int &x,const int &y){
		return (x-y<0?x-y+mod:x-y);
	}
	int ksm(int x,int k){
		int base=1;
		while(k){
			if(k&1)base=1ll*base*x%mod;
			k>>=1;
			x=1ll*x*x%mod;
		}
		return base;
	}
};
using namespace CFConTest;*/
const int N=5e5+5;
int n,x,y,ans=1e15,g[N],siz[N],f[N];
vi v[N];
int st[N],top;
int q[N],head,tail;
int cmp(int x,int y){
	return siz[x]<siz[y];
}
void dfs(int u,int fa){
	siz[u]=1;
	for(auto i:v[u]){
		if(i==fa)continue;
		dfs(i,u);
		siz[u]+=siz[i];
		ans=min(ans,f[i]+(n-siz[i])*(n-siz[i]));
	}
	for(auto i:v[u]){
		if(i==fa)continue;
		f[u]=min(f[u],f[i]+(siz[u]-siz[i])*(siz[u]-siz[i]));
	}
	f[u]=min(f[u],siz[u]*siz[u]);
	top=0;
	for(auto i:v[u]){
		if(i==fa)continue;
		st[++top]=i;
	}
	sort(st+1,st+top+1,cmp);
	for(int i=1;i<=top;i++){
		int u=st[i];
		g[u]=siz[u]*siz[u]+f[u];
	}
	head=tail=1;q[1]=st[1];
	for(int i=2;i<=top;i++){
		int uu=st[i];
		while(head<tail && (g[q[head+1]]-g[q[head]])>=(siz[q[head+1]]-siz[q[head]])*2*(n-siz[uu]))head++;
		ans=min(ans,f[uu]+f[q[head]]+(n-siz[uu]-siz[q[head]])*(n-siz[uu]-siz[q[head]]));
		while(head<tail && (g[q[tail]]-g[q[tail-1]])*(siz[uu]-siz[q[tail]])>=(g[uu]-g[q[tail]])*(siz[q[tail]]-siz[q[tail-1]]))tail--;
		q[++head]=uu;
	}
}
signed main(){
	#ifdef newbiewzs
		freopen("data.in","r",stdin);
	#else
	#endif
	n=read();mem0x3f(f);
	for(int i=1;i<n;i++){
		x=read();y=read();
		v[x].pb(y);
		v[y].pb(x);
	}
	dfs(1,0);
	cout<<((n*(n-1))/2+(n*n-ans)/2);
    #ifdef newbiewzs
		cerr<<'\n'<<"Time:"<<clock()<<" ms"<<'\n';
	#endif
	return 0;
}