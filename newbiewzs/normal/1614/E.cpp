#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
#include<queue>
#include<vector>
#include<map>
#include<ctime>
#include<bitset>
#include<set>
#define vi vector<int>
#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define bc(x) __builtin_popcount(x)
#define fl fflush(stdout)
#define re register
#define il inline
#define pii pair<int,int>
#define pil pair<int,long long>
#define pll pair<long long,long long>
#define mem0(x) memset(x,0,sizeof(x))
#define mem0x3f(x) memset(x,0x3f,sizeof(x))
// #pra gma GCC opti mize(3)
//#define int long long
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
namespace IO_BUFF{
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
const int N=2e5+5;
const int M=1e9;
const int mod=1e9+1;
int rt,cl[N*80],cr[N*80],minn[N*80],maxx[N*80],tag[N*80];
int tot;
int n,x,m,las;
#define mid ((l+r)>>1)
#define ls cl[u]
#define rs cr[u]
int newnode(int l,int r){
	int u=++tot;
	maxx[u]=r;
	minn[u]=l;
	return u;
}
void pushr(int u,int x){
	minn[u]+=x;
	maxx[u]+=x;
	tag[u]+=x;
}
void pushdown(int u,int l,int r){
	if(!ls)ls=newnode(l,mid);
	if(!rs)rs=newnode(mid+1,r);
	if(!tag[u])return ;
	pushr(ls,tag[u]);
	pushr(rs,tag[u]);
	tag[u]=0;
}
void update(int u){
	maxx[u]=max(maxx[ls],maxx[rs]);
	minn[u]=min(minn[ls],minn[rs]); 
}
void add(int &u,int l,int r,int L,int R,int x){
	if(!u)u=newnode(l,r);
	if(L<=l && R>=r){
		pushr(u,x);
		return ;
	}
	pushdown(u,l,r);
	if(L<=mid)add(ls,l,mid,L,R,x);
	if(R>mid)add(rs,mid+1,r,L,R,x);
	update(u);
}
int query(int u,int l,int r,int x){
	if(l==r){
		return maxx[u];
	}
	pushdown(u,l,r);
	if(x<=mid)return query(ls,l,mid,x);
	else return query(rs,mid+1,r,x);
} 
int queryl(int u,int l,int r,int x){
	if(l==r){
		return l;
	}
	pushdown(u,l,r);
	if(minn[rs]<x)return queryl(rs,mid+1,r,x);
	else return queryl(ls,l,mid,x);
}
int queryr(int u,int l,int r,int x){
	if(l==r){
		return l;
	}
	pushdown(u,l,r);
	if(maxx[ls]>x)return queryr(ls,l,mid,x);
	else return queryr(rs,mid+1,r,x);
}
int main(){
	#ifdef newbiewzs
		freopen("data.in","r",stdin);
	#else
	#endif
	n=read();
	rt=newnode(0,M);
	for(int i=1;i<=n;i++){
		x=read();
		if(minn[rt]<x){
			int tmp=queryl(rt,0,M,x);
			add(rt,0,M,0,tmp,1);
		}
		if(maxx[rt]>x){
			int tmp=queryr(rt,0,M,x);
			add(rt,0,M,tmp,M,-1);
		}
		m=read();
		for(int k=1;k<=m;k++){
			x=(read()+las)%mod;
			las=query(rt,0,M,x);
			cout<<las<<'\n';
		}
	}
	return 0;
}