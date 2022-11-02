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
//#pragma GCC optimize(3)
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
const int N=2e5+5;
int n,q,op,l,r,x,f[N],maxx[N];
#define mid ((l+r)>>1)
#define ls (u<<1)
#define rs (u<<1|1)
int summ[N*4];
int find(int x){
	if(f[x]!=x)return f[x]=find(f[x]);
	else return x;
}
void build(int u,int l,int r){
	summ[u]=r-l+1;
	if(l==r)return ;
	build(ls,l,mid);
	build(rs,mid+1,r);
}
int tot,ch[N*20][2],rt[N],bj[N*20];
void add(int &u,int l,int r,int x){
	if(!u)u=++tot;
	if(l==r){
		bj[u]=1;return ;
	}
	if(x<=mid)add(ch[u][0],l,mid,x);
	else add(ch[u][1],mid+1,r,x);
	bj[u]=bj[ch[u][0]]|bj[ch[u][1]];
}
int merge(int x,int y,int l,int r){
	if(!x || !y)return x|y;
	if(l==r){
		bj[x]|=bj[y];return x;
	}
	ch[x][0]=merge(ch[x][0],ch[y][0],l,mid);
	ch[x][1]=merge(ch[x][1],ch[y][1],mid+1,r);
	bj[x]|=bj[y];
	return x;
}
int query(int u,int l,int r,int x){
	if(x<l || x>r)return 1;
	if(l==r){
		return summ[u];
	}
	if(x<=mid)return query(ls,l,mid,x);
	else return query(rs,mid+1,r,x);
}
void merge(int x,int y){
	x=find(x);
	y=find(y);
	rt[x]=merge(rt[x],rt[y],1,n);
	f[y]=x;maxx[x]=max(maxx[x],maxx[y]);
}
void add(int u,int l,int r,int L,int R){
	if(!summ[u])return ;
	if(l==r){
		if(!query(1,1,n,l-1)){
			merge(l-1,l);
		}
		if(!query(1,1,n,l+1)){
			merge(l,l+1);
		}
		summ[u]=0;
		return ;
	}
	if(L<=l && R>=r){
		add(ls,l,mid,L,R);
		add(rs,mid+1,r,L,R);
		summ[u]=summ[ls]+summ[rs];
		return ;
	}
	if(L<=mid)add(ls,l,mid,L,R);
	if(R>mid)add(rs,mid+1,r,L,R);
	summ[u]=summ[ls]+summ[rs];
}
int ask(int u,int l,int r,int L,int R){
	if(!u)return 0;
	if(L<=l && R>=r){
		return bj[u];
	}
	if(R<=mid)return ask(ch[u][0],l,mid,L,R);
	if(L>mid)return ask(ch[u][1],mid+1,r,L,R);
	return max(ask(ch[u][0],l,mid,L,R),ask(ch[u][1],mid+1,r,L,R));
}
int check(int x,int L,int R){
	if(L<0 || R>n || L>R)return 0;
	if(ask(rt[x],1,n,L,R)==0)return 0;
	else return 1;
}
int main(){
	#ifdef newbiewzs
		freopen("data.in","r",stdin);
	#else
	#endif
	n=read();q=read();
	build(1,1,n);
	for(int i=1;i<=n;i++)f[i]=maxx[i]=i;
	for(int i=1;i<=q;i++){
		op=read();
		if(op==0){
			l=read();r=read();x=read();
			if(x==0){
				add(1,1,n,l,r);
			}
			else add(rt[find(l)],1,n,r);
		}
		else{
			x=read();
			if(query(1,1,n,x)==0){
				puts("NO");
			}
			else {
				bool flag=0;
				if(check(x,x,x)){
					flag=1;
				}
				if(x<n && !query(1,1,n,x+1)){
					int tmp=maxx[find(x+1)];
					if(check(x,x+1,tmp))flag=1;
				}
				if(x>1 && !query(1,1,n,x-1)){
					if(check(find(x-1),x,x))flag=1;
					if(x<n && !query(1,1,n,x+1)){
						int tmp=maxx[find(x+1)];
						if(check(find(x-1),x+1,tmp))flag=1;
					}
				}
				if(flag)puts("YES");
				else puts("N/A");
			}
		}
	}
	return 0;
}