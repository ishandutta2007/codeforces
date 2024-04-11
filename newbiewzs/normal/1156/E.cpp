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
#include<unordered_map>
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
	inline int read(){
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
const int mod=200437;
int n,a[N],pos[N];
int b[N];
vi v[N];
struct MyHash{
	
	vector<pii> v[mod+5];
	void insert(int x,int pos){
		const int val=x%mod;
		v[val].pb(mp(x,pos));
	}
	int query(int x){
		const int val=x%mod;
		for(auto k:v[val]){
			if(k.fi==x)return k.se;
		}
		return 0;
	}
}ma;
struct RMQ
{
	#define B 17
	int wmax(const int &i,const int &j){return w[i]>w[j]?i:j;}
	int pre[N],suf[N],bl[N],f[20][N>>5],w[N],lg[N];
	unsigned state[N];
	void build()
	{
		for(int i=1;i<=n;i++)bl[i]=((i-1)>>5)+1;
		int q[40]={0};
		for(int i=1;i<=bl[n];i++)
		{
			int L=(i-1)<<5|1,R=min(n,i<<5);
			pre[L]=L;for(int j=L+1;j<=R;j++)pre[j]=wmax(pre[j-1],j);
			suf[R]=R;for(int j=R-1;j>=L;j--)suf[j]=wmax(suf[j+1],j);
			int top=0;
			state[L]=1;
			q[++top]=L;
			for(int j=L+1;j<=R;j++)
			{
				state[j]=state[j-1]^(1<<(j-L));
				while(top&&w[j]>w[q[top]])state[j]^=1<<(q[top]-L),--top;
				q[++top]=j;
			}
		}
		for(int i=2;i<=bl[n];i++)lg[i]=lg[i>>1]+1;
		for(int i=1;i<=bl[n];i++)f[0][i]=suf[(i-1)<<5|1];
		for(int i=1;(1<<i)<=bl[n];i++)	
			for(int j=1;j+(1<<i)-1<=bl[n];j++)
				f[i][j]=wmax(f[i-1][j],f[i-1][j+(1<<(i-1))]);
	}
	int query(int l,int r)
	{
		if(bl[l]==bl[r])
		{
			int L=(bl[l]-1)<<5|1;
			return l+__builtin_ctz(state[r]>>(l-L));
		}
		if(bl[l]==bl[r]-1)return wmax(suf[l],pre[r]);
		int len=lg[bl[r]-bl[l]-1];
		return wmax(wmax(pre[r],suf[l]),wmax(f[len][bl[l]+1],f[len][bl[r]-(1<<len)]));
	}
}rmq;
int calc(int x,int l,int r){
	int val=ma.query(x);
	if(!val)return 0;
	if(l>r)return 0;
	int posa=lower_bound(v[val].begin(),v[val].end(),l)-v[val].begin();
	int posb=lower_bound(v[val].begin(),v[val].end(),r+1)-v[val].begin()-1;
	return max(posb-posa+1,0);
}
ll ans;
void solve(int l,int r){
	if(l>r)return ;
	int mid=rmq.query(l,r);
	if(mid-l+1<r-mid){
		for(int k=l;k<mid;k++){
			ans=ans+calc(a[mid]-a[k],mid+1,r);
		}
	}
	else{
		for(int k=mid+1;k<=r;k++){
			ans=ans+calc(a[mid]-a[k],l,mid-1);
		}
	}
	solve(l,mid-1);
	solve(mid+1,r);
}
int main(){
	#ifdef newbiewzs
		freopen("data.in","r",stdin);
	#else
	#endif
	n=read();
	for(int i=1;i<=n;i++)a[i]=b[i]=read();
	sort(b+1,b+n+1);
	for(int i=1;i<=n;i++){
		pos[i]=lower_bound(b+1,b+n+1,a[i])-b;
		if(!ma.query(a[i]))ma.insert(a[i],pos[i]);
	}
	for(int i=1;i<=n;i++)v[pos[i]].pb(i);
	for(int i=1;i<=n;i++)rmq.w[i]=a[i];
	rmq.build();
	solve(1,n);
	cout<<ans;
    #ifdef newbiewzs
		cerr<<'\n'<<"Time:"<<clock()<<" ms"<<'\n';
	#endif
	return 0;
}