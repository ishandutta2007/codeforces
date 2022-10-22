#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, sx, sy, dx, dy, M;
ll m;

int nr(ll x) { // normalize
	x%=n;
	if (x<0)
		x+=n;
	return x;
}

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

void dbg(Mat a) {
	int n=a.n, m=a.m;
	for (int i=0; i<n; ++i) {
		for (int j : a[i])
			cout << j << " ";
		cout << endl;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> sx >> sy >> dx >> dy >> m, M=n;
	Mat a(1, 6), t(6, 6);
	a[0]={sx, sy, nr(dx), nr(dy), 0, 1};
	for (int i=0; i<6; ++i)
		t[i][i]=1;
	t[2][0]=t[3][1]=1; // dx->x, dy->y
	t[0][2]=t[0][3]=t[1][2]=t[1][3]=1; // x+y->dx, dy
	++t[0][0], ++t[0][1], ++t[1][0], ++t[1][1];
	t[4][0]=t[4][1]=t[4][2]=t[4][3]=1; // incremented bush->dx, dy
	t[5][4]=1; // add number of seconds to increment
	for (; m; m>>=1, t=t*t)
		if (m&1)
			a=a*t;
	cout << (a[0][0]?a[0][0]:n) << " " << (a[0][1]?a[0][1]:n);
	return 0;
}