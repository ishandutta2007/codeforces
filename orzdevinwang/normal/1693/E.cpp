#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
#define me(f, x) memset(f, x, sizeof(f))
#define uint unsigned int 
using namespace std;
const int N = 1 << 20;
int n, a[N];
vi x[N]; 
int sz[N];
void add(int x, int w) {
	for (; x <= n; x += x & -x) 
		 sz[x] += w;
}
int query(int x) {
	int ret = 0;
	for(; x; x -= x & -x) 
		ret += sz[x];
	return ret;
}
int main () {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	L(i, 1, n) cin >> a[i], x[a[i]].emplace_back(i);
	ll ns = 0;
	int L = 1, R = n;
	R(i, n, 1) if(sz(x[i])) {
		int l = x[i][0], r = x[i].back();
		for(const int &u : x[i]) 
			add(u, 1); 
		int xL = L, xR = R;
		L = min(l, xR + 1), R = max(r, xL - 1);
//		cout << L << " to " << R << endl;
		ns += query(R) - query(L - 1);
	}
	cout << ns << '\n';
	return 0;
}