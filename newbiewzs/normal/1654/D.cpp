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
namespace CFConTest{
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
using namespace CFConTest;
const int N=4e5+5;
const int M=2e5;
int T,n,in[N],rt;
int x,y,xx,yy;
struct node{
	int to,x,y;
};
vector<node>v[N];
int vis[N],st[N],las[N],top;
void init(){
	for(int i=2;i<=M;i++){
		if(!vis[i])st[++top]=i,las[i]=i;
		for(int k=1;k<=top && st[k]*i<=M;k++){
			vis[i*st[k]]=1;las[i*st[k]]=st[k];
			if(i%st[k]==0)break;
		}
	}
}
int tong[N],maxx[N];
void dfs(int u,int fa){
	
	for(auto i:v[u]){
		if(i.to==fa)continue;
		int uu=i.x;
		
		int vv=i.y;
		while(vv!=1){
			int tmp=las[vv];
			while(vv%tmp==0)vv/=tmp,tong[tmp]++;
		}
		while(uu!=1){
			int tmp=las[uu];
			while(uu%tmp==0){
				uu/=tmp;
				tong[tmp]--;
			}
			maxx[tmp]=max(maxx[tmp],-tong[tmp]);
		}
		dfs(i.to,u);
		uu=i.x;
		while(uu!=1){
			int tmp=las[uu];
			while(uu%tmp==0)uu/=tmp,tong[tmp]++;
		}
		vv=i.y;
		while(vv!=1){
			int tmp=las[vv];
			while(vv%tmp==0)vv/=tmp,tong[tmp]--;
		}
	}
}
int summ;
void dfs1(int u,int fa,int noww){
	summ=add(summ,noww);
	for(auto i:v[u]){
		if(i.to==fa)continue;
		dfs1(i.to,u,1ll*i.y*ksm(i.x,mod-2)%mod*noww%mod);
	}
}
signed main(){
	#ifdef newbiewzs
		freopen("data.in","r",stdin);
	#else
	#endif
	T=read();
	init();
	while(T--){
		n=read();summ=0;
		for(int i=1;i<=n;i++)maxx[i]=0,tong[i]=0;
		for(int i=1;i<n;i++){
			x=read();y=read();
			xx=read();yy=read();
			v[x].pb({y,xx,yy});
			v[y].pb({x,yy,xx});
		}
		dfs(1,0);
		int ans=1;
		for(int i=1;i<=n;i++){
			for(int k=1;k<=maxx[i];k++){
				ans=ans*i%mod;
			}
		}
		dfs1(1,0,ans);
		cout<<summ<<'\n';
		for(int i=1;i<=n;i++)v[i].clear();
	}
    #ifdef newbiewzs
		cerr<<'\n'<<"Time:"<<clock()<<" ms"<<'\n';
	#endif
	return 0;
}