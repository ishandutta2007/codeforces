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
const int N=4e5+5;
const int M=4e5+1;
int n,pos[N];
struct node{
	int a,b,val;
}a[N];
int cmp(node x,node y){
	return x.a<y.a;
}
#define mid ((l+r)>>1)
#define ls (u<<1)
#define rs (u<<1|1)
struct SoKel{
	int minn[N*4],tag[N*4],ad[N*4];
	void build(int u,int l,int r){
		minn[u]=1e9+7;
		if(l==r){
			return ;
		}
		build(ls,l,mid);
		build(rs,mid+1,r);
	}
	void update(int u){
		minn[u]=min(minn[ls],minn[rs]);
	}
	void pushdown(int u){
		if(tag[u]){
			minn[ls]=minn[rs]=1e9+7;
			ad[ls]=ad[rs]=0;
			tag[ls]=tag[rs]=1;
			tag[u]=0;
		}
		if(ad[u]){
			minn[ls]+=ad[u];
			minn[rs]+=ad[u];
			ad[ls]+=ad[u];
			ad[rs]+=ad[u];
			ad[u]=0;
		}
	}
	int query(int u,int l,int r,int L,int R){
		if(L<=l && R>=r){
			return minn[u];
		}
		pushdown(u);
		int tmp=1e9+7;
		if(L<=mid)tmp=min(tmp,query(ls,l,mid,L,R));
		if(R>mid)tmp=min(tmp,query(rs,mid+1,r,L,R));
		update(u);
		return tmp;
	}
	void clear(){
		ad[1]=0;tag[1]=1;minn[1]=1e9+7;
	}
	void add(int u,int l,int r,int x,int k){
		if(l==r){
			minn[u]=min(minn[u],k);
			return ;
		}
		pushdown(u);
		if(x<=mid)add(ls,l,mid,x,k);
		else add(rs,mid+1,r,x,k);
		update(u);
	}
	void add(int x){
		ad[1]+=x;
	}
}f,g;
int main(){
	#ifdef newbiewzs
		freopen("data.in","r",stdin);
	#else
	#endif
	n=read();
	for(int i=1;i<=n;i++){
		a[i].a=read();a[i].b=read();
		if(a[i].a>a[i].b)swap(a[i].a,a[i].b),a[i].val=1;
		if(a[i].a<=n && a[i].b<=n){
			puts("-1");return 0;
		}
	}
	sort(a+1,a+n+1,cmp);
	f.build(1,1,M);
	g.build(1,1,M);
	f.add(1,1,M,M,a[1].val);
	g.add(1,1,M,M,a[1].val^1);
	for(int i=1;i<n;i++){
		int ta=f.query(1,1,M,a[i+1].b,M)+(a[i+1].val^1);
		int tb=g.query(1,1,M,a[i+1].b,M)+(a[i+1].val);
		if(a[i+1].b<a[i].b){
			f.add(a[i+1].val);
		}
		else f.clear();
		if(a[i+1].b<a[i].b){
			g.add(a[i+1].val^1);
		}
		else g.clear();
		g.add(1,1,M,a[i].b,ta);
		f.add(1,1,M,a[i].b,tb);
	}
	int ans=min(f.minn[1],g.minn[1]);
	if(ans>1e9){
		cout<<"-1";
	}
	else{
		cout<<ans;
	}
	return 0;
}
/*
 
  
*/