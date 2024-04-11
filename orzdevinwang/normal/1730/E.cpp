#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define sz(a) ((int) (a).size())
#define vi vector < int > 
#define me(a, x) memset(a, x, sizeof(a))
#define ull unsigned long long
#define ld __float128
using namespace std;
const int N = 1e6 + 7, V = 1e6; 
int n, a[N], l[N], r[N], stk[N], tp;

struct dsu {
int f[N];
inline int find(int x) {
	return f[x] == x ? x : f[x] = find(f[x]);
} 
} x, y;
vi vc[N];

void Main() {
	cin >> n;
	L(i, 1, n) {
		cin >> a[i];
		r[i] = n + 1;
		vc[a[i]].emplace_back(i);
	}
	L(i, 0, n + 1) x.f[i] = y.f[i] = i;
	tp = 0;
	L(i, 1, n) {
		while(tp && a[stk[tp]] < a[i]) r[stk[tp]] = i, --tp;
		l[i] = stk[tp], stk[++tp] = i;
	}
	ll ns = 0;
	R(i, V, 1) if(sz(vc[i])) {
		for(int j = i * 2; j <= V; j += i) 
			if(sz(vc[j])) for(const int &u : vc[j])
				ns -= (ll) (u - max(x.find(u), l[u])) * (min(y.find(u), r[u]) - u);
		for(const int &u : vc[i]) 
			x.f[u] = u - 1, y.f[u] = u + 1;
		for(int j = i; j <= V; j += i) 
			if(sz(vc[j])) for(const int &u : vc[j]) 
				ns += (ll) (u - max(x.find(u), l[u])) * (min(y.find(u), r[u]) - u);
	}
	cout << ns << '\n'; 
	L(i, 1, n) {
		vc[a[i]].clear();
	}
}
int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t--) Main();
	return 0;
}