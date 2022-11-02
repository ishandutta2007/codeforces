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
const int N=1e6+5;
int n,m,s,x,y,a[N],b[N],M,mb,val[N],tong[N];
struct GW{
	int x,y,z;
}c[N];
int cmp(GW x,GW y){
	return x.x<y.x;
}
#define ls (u<<1)
#define rs (u<<1|1)
#define mid ((l+r)>>1)
int maxx[N*4],tag[N*4];
void build(int u,int l,int r){
	if(l==r){
		maxx[u]=-tong[l];
		return ;
	}
	build(ls,l,mid);
	build(rs,mid+1,r);
	maxx[u]=max(maxx[ls],maxx[rs]);
}
void pushdown(int u){
	if(tag[u]==0)return ;
	tag[ls]+=tag[u];
	tag[rs]+=tag[u];
	maxx[ls]+=tag[u];
	maxx[rs]+=tag[u];
	tag[u]=0;
	return ;
}
void add(int u,int l,int r,int L,int R,int k){
	if(L>R)return ;
	if(L<=l && R>=r){
		maxx[u]+=k;
		tag[u]+=k;
		return ;
	}
	pushdown(u);
	if(L<=mid)add(ls,l,mid,L,R,k);
	if(R>mid)add(rs,mid+1,r,L,R,k);
	maxx[u]=max(maxx[ls],maxx[rs]);
}
signed main(){
	#ifdef newbiewzs
		freopen("data.in","r",stdin);
	#else
	#endif
	n=read();m=read();s=read();
	memset(val,10,sizeof(val));
	memset(tong,10,sizeof(tong));
	for(int i=1;i<=n;i++)x=read(),y=read(),val[x]=min(val[x],y),M=max(M,x);
	for(int i=1;i<=m;i++){
		x=read(),y=read();
		tong[x]=min(tong[x],y);
		mb=max(mb,x);
	}
	sort(a+1,a+n+1);
	sort(b+1,b+m+1);
	build(1,1,mb);
	for(int i=1;i<=s;i++){
		c[i].x=read();c[i].y=read();c[i].z=read();
	}
	sort(c+1,c+s+1,cmp);
	int head=1,ans=-1e15;
	for(int i=1;i<=M;i++){
		while(head<=s && c[head].x<i){
			add(1,1,mb,c[head].y+1,mb,c[head].z);
			head++;
		}
		if(val[i]<=1e9){
			ans=max(ans,-val[i]+maxx[1]);
		}
	}
	cout<<ans;
	return 0;
}