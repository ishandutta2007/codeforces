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
// #pra gma GCC opti mize(3)
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
	    int x,ch;while((ch=gc())<'0'||ch>'9');x=ch^'0';
	    while((ch=gc())>='0'&&ch<='9') x=(x<<1)+(x<<3)+(ch^'0');return x;
	}
	char ss[19999999],tt[20];int ssl,ttl;
    inline int print(int x)
    {
        if(x<0)ss[++ssl]='-',x=(-x);
		if(!x) ss[++ssl]='0';for(ttl=0;x;x/=10) tt[++ttl]=char(x%10+'0');
        for(;ttl;ttl--) ss[++ssl]=tt[ttl];return ss[++ssl]='\n';
    }
	inline int Flush(){return fwrite(ss+1,sizeof(char),ssl,stdout),ssl=0,0;}
	int read(){
		char c=getchar();int x=1;int s=0;
		while(c<'0' || c>'9'){if(c=='-')x=-1;c=getchar();}
		while(c>='0' && c<='9'){
			s=s*10+c-'0';c=getchar();
		}
		return s*x;
	}
}using namespace IO_BUFF;
const int N=3e5+5;
int T,n,a[N],b[N];
vi va[N],vb[N];
int dfn[N],ed[N],tot;
void dfs1(int u,int fa){
	dfn[u]=++tot;
	for(auto i:vb[u]){
		if(i==fa)continue;
		dfs1(i,u);
	}
	ed[u]=tot;
}
#define mid ((l+r)>>1)
#define ls (u<<1)
#define rs (u<<1|1)
int summ[N*4],minn[N*4],cd[N],ans;
void update(int u){
	summ[u]=summ[ls]+summ[rs];
	minn[u]=min(minn[ls],minn[rs]);
}
void build(int u,int l,int r){
	if(l==r){
		summ[u]=0;minn[u]=1e9;
		return ;
	}
	build(ls,l,mid);
	build(rs,mid+1,r);
	update(u);
}
void add(int u,int l,int r,int x,int k){
	if(l==r){
		summ[u]++;
		minn[u]=k;
		cd[minn[u]]=l;
		return ;
	}
	if(x<=mid)add(ls,l,mid,x,k);
	else add(rs,mid+1,r,x,k);
	update(u);
}
int query(int u,int l,int r,int L,int R){
	if(L>R)return 1e9;
	if(L<=l && R>=r){
		return minn[u];
	}
	if(R<=mid)return query(ls,l,mid,L,R);
	if(L>mid)return query(rs,mid+1,r,L,R);
	return min(query(ls,l,mid,L,R),query(rs,mid+1,r,L,R));
}
int ask(int u,int l,int r,int L,int R){
	if(L>R)return 0;
	if(L<=l && R>=r){
		return summ[u];
	}
	if(R<=mid)return ask(ls,l,mid,L,R);
	if(L>mid)return ask(rs,mid+1,r,L,R);
	return (ask(ls,l,mid,L,R)+ask(rs,mid+1,r,L,R));
}
void del(int u,int l,int r,int x){
	if(l==r){
		summ[u]--;
		cd[minn[u]]=0;
		minn[u]=1e9;
		return ;
	}
	if(x<=mid)del(ls,l,mid,x);
	else del(rs,mid+1,r,x);
	update(u);
}
int sx[N],sy[N];
int fx[N];
void dfs(int u,int fa){
	int tmp=query(1,1,n,ed[u],n);
	if(tmp<=dfn[u]){
		int pos=cd[tmp];
		sx[u]=pos;
		sy[u]=tmp;
		del(1,1,n,pos);
	}
	add(1,1,n,ed[u],dfn[u]);
	fx[u]=1;
	ans=max(ans,summ[1]);
	for(auto i:va[u]){
		if(i==fa)continue;
		dfs(i,u);
	}
	if(fx[u]==1){
		del(1,1,n,ed[u]);
	}
	if(sx[u]){
		add(1,1,n,sx[u],sy[u]);
	}
}
signed main(){
	#ifdef newbiewzs
		freopen("data.in","r",stdin);
	#else
	#endif
	T=read();
	while(T--){
		n=read();
		for(int i=2;i<=n;i++)a[i]=read();
		for(int i=2;i<=n;i++)b[i]=read();
		for(int i=2;i<=n;i++){
			va[a[i]].pb(i);
			vb[b[i]].pb(i);
		}
		build(1,1,n);
		dfs1(1,0);
		dfs(1,0);
		cout<<ans<<'\n';
		for(int i=1;i<=n;i++)va[i].clear(),vb[i].clear();
		for(int i=1;i<=n;i++)sx[i]=sy[i]=fx[i]=0;
		ans=0;
		tot=0;
		for(int i=1;i<=n;i++)dfn[i]=ed[i]=0;
		for(int i=1;i<=n;i++)cd[i]=0;
	}
	return 0;
}