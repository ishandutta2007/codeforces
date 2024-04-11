#include <bits/stdc++.h>

using namespace std;

const int N = 60 , M = 110 , T = 2e4 + 10;

namespace FFT {
	struct cp {
		double x , y;
		cp(double x = 0.0 , double y = 0.0) : x(x) , y(y) {}
	};
	cp operator + (cp A , cp B) {return cp(A.x + B.x , A.y + B.y);}
	cp operator - (cp A , cp B) {return cp(A.x - B.x , A.y - B.y);}
	cp operator * (cp A , cp B) {return cp(A.x * B.x - A.y * B.y , A.x * B.y + A.y * B.x);}

	const double Pi = acos(-1);
	int n , m , limit , l , r[T << 2];
	cp a[T << 2] , b[T << 2];
	
	void fft(cp *a , int type) {
		for(int i = 0; i < limit; i++)
			if(i < r[i]) swap(a[i] , a[r[i]]);
		for(int i = 1; i < limit; i <<= 1) {
			cp temp = cp(cos(Pi / i) , type * sin(Pi / i));
			for(int j = 0; j < limit; j += (i << 1)) {
				cp t = cp(1 , 0);
				for(int k = 0; k < i; k++ , t = t * temp) {
					cp tx = a[j + k] , ty = t * a[i + j + k];
					a[j + k] = tx + ty , a[i + j + k] = tx - ty;
				}
			}
		}
	}
	
	void solve() {
		limit = 1 , l = 0;
		while(limit <= n + m) limit <<= 1 , l++;
		for(int i = 0; i < limit; i++) r[i] = (r[i >> 1] >> 1) | ((i & 1) << (l - 1));
		for(int i = n + 1; i < limit; i++) a[i] = cp();
		for(int i = m + 1; i < limit; i++) b[i] = cp();
		fft(a , 1) , fft(b , 1);
		for(int i = 0; i < limit; i++) a[i] = a[i] * b[i];
		fft(a , -1);
		for(int i = 0; i <= n + m; i++) a[i].x /= limit; 
	}
};

const double inf = 1e18;
int n , m , t , x , a[M] , b[M];
double d[N][N] , c[M] , p[M][T << 1] , f[N][T << 1] , g[M][T];

void solve(int l , int r) {
	if(l == t) return;
	if(l == r) {
		for(int i = 1; i < n; i++) f[i][l] = inf;
		for(int i = 1; i <= m; i++)
			if(a[i] != n) f[a[i]][l] = min(f[a[i]][l] , g[i][l] + c[i]);
		return;
	}
	int mid = (l + r) >> 1;
	solve(mid + 1 , r);
	FFT::n = r - l - 1 , FFT::m = r - mid - 1;
	for(int i = 1; i <= m; i++)
		if(a[i] != n) {
			for(int j = 0; j <= FFT::n; j++) FFT::a[j] = FFT::cp(p[i][j + 1] , 0.0);
			for(int j = 0; j <= FFT::m; j++) FFT::b[j] = FFT::cp(f[b[i]][r - j] , 0.0);
			FFT::solve();
			for(int j = l; j <= mid; j++) g[i][j] += FFT::a[r - j - 1].x;
		}
	solve(l , mid);
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m >> t >> x;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			if(i != j) d[i][j] = inf; 
	for(int i = 1 , y; i <= m; i++) {
		cin >> a[i] >> b[i] >> y;
		c[i] = y , d[a[i]][b[i]] = y;
		for(int j = 1; j <= t; j++)
			cin >> y , p[i][j] = y / 1e5;
	}
	for(int k = 1; k <= n; k++)
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				d[i][j] = min(d[i][j] , d[i][k] + d[k][j]);
	for(int i = t + 1; i < 2 * t; i++) f[n][i] = x;
	for(int i = 1; i < n; i++)
		for(int j = t; j < t * 2; j++)
			f[i][j] = d[i][n] + x;
	solve(0 , 2 * t - 1);
	cout << fixed << setprecision(10) << f[1][0] << endl;
	return 0;
}