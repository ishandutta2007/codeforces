#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=2e5, M=1e9+7;
int n, m, k;
ll iv[mxN], f[mxN], iF[mxN], dp[2001];
ar<int, 2> a[mxN];

ll C(int x, int y) {
	return f[x]*iF[y]%M*iF[x-y]%M;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	iv[1]=f[0]=f[1]=iF[0]=iF[1]=1;
	for (int i=2; i<mxN; ++i) {
		iv[i]=M-M/i*iv[M%i]%M;
		f[i]=f[i-1]*i%M;
		iF[i]=iF[i-1]*iv[i]%M;
	}
	cin >> n >> m >> k;
	for (int i=0; i<k; ++i)
		cin >> a[i][0] >> a[i][1];
	a[k][0]=n, a[k][1]=m;
	sort(a, a+k);
	for (int i=0; i<=k; ++i) {
		--a[i][0], --a[i][1];
		dp[i]=C(a[i][0]+a[i][1], a[i][0])+696969ll*M;
		for (int j=0; j<i; ++j) {
			if (a[j][1]>a[i][1])
				continue;
			int dx=a[i][0]-a[j][0], dy=a[i][1]-a[j][1];
			dp[i]-=dp[j]*C(dx+dy, dx)%M;
		}
		dp[i]%=M;
	}
	cout << dp[k];
	return 0;
}