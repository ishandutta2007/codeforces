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
int n,m,a[4][N],L[N],R[N],x[N],f[N];
int sa[N],sb[N],sc[N];
vi v[N];
int suf[N],pre[N];
#define ls (u<<1)
#define rs (u<<1|1)
#define mid ((l+r)>>1)
int maxx[N*4],mixx[N*4];
void add(int u,int l,int r,int x,int k,int id){
	if(l==r){
		if(id==1)maxx[u]=k;
		else mixx[u]=k;
		return ;
	}
	if(x<=mid)add(ls,l,mid,x,k,id);
	else add(rs,mid+1,r,x,k,id);
	maxx[u]=max(maxx[ls],maxx[rs]);
	mixx[u]=max(mixx[ls],mixx[rs]);
}
int query(int u,int l,int r,int L,int R,int id){
	if(L>R)return -1e15;
	if(L<=l && R>=r)return id==1?maxx[u]:mixx[u];
	if(R<=mid)return query(ls,l,mid,L,R,id);
	if(L>mid)return query(rs,mid+1,r,L,R,id);
	return max(query(ls,l,mid,L,R,id),query(rs,mid+1,r,L,R,id));
}
int ans=-1e15;
void solve(int l,int r,vi tmp,int val){
	vi Ls,Rs;
	if(l==1 && r==3){
		new char;
	}
	for(auto k:tmp){
		if(L[k]<=l && R[k]>=r){
			val=max(val,-x[k]);
			continue;
		}
		if(L[k]<=mid)Ls.pb(k);
		if(R[k]>mid)Rs.pb(k);
	}
	if(l==r){
		ans=max(ans,f[l]+sc[l]);
		ans=max(ans,val+sa[l]+a[2][l]+sc[l]);
		if(ans==-8){
			new char;
		}
		return ;
	}
	for(int i=mid+1;i>=l;i--)suf[i]=-1e15;
	if(l==1 && r==3){
		new char;
	}
	
	suf[mid+1]=max(suf[mid+1],f[mid]-sb[mid]);
	for(int i=mid;i>=l;i--){
		suf[i]=max(suf[i],suf[i+1]);
		suf[i]=max(suf[i],sa[i]-sb[i-1]);
		suf[i]=max(suf[i],f[i-1]-sb[i-1]);
	}
//	int pre=-1e15;
	pre[mid]=-1e15;
	for(int i=mid+1;i<=r;i++){
		pre[i]=max(pre[i-1],sb[i]+sc[i]);
/*		pre=max(pre,sb[i]+sc[i]);
		for(auto k:v[i]){
			if(L[k]>mid+1)continue;
			ans=max(ans,pre+suf[max(l,L[k])]-x[k]);
			if(ans==-19){
				new char;
			}
		}*/
	}
	if(l==1 && r==2){
		new char;
	}
	for(auto k:Rs){
		if(L[k]>mid+1)continue;
		ans=max(ans,pre[min(R[k],r)]+suf[max(l,L[k])]-x[k]);
		if(ans==-8){
			new char;
		}
	}
	ans=max(ans,pre[r]+suf[l]+val);
	if(ans==-8){
		new char;
	}
	solve(l,mid,Ls,val);
	solve(mid+1,r,Rs,val);
}
signed main(){
	#ifdef newbiewzs
		freopen("data.in","r",stdin);
	#else
	#endif
	n=read();m=read();
	for(int i=1;i<=3;i++){
		for(int k=1;k<=n;k++){
			a[i][k]=read();
		}
	}
	for(int i=1;i<=m;i++){
		L[i]=read();R[i]=read();x[i]=read();
		v[R[i]].pb(i);
	}
	for(int i=1;i<=n;i++){
		sa[i]=sa[i-1]+a[1][i];
		sb[i]=sb[i-1]+a[2][i];
	}
	for(int i=n;i>=1;i--){
		sc[i]=sc[i+1]+a[3][i];
	}
	memset(maxx,-10,sizeof(maxx));
	memset(f,-10,sizeof(f));
	for(int i=1;i<=n;i++){
		add(1,1,n,i,sa[i]-sb[i-1],0);
		for(auto k:v[i]){
			f[i]=max(f[i],query(1,1,n,max(L[k]-1,1ll),i-1,1)+sb[i]-x[k]);
			f[i]=max(f[i],query(1,1,n,L[k],i,0)+sb[i]-x[k]);
		}
		add(1,1,n,i,f[i]-sb[i],1);
	}
	vi TMP;
	for(int i=1;i<=m;i++)TMP.pb(i);
	solve(1,n,TMP,-1e15);
	cout<<ans;
	return 0;
}