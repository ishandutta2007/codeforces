// xtqqwq
#include<bits/stdc++.h>
#pragma GCC optimize("Ofast","-funroll-loops")
#pragma GCC target("sse4.1","sse4.2","ssse3","sse3","sse2","sse","avx2","avx","popcnt","tune=native")

#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef long double ld;

template <typename T> bool chkmin(T &x,T y){return x>y?x=y,1:0;}
template <typename T> bool chkmax(T &x,T y){return x<y?x=y,1:0;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int cys=998244353;
int n,m;
int A[100005],B[100005],p[100005],a[100005],ipw2[100005];

ll mod(ll x){return x>=cys?x-cys:x;}

ll qpow(ll x,ll p){
	ll ret=1;
	for(;p;p>>=1,x=x*x%cys) if(p&1) ret=ret*x%cys;
	return ret;
}

int main(){
//	n=100000;
//	mt19937 mrand(34);
//	for(int i=1;i<=n;i++) a[i]=mrand()%cys;
//	for(int i=1;i<=n;i++) p[i]=mrand()&1,m+=p[i];
	n=readint(); m=readint();
	for(int i=1;i<=n;i++) a[i]=readint();
	for(int i=1;i<=m;i++) p[readint()]=1;
	ipw2[0]=1;
	for(int i=1;i<=n;i++) ipw2[i]=1ll*ipw2[i-1]*((cys+1)/2)%cys;
	int cnt1=0,cnt2=0;
	for(int i=1;i<=n;i++) if(p[i]) A[i]++,cnt1++;
	for(int i=1;i<=n;i++) A[i]+=A[i-1];
	ll ans=0;
	for(int i=1;i<=n;i++){
		//j -> (j+i)%k
		A[i-1]=cnt1;
		//j -> (j-i)%k
		B[n-i]=-cnt2;
		if(p[i-1]) B[n-i]--,cnt2++;
		ll sum=0;
		if(i<n-i){
			for(int j=0;j<i;j++) sum+=ipw2[A[j+i]+B[n+j-i]];
			for(int j=i;j<n-i;j++) sum+=ipw2[A[j+i]+B[j-i]];
			for(int j=n-i;j<n;j++) sum+=ipw2[A[j+i-n]+B[j-i]];
		}
		else{
			for(int j=0;j<n-i;j++) sum+=ipw2[A[j+i]+B[n+j-i]];
			for(int j=n-i;j<i;j++) sum+=ipw2[A[j+i-n]+B[n+j-i]];
			for(int j=i;j<n;j++) sum+=ipw2[A[j+i-n]+B[j-i]];
		}
		ans=(ans+sum%cys*a[i])%cys;
	}
	ll pw=1;
	for(int i=1;i<=m;i++) pw=pw*2%cys;
	ans=ans*pw%cys;
	for(int i=1;i<=n;i++) ans=mod(ans+cys-1ll*a[i]*n%cys);
	ans=ans*qpow(pw-1,cys-2)%cys;
	printf("%lld\n",ans);
	return 0;
}