#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=3e5+5;
const int mod=998244353;

int power(int a,int b) {
	int ret=1;
	for (;b;b/=2) {
		if (b&1) {
			ret=1LL*ret*a%mod;
		}
		a=1LL*a*a%mod;
	}
	return ret;
}
int inv(int a) {
	if (a>=mod) {
		a%=mod;
	}
	return power(a,mod-2);
}
#define poly vector<int>
int lim,l;
vector<int>rev;
void ntt(poly &a,int type) {
	for (int i=0;i<lim;i++) {
		if (rev[i]>i) {
			swap(a[i],a[rev[i]]);
		}
	}
	for (int mid=1;mid<lim;mid*=2) {
		int Wn=power(type>0?3:inv(3),(mod-1)/mid/2);
		for (int len=mid*2,k=0;k<lim;k+=len) {
			int w=1;
			for (int i=k;i<k+mid;i++,w=1LL*w*Wn%mod) {
				int x=a[i],y=1LL*w*a[i+mid]%mod;
				a[i]=(x+y)%mod;
				a[i+mid]=(x-y+mod)%mod;
			}
		}
	}
	if (type<0) {
		int invn=inv(lim);
		for (int i=0;i<lim;i++) {
			a[i]=1LL*a[i]*invn%mod;
		}
	}
}
poly operator *(poly a,poly b) {
	if (a.empty()) a=poly({0});
	if (b.empty()) b=poly({0});
	int n=a.size(),m=b.size();
	for (lim=1,l=0;lim<=n+m;l++) lim*=2;
	a.resize(lim),b.resize(lim),rev.resize(lim);
	for (int i=0;i<lim;i++) {
		rev[i]=(rev[i>>1]>>1)|((i&1)<<(l-1));
	}
	ntt(a,1),ntt(b,1);
	for (int i=0;i<lim;i++) {
		a[i]=1LL*a[i]*b[i]%mod;
	}
	ntt(a,-1);
	a.resize(n+m-1);
	return a;
}
int fact[N],invf[N],ffact[N],pw[N];
void ysgs(int n) {
	for (int i=pw[0]=1;i<=n;i++) {
		pw[i]=pw[i-1]*2%mod;
	}
	ffact[0]=ffact[1]=1;
	for (int i=2;i<=n;i++) {
		ffact[i]=1LL*ffact[i-2]*i%mod;
	}
	for (int i=fact[0]=1;i<=n;i++) {
		fact[i]=1LL*fact[i-1]*i%mod;
	}
	invf[n]=inv(fact[n]);
	for (int i=n;i>=1;i--) {
		invf[i-1]=1LL*invf[i]*i%mod;
	}
}
int C(int n,int m) {
	if (n<m||m<0) {
		return 0;
	}
	return 1LL*fact[n]*invf[m]%mod*invf[n-m]%mod;
}
int G[N];
void work() {
	int n,ans=0;
	cin>>n;
	poly A(n+1),B(n+1);
	for (int i=0;i<=n;i++) {
		A[i]=invf[i];
		if (i%2==0) {
			B[i]=1LL*(i?ffact[i-1]:1)*invf[i]%mod;
		}
	}
	auto F=A*B;
	for (int i=0;i<=n;i++) {
		F[i]=1LL*F[i]*fact[i]%mod;
	}
	for (int i=0;i<=n;i++) {
		G[i]=0;
		if (i%4==0) {
			G[i]=1LL*(i?ffact[i/2-1]:1)*pw[i/4]%mod;
			ans=(ans+1LL*G[i]*F[n-i]%mod*C(n-i/2,i/2))%mod;
		}
	}
	cout<<ans<<"\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	ysgs(3e5); 
	int T=1;
	cin>>T;
	while (T--) {
		work();
	} 
	
	return 0;
}