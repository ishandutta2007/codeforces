#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=605;
const int mod=1e9+7;

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
ll A[N],B[N];
int n,K,a[N],n1,b[N],n2,iva[N],ivb[N];
int pw[N],s1[N],s2[N],c[N][N],f[N][N],g[N][N],F[N][N],G[N][N];
int work() {
	for (int i=pw[0]=1;i<=n;i++) {
		pw[i]=pw[i-1]*2%mod;
	}
	for (int i=1;i<=n1;i++) {
		iva[i]=power(a[i],mod-2);
		A[i]=1LL*a[i]*n+n1-i;
	}
	for (int i=1;i<=n2;i++) {
		ivb[i]=power(b[i],mod-2);
		B[i]=1LL*b[i]*n+n1+n2-i;
	}
	for (int i=1;i<=n1;i++) {
		for (int j=1;j<=n2;j++) {
			int p=n2+1;
			ll mn=min(A[i],B[j]);
			for (int k=n2;k>j&&mn>B[k];k--) {
				p=k;
				s1[k]=(s1[k+1]+1LL*pw[n2-k]*b[k])%mod;
				s2[k]=(s2[k+1]+pw[n2-k])%mod;
				c[i][j]=(c[i][j]+1LL*b[k]*iva[i]%mod*pw[n2-k])%mod;
			}
			for (int k=i+1,l=p;k<=n1;k++) {
				if (A[k]>mn) {
					continue;
				}
				while (l<=n2&&1LL*b[l]*b[j]>1LL*a[k]*a[i]) {
					l++;
				}
				c[i][j]=(c[i][j]+1LL*a[k]*ivb[j]%mod*pw[n1-k])%mod;
				c[i][j]=(c[i][j]+1LL*s2[l]*a[k]%mod*ivb[j]%mod*pw[n1-k])%mod;
				c[i][j]=(c[i][j]+1LL*(s1[p]-s1[l]+mod)*iva[i]%mod*pw[n1-k])%mod;
			}
		}
	}
	for (int i=f[0][0]=1;i<=n1;i++) {
		for (int j=f[i][0]=1;j<=i;j++) {
			f[i][j]=(f[i-1][j]+1LL*f[i-1][j-1]*a[i])%mod;
			F[i][j]=(f[i][j]-f[i-1][j]+mod)%mod;
		}
	}
	for (int i=g[0][0]=1;i<=n2;i++) {
		for (int j=g[i][0]=1;j<=i;j++) {
			g[i][j]=(g[i-1][j]+1LL*g[i-1][j-1]*b[i])%mod;
			G[i][j]=(g[i][j]-g[i-1][j]+mod)%mod;
		}
	}
	int ans=0;
	for (int i=1;i<=n1;i++) {
		for (int j=1;j<=n2;j++) {
//			cerr<<i<<' '<<j<<":"<<c[i][j]<<endl;
			int tot=0;
			ll mn=min(A[i],B[j]);
			for (int k=n1;k>i;k--) {
				tot+=A[k]<mn;
			}
			for (int k=n2;k>j;k--) {
				tot+=B[k]<mn;
			}
			for (int k=1;k<K;k++) {
				if (k&1) {
					ans=(ans+1LL*F[i][K-k]*G[j][k]%mod*c[i][j])%mod;
				} else {
					ans=(ans+1LL*F[i][K-k]*G[j][k]%mod*pw[tot])%mod;
				}
			}
//			cerr<<ans<<endl;
		}
	}
	for (int i=1;i<=n1;i++) {
		int tot=n1-i;
		for (int k=n2;k>=1;k--) {
			tot+=B[k]<A[i];
		}
		ans=(ans+1LL*F[i][K]*pw[tot])%mod;
	}
	if (K&1) {
		for (int i=1;i<=n2;i++) {
			for (int k=n1;k>=1;k--) {
				if (A[k]<B[i]) {
					ans=(ans+1LL*G[i][K]*pw[n2-i]%mod*ivb[i]%mod*a[k]%mod*pw[n1-k])%mod;
				}
			}
		}
	}
	if (~K&1) {
		for (int i=1;i<=n2;i++) {
			int tot=n2-i;
			for (int k=n1;k>=1;k--) {
				tot+=B[i]>A[k];
			}
			ans=(ans+1LL*G[i][K]*pw[tot])%mod;
		}
	}
//	cerr<<ans<<endl;
	reverse(a+1,a+1+n1);
	reverse(b+1,b+1+n2);
	for (int i=f[0][0]=1;i<=n1;i++) {
		for (int j=f[i][0]=1;j<=i;j++) {
			f[i][j]=(f[i-1][j]+1LL*f[i-1][j-1]*a[i])%mod;
			F[i][j]=(f[i][j]-f[i-1][j]+mod)%mod;
		}
	}
	for (int i=g[0][0]=1;i<=n2;i++) {
		for (int j=g[i][0]=1;j<=i;j++) {
			g[i][j]=(g[i-1][j]+1LL*g[i-1][j-1]*b[i])%mod;
			G[i][j]=(g[i][j]-g[i-1][j]+mod)%mod;
		}
	}
	if (K&1) {
		for (int i=1;i<=n2;i++) {
			ans=(ans-1LL*G[i][K]*pw[n2-i]%mod+mod)%mod;
		}
	}
	for (int i=1;i<=n1;i++) {
		for (int j=1;j<=n2;j++) {
			for (int k=1;k<K;k+=2) {
				ans=(ans-1LL*F[i][K-k]*G[j][k]%mod+mod)%mod;
			}
		}
	}
	return ans;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>n>>K;
	for (int i=1;i<=n;i++) {
		int x;
		cin>>x;
		if (x>0) {
			a[++n1]=x;
		} else {
			b[++n2]=-x;
		}
	}
	sort(a+1,a+1+n1,greater<int>());
	sort(b+1,b+1+n2,greater<int>());
	cout<<work()<<"\n";
	
	return 0;
}
/*
3 2
-1 -3 1



8 5
-2 -2 -3 -3 2 2 3 4

*/