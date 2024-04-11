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
#define int long long
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
namespace IO_BUFF{
	const int BS=(1<<24)+5;char Buffer[BS],*HD,*TL;
	inline int gc(){
	    if(HD==TL) TL=(HD=Buffer)+fread(Buffer,1,BS,stdin);
	    return (HD==TL)?EOF:*HD++;
	}
	inline int read(){
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
}using namespace IO_BUFF;
const int N=1e5+5;
int n,m,q,op,x,y;
int a[N],b[N],sa[N],sb[N],st[N],top;
#define ls (u<<1)
#define rs (u<<1|1)
#define mid ((l+r)>>1)
int summ[N*4],tag[N*4],maxx[N*4],ans[N*4];
void update(int u,int l,int r){
	summ[u]=summ[ls]+summ[rs];
	maxx[u]=maxx[rs];
	ans[u]=ans[ls]+ans[rs]+summ[ls]*(r-mid);
}
void build(int u,int l,int r){
	if(l==r){
		summ[u]=maxx[u]=ans[u]=sb[l];
		return ;
	}
	build(ls,l,mid);
	build(rs,mid+1,r);
	update(u,l,r);
}
void pushdown(int u,int l,int r){
	if(tag[u]){
		summ[ls]+=tag[u]*(mid-l+1);
		summ[rs]+=tag[u]*(r-mid);
		ans[ls]+=((mid-l+1)*(mid-l+2)/2)*tag[u];
		ans[rs]+=((r-mid)*(r-mid+1)/2)*tag[u];
		
		maxx[ls]+=tag[u];
		maxx[rs]+=tag[u];
		tag[ls]+=tag[u];
		tag[rs]+=tag[u];
		tag[u]=0;
	}
}
void add(int u,int l,int r,int L,int R,int k){
	if(L<=l && R>=r){
		tag[u]+=k;maxx[u]+=k;
		summ[u]+=(r-l+1)*k;
		ans[u]+=((r-l+1)*(r-l+2)/2)*k;
		return ;
	}
	pushdown(u,l,r);
	if(L<=mid)add(ls,l,mid,L,R,k);
	if(R>mid)add(rs,mid+1,r,L,R,k);
	update(u,l,r);
}
int query(int u,int l,int r,int L,int R){
	if(L<=l && R>=r)return summ[u];
	pushdown(u,l,r);
	if(R<=mid)return query(ls,l,mid,L,R);
	if(L>mid)return query(rs,mid+1,r,L,R);
	return query(ls,l,mid,L,R)+query(rs,mid+1,r,L,R);
}
int query(int u,int l,int r,int x){
	if(l==r){
		return l-(summ[u]>x);
	}
	pushdown(u,l,r);
	if(maxx[ls]<x)return query(rs,mid+1,r,x);
	else return query(ls,l,mid,x);
}
signed main(){
	#ifdef newbiewzs
	#else
	#endif
	n=read();m=read();q=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=m;i++)b[i]=read();
	for(int i=1;i<m;i++)sb[i]=b[i+1]-b[i];
	build(1,1,m-1);
	for(int T=1;T<=q;T++){
		op=read();x=read();y=read();
		if(op==1){
			for(int i=n-x+1,tmp=0;i<=n;i++){
				tmp++;a[i]=(a[i]+y*tmp);
			}	
		}
		else{
			if(m==x){
				b[1]+=y;
			}
			add(1,1,m-1,max(1ll,m-x),m-1,y);
		}
		for(int i=1;i<n;i++)sa[i]=a[i+1]-a[i];
		int tmp=0;
		for(int i=1;i<n;i++){
			int pos=query(1,1,m-1,sa[i]);
			if(pos){
				tmp=tmp+query(1,1,m-1,1,pos);
			}
			tmp=tmp+(n+m-2-(i-1)-(pos))*sa[i];
		}
		print(tmp+(n+m-1)*(a[1]+b[1])+ans[1]);
	}
	Flush();
	return 0;
}