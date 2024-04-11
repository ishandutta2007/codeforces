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
#define dbgg(x,y) cerr<<"In Line "<< __LINE__<<" the "<<#x<<" = "<<x<<" ; the "<<#y<<" = "<<y<<'\n';
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
namespace CFConTest{
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
using namespace CFConTest;
const int N=1e5+5;
const int g=3;
const int ig=332748118;
int n,m,a[N],p[N],s[N],ans[N<<2];
int pw[N],ipw[N];
int bit,len,r[N<<4];
void prework(int x){
	len=1;bit=0;
	while(len<=x)len*=2,bit++;
	for(int i=0;i<len;i++){
		r[i]=((r[i>>1]>>1)|((i&1)<<(bit-1)));
	}
}
void ntt(vi &a,int op){
	for(int i=0;i<len;i++){
		if(r[i]>i)swap(a[r[i]],a[i]);
	}
	for(int i=1;i<len;i*=2){
		const int w=(op==1)?ksm(g,(mod-1)/(i*2)):ksm(ig,(mod-1)/(i*2));
		for(int k=0;k<len;k+=i*2){
			for(int j=0,h=1;j<i;j++,h=1ll*h*w%mod){
				const int x=a[k+j];
				const int y=1ll*h*a[i+k+j]%mod;
				a[k+j]=add(x,y);
				a[i+k+j]=del(x,y);
			}
		}
	}
	if(op==-1){
		const int inv=ksm(len,mod-2);
		for(int i=0;i<len;i++)a[i]=1ll*a[i]*inv%mod;
	}
}
vi mul(vi a,vi b){
	prework(a.size()+b.size()+1);
	a.resize(len);
	b.resize(len);
	ntt(a,1);
	ntt(b,1);
	for(int i=0;i<len;i++)a[i]=1ll*a[i]*b[i]%mod;
	ntt(a,-1);
	return a;
}
#define mid ((l+r)>>1)
inline int calc(int x){
	if(x<0)return 0;
	if(x>n)return n;
	return x;
}
void solve(int l,int r){
	if(l==r)return ;
//	dbgg(l,r);
	
	solve(l,mid);
	solve(mid+1,r);
	vi x,y;
	
	for(int i=l;i<=mid;i++)x.pb(pw[s[calc(i)]]);
	for(int i=mid+1;i<=r;i++)y.pb(ipw[s[calc(i)]]);
	vi tmp=mul(x,y);
	for(int i=0;i<tmp.size();i++){
		if(l+mid+1+i<0 || l+mid+1+i>2*n)continue;
		ans[l+mid+1+i]=add(ans[l+mid+1+i],tmp[i]);
	}
}
int main(){
	#ifdef newbiewzs
		freopen("data.in","r",stdin);
	#else
	#endif
	/*vi a,b;
	a.pb(3);a.pb(4);a.pb(10);a.pb(114514);
	b.pb(2);b.pb(5);b.pb(1919810);
	vi c=mul(a,b);
	for(int i=0;i<c.size();i++){
		cout<<c[i]<<" ";
	}
	return 0;*/
	n=read();m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=m;i++)p[i]=read(),s[p[i]]++;
	for(int i=1;i<=n;i++)s[i]+=s[i-1];
	pw[0]=ipw[0]=1;
	for(int i=1;i<=n;i++)pw[i]=2ll*pw[i-1]%mod;
	ipw[n]=ksm(pw[n],mod-2);
	for(int i=n-1;i>=1;i--)ipw[i]=1ll*ipw[i+1]*2%mod;
	solve(-n,2*n);
	int summ=0;
	for(int i=1;i<=n;i++){
	//	cout<<ans[i*2-1]<<" ";
	//	dbg(ans[i*2-1]);
		summ=add(summ,1ll*del(1ll*pw[m]*ans[i*2-1]%mod,min(2*n-i+1,i+n))*a[i]%mod);
	}
//	cout<<endl;
	int base=del(pw[m],1);
	summ=1ll*summ*ksm(base,mod-2)%mod;
	cout<<summ;
	return 0;
}