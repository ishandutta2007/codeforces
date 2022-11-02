#include <bits/stdc++.h>
typedef unsigned long long u64;
const int P=1e9+7;
u64 power(u64 a, int b) {
	u64 res=1;
	for(; b; b/=2) {
		if(b&1) res=res*a%P;
		a=a*a%P;
	}
	return res;
}
int n, a[14], pp[14][14], ps[14][1<<14], f[1<<14][14];
int main() {
	scanf("%d", &n);
	for(int i=0; i<n; ++i) scanf("%d", a+i);
	for(int i=0; i<n; ++i) {
		for(int j=0; j<n; ++j) {
			if(i!=j) pp[i][j]=a[i]*power(a[i]+a[j], P-2)%P;
		}
	}
	for(int i=0; i<n; ++i) {
		ps[i][0]=1;
		for(int j=0, up=1; j<n; ++j, up*=2) {
			if(i==j) continue;
			for(int s=0; s<up; ++s)
				ps[i][up+s]=1llu*ps[i][s]*pp[i][j]%P;
		}
	}
	for(int s=0; s<(1<<n); ++s) {
		u64 in=1;
		for(int i=0; i<n; ++i) {
			if(~s>>i&1) in=in*ps[i][s]%P;
		}
		for(int i=0; i<n; ++i) {
			if(s>>i&1) f[s][i]=in;
		}
		for(int t=s; t=(t-1)&s; ) {
			u64 in2=1;
			for(int i=0; i<n; ++i) {
				if(~s>>i&1) in2=in2*ps[i][s^t]%P;
			}
			for(int i=0; i<n; ++i) {
				if(t>>i&1) f[s][i]=(f[s][i]+in2*(P-f[t][i]))%P;
			}
		}
	}
	int ans=0, *F=f[(1<<n)-1];
	for(int i=0; i<n; ++i) ans=(ans+F[i])%P;
	printf("%d\n", ans);
	return 0;
}