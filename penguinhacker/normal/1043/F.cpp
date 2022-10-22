#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=3e5, M=1e9+696969;
int n, a[mxN], cnt[mxN+1];
vector<int> fc[mxN+1];
ll f[mxN+1], iv[mxN+1], iF[mxN+1], dp[mxN+1];

ll C(int x, int y) {
	assert(0<=y&&y<=x);
	return f[x]*iF[y]%M*iF[x-y]%M;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	for (int i=1; i<=mxN; ++i)
		for (int j=i; j<=mxN; j+=i)
			fc[j].push_back(i);
	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> a[i];
		for (int j : fc[a[i]])
			++cnt[j];
	}
	f[0]=f[1]=iF[0]=iF[1]=iv[1]=1;
	for (int i=2; i<=mxN; ++i) {
		f[i]=f[i-1]*i%M;
		iv[i]=M-M/i*iv[M%i]%M;
		iF[i]=iF[i-1]*iv[i]%M;
	}
	for (int i=1; i<=7; ++i) {
		for (int j=mxN; j; --j) {
			if (cnt[j]<i) {
				dp[j]=0;
				continue;
			}
			dp[j]=C(cnt[j], i);
			for (int k=2*j; k<=mxN; k+=j)
				dp[j]=(dp[j]-dp[k]+M)%M;
		}
		if (dp[1]) {
			cout << i;
			return 0;
		}
	}
	cout << -1;
	return 0;
}