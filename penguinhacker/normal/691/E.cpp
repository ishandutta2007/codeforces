#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=100, M=1e9+7;
int n;
ll k, a[mxN];

struct Mat {
	int n, m;
	vector<vector<int>> mat;
	Mat(int _n, int _m) : n(_n), m(_m) {
		mat.assign(n, vector<int>(m));
	}
	const vector<int>& operator[](int i) const {
		return mat[i];
	}
	vector<int>& operator[](int i) {
		return mat[i];
	}
	Mat operator*(const Mat& o) const {
		assert(m==o.n);
		Mat r(n, o.m);
		for (int i=0; i<n; ++i)
			for (int j=0; j<m; ++j)
				for (int k=0; k<o.m; ++k)
					r[i][k]=(r[i][k]+(ll)mat[i][j]*o[j][k])%M;
		return r;
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k, --k;
	Mat s(1, n), t(n, n);
	for (int i=0; i<n; ++i) {
		cin >> a[i];
		s[0][i]=1;
	}
	for (int i=0; i<n; ++i)
		for (int j=0; j<n; ++j)
			if (__builtin_popcountll(a[i]^a[j])%3==0)
				t[i][j]=1;
	while(k) {
		if (k&1)
			s=s*t;
		t=t*t;
		k/=2;
	}
	ll ans=0;
	for (int i=0; i<n; ++i)
		ans+=s[0][i];
	cout << ans%M;
	return 0;
}