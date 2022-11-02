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
const int N=1e5+5;
int m,n,a[N];
int LL[N],RR[N];
bool check(int u){
	int r=0;
	for(int i=1;i<=n;i++){
		if(r>a[i])return 0;
		r=r+u;
		r=max(r,a[i]);
//		r=r+max(u,a[i]-u);
	}
	if(r>m)return 0;
	return 1;
}
bool solve(int l,int r){
	int L=0,R=0;a[n+1]=1e9+5;
	for(int i=1;i<=n;i++){
		L=L+l;
		if(L>a[i+1])return 0;
		R=R+r;
		if(R<a[i])return 0;
		L=max(L,a[i]);
		R=min(R,a[i+1]);
		if(L>R)return 0;
	}
	if(R<m || L>m)return 0;
	return 1;
}
int sx[N],sy[N],top;
void out(int l,int r){
	int L=0,R=0;a[n+1]=1e9+5;
	for(int i=1;i<=n;i++){
		L=L+l;
		R=R+r;
		L=max(L,a[i]);
		R=min(R,a[i+1]);
		LL[i]=L;
		RR[i]=R;
	}
	sx[++top]=m;
	for(int i=n;i>=1;i--){
		LL[i-1]=max(LL[i-1],sx[top]-r);
		RR[i-1]=min(RR[i-1],sx[top]-l);
		sx[++top]=RR[i-1];
		
	}
	for(int i=top;i>1;i--){
		cout<<sx[i]<<" "<<sx[i-1]<<'\n';
	}
}
signed main(){
	#ifdef newbiewzs
		freopen("data.in","r",stdin);
	#else
	#endif
	m=read();n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	int l=1,r=1e9,jl=-1;
	#define mid ((l+r)>>1)
	while(l<=r){
		if(check(mid))jl=mid,l=mid+1;
		else r=mid-1;
	}
	l=jl,r=1e9;
	int pos;
	while(l<=r){
		if(solve(jl,mid))pos=mid,r=mid-1;
		else l=mid+1;
	}
	out(jl,pos);
//	cout<<pos-jl;
    #ifdef newbiewzs
		cerr<<'\n'<<"Time:"<<clock()<<" ms"<<'\n';
	#endif
	return 0;
}