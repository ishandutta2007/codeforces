#include<bits/stdc++.h>
#define ll long long
#define poly vector<int>
using namespace std;
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
int n,k,m; 

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>n>>k>>m;
	if (m>k+k) {
		cout<<"0\n";
		return 0;
	}
	poly f(k+1);
	f[k]=1;
	for (int t=1;t<=n;t++) {
		poly g(k+1);
		for (int i=f.size()-1,sum=0;i>=0;i--) {
			if (i<=k) {
				g[i]=(sum+1LL*f[i]*(k-i+1))%mod;
			}
			sum=(sum+f[i])%mod;
		}
		f=g*g;
	}
	cout<<f[m]<<"\n";
	
	return 0;
}