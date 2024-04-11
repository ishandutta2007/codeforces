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
#define dsi(x,y,z) cerr<<"In Line "<<__LINE__<<" the "<<#x<<" = "<<x<<" ; "<<"the "<<#y<<" = "<<y<<" ; the "<<#z<<" = "<<z<<'\n';
#define fr(i,a,b) for(int i=a;i<=b;i++)
#define rf(i,a,b) for(int i=a;i>=b;i--)
// #pragma GCC optimize(3)
//#define int long long
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
const int N=5e4+5;
const int B=256;
int n,q,x,y,a[N],deep[N],fu[N];
int Fu[N],st[N],top;
vi v[N];
int f[N][B+5],w[B*2];
int ch[B*9][2],tot,rt;
void ins(int x){
	int u=rt;
	rf(i,7,0){
		int v=(x>>i)&1;
		if(!ch[u][v]){
			ch[u][v]=++tot;
		}
		u=ch[u][v];
	}
}
auto ask(int x){
	int tmp=0,u=rt,val=0;
	rf(i,7,0){
		int v=(x>>i)&1;
		if(ch[u][v^1])u=ch[u][v^1],val|=((v^1)<<i),tmp|=(1<<i);
		else u=ch[u][v],val|=(v<<i);
	}
	return tmp*B+w[val];
}
void dfs(int u,int fa){
	st[++top]=u;
	deep[u]=deep[fa]+1;
	fu[u]=fa;
	for(auto i:v[u]){
		if(i==fa)continue;
		dfs(i,u);
	}
	if(top>B){
		Fu[u]=st[top-B];
		mem0(ch);
		mem0(w);
		tot=0;
		int nw=u,pre=0;
		while(nw!=Fu[u]){
			w[a[nw]/B]=max(w[a[nw]/B],pre^(a[nw]&(B-1)));
			ins(a[nw]/B);
			nw=fu[nw];
			pre++;
		}
		fr(i,0,B-1)f[u][i]=ask(i);
	}
	top--;
}
int main(){
	#ifdef newbiewzs
		freopen("data.in","r",stdin);
	#else
	#endif
	n=read();q=read();
	fr(i,1,n)a[i]=read();
	fr(i,1,n-1){
		x=read();y=read();
		v[x].pb(y);
		v[y].pb(x);
	}
	dfs(1,0);
	fr(i,1,q){
		x=read();y=read();
		int ans=0,pre=0;
		while(deep[y]-deep[x]>B){
			ans=max(ans,f[y][pre/B]);
			y=Fu[y];pre+=B;
		}
		while(deep[y]>=deep[x]){
			ans=max(ans,a[y]^pre);
			y=fu[y];pre++;
		}
		cout<<ans<<'\n';
	}
	return 0;
}