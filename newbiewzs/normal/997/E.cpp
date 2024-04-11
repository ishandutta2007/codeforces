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
const int N=1.2e5+5;
int n,m,l,r,a[N],ans[N];
vector<pii>q[N];
#define ls (u<<1)
#define rs (u<<1|1)
#define mid ((l+r)>>1)
int summ[N*4],minn[N*4],cnt[N*4];
int ad[N*4],tag[N*4];
void addminn(int u,int x){
	minn[u]+=x;
	ad[u]+=x;
}
void addtag(int u,int x){
	tag[u]+=x;
	summ[u]+=cnt[u]*x;
}
void pushdown(int u){
	if(ad[u]){
		addminn(ls,ad[u]);
		addminn(rs,ad[u]);
		ad[u]=0;
	}
	if(tag[u]){
		if(minn[u]==minn[ls])addtag(ls,tag[u]);
		if(minn[u]==minn[rs])addtag(rs,tag[u]);
		tag[u]=0;
	}
}
void update(int u){
	minn[u]=min(minn[ls],minn[rs]);
	cnt[u]=(minn[u]==minn[ls])*cnt[ls]+(minn[u]==minn[rs])*cnt[rs];
	summ[u]=summ[ls]+summ[rs];
}

void add(int u,int l,int r,int L,int R,int x){
	if(L<=l && R>=r){
		addminn(u,x);
		return ;
	}
	pushdown(u);
	if(L<=mid)add(ls,l,mid,L,R,x);
	if(R>mid)add(rs,mid+1,r,L,R,x);
	update(u);
}
int query(int u,int l,int r,int L,int R){
	if(L<=l && R>=r)return summ[u];
	pushdown(u);
	if(R<=mid)return query(ls,l,mid,L,R);
	if(L>mid)return query(rs,mid+1,r,L,R);
	return query(ls,l,mid,L,R)+query(rs,mid+1,r,L,R);
}
void build(int u,int l,int r){
	if(l==r){
		minn[u]=l;cnt[u]=1;
		return ;
	}
	build(ls,l,mid);
	build(rs,mid+1,r);
	update(u);
}
int sta[N],topa; // min 
int stb[N],topb; // max
signed main(){
	#ifdef newbiewzs
		freopen("data.in","r",stdin);
	#else
	#endif
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	m=read();
	for(int i=1;i<=m;i++){
		l=read();r=read();
		q[r].pb(mp(l,i));
	}
	build(1,1,n);
	for(int i=1;i<=n;i++){
		while(topa && a[sta[topa]]>a[i]){
			add(1,1,n,sta[topa-1]+1,sta[topa],a[sta[topa]]-a[i]);
			topa--;
		}
		while(topb && a[stb[topb]]<a[i]){
			add(1,1,n,stb[topb-1]+1,stb[topb],a[i]-a[stb[topb]]);
			topb--;
		}
		addtag(1,1);
		addminn(1,-1);
		sta[++topa]=i;
		stb[++topb]=i;
		for(auto k:q[i]){
			ans[k.se]=query(1,1,n,k.fi,i);
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<'\n';
    #ifdef newbiewzs
		cerr<<'\n'<<"Time:"<<clock()<<" ms"<<'\n';
	#endif
	return 0;
}