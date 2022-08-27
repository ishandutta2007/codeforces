#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i) 
#define R(i, j, k) for(int i = (j); i >= (k); --i) 
#define ll long long 
#define sz(a) ((int) (a).size())
#define vi vector < int > 
#define me(a, x) memset(a, x, sizeof(a)) 
using namespace std;
const int N = 1e6 + 7;
const double inf = 1e18; 
struct Mat {
	double f[3][3];
	Mat (int x = 0) {
		L(i, 0, 2) 
			L(j, 0, 2) 
				f[i][j] = i == j ? x : -inf;
	}
} ;
Mat operator * (Mat a, Mat b) {
	Mat ret(-inf); 
	L(i, 0, 2) L(j, 0, 2) L(k, 0, 2) ret.f[i][j] = max(ret.f[i][j], a.f[i][k] + b.f[k][j]);
	return ret;
}
Mat f[N];
double kl;
void add (int x, int L, int R, int p, int c) {
	if(L == R) {
		f[x] = Mat(-inf);
		f[x].f[0][1] = kl * c;
		f[x].f[1][0] = -c;
		f[x].f[2][0] = -c;
		f[x].f[1][2] = -c;
		f[x].f[2][2] = 0;
		L(i, 0, 2) L(j, 0, 2) f[x].f[i][j] += c;
		return ;
	}
	int mid = (L + R) >> 1;
	p <= mid ? add (x << 1, L, mid, p, c) : add (x << 1 | 1, mid + 1, R, p, c);
	f[x] = f[x << 1] * f[x << 1 | 1];
}
Mat query (int x, int L, int R, int l, int r) {
	if(l <= L && R <= r) return f[x];
	int mid = (L + R) >> 1;
	if(l <= mid && mid < r) return query(x << 1, L, mid, l, r) * query(x << 1 | 1, mid + 1, R, l, r);
	return l <= mid ? query(x << 1, L, mid, l, r) : query(x << 1 | 1, mid + 1, R, l, r);
}

int n, q, x, y, a[N];
int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cout.precision(12), cout << fixed;
	cin >> n >> q;
	cin >> x >> y;
	if(x > y) swap(x, y);
	kl = (double) x / y;
	L(i, 1, n) {
		cin >> a[i];
		add(1, 1, n, i, a[i]);
	}
	while(q--) {
		int op;
		cin >> op;
		if(op == 1) {
			int k, v;
			cin >> k >> v;
			a[k] = v;
			add (1, 1, n, k, v);
		} else {
			int u, v;
			cin >> u >> v;
			Mat qwq = query(1, 1, n, u, v);
			double mx = 0;
			L(i, 0, 2) if(i != 1) 
				L(j, 1, 2) 
					mx = max(mx, qwq.f[i][j]); //, cout << i << ' ' << j << " : " << qwq.f[i][j] << endl;
			cout << mx / (x + y) << '\n';
		}
	}
	return 0;
}
/*
4 3
1 2
3 1 1 3
2 1 4
1 1 1
2 1 3
*/