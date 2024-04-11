#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int> 
using namespace std;
const int N = 3e5 + 7;
int n, k;
ll g[N], s, t, ns = 1e10;
struct node {
	ll c, v;
} p[N];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> k >> s >> t;
	L(i, 1, n) cin >> p[i].c >> p[i].v;
	L(i, 1, k) cin >> g[i];
	++k, g[k] = s;
	sort(p + 1, p + n + 1, [&] (node a, node b) {
		return a.v < b.v;
	});
	sort(g + 1, g + k + 1);
	R(i, k, 1) g[i] -= g[i - 1];
	sort(g + 1, g + k + 1);	
	
	int now = 0;
	ll ol = 0;
	L(i, 1, n) {
		while(now < k && p[i].v >= g[now + 1] * 2) ++now, ol += g[now];
		if(p[i].v >= g[k] && 2 * (s - ol) - p[i].v * (k - now) + s <= t) ns = min(ns, p[i].c);
	}
	if(ns > 5e9) cout << "-1\n";
	else cout << ns << "\n";
	return 0;
}