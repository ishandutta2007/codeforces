#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=1e5, M=1e9+7;
int n, x, d[mxN], cnt[101], dp[100];

struct Mat {
	int n, m;
	vector<vector<int>> a;
	Mat() {}
	Mat(int n, int m) : n(n), m(m) {a.assign(n, vector<int>(m));}
	vector<int>& operator[](int i) {return a[i];}
	const vector<int>& operator[](int i) const {return a[i];}
	Mat operator*(const Mat& b) const {
		assert(m==b.n); Mat r(n, b.m);
		for (int i=0; i<n; ++i) for (int j=0; j<m; ++j) for (int k=0; k<b.m; ++k) r[i][k]=(r[i][k]+(ll)a[i][j]*b[j][k])%M;
		return r;
	};
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> x;
	for (int i=0; i<n; ++i)
		cin >> d[i], ++cnt[d[i]];
	dp[0]=1;
	for (int i=1; i<100; ++i)
		for (int j=1; j<=i; ++j)
			dp[i]=(dp[i]+(ll)dp[i-j]*cnt[j])%M;
	if (x<100) {
		int ans=0;
		for (int i=0; i<=x; ++i)
			ans=(ans+dp[i])%M;
		cout << ans;
		return 0;
	}
	Mat a(1, 101), t(101, 101);
	for (int i=0; i<100; ++i) {
		a[0][i]=dp[i];
		a[0][100]=(a[0][100]+dp[i])%M;
		if (i)
			t[i][i-1]=1;
	}
	t[100][100]=1;
	for (int i=1; i<=100; ++i)
		t[100-i][99]=t[100-i][100]=cnt[i];
	int m=x-99;
	for (; m; m>>=1, t=t*t)
		if (m&1)
			a=a*t;
	cout << a[0][100];
	return 0;
}