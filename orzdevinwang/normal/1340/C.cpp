#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 10007;
int fn, n, g, r, d[N], lm[N][1003], f[N];
ll dis[N][1003];
bool h[N][1003];
int main () {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> fn >> n;
	L(i, 1, n) cin >> d[i];
	cin >> g >> r;
	memset(dis, -1, sizeof(dis));
	sort(d + 1, d + n + 1);
	ll ns = 1e18;
	queue < pair < int, int > > q[N];
	dis[1][0] = 0, h[1][0] = true, lm[1][0] = 0, q[0].push (make_pair (1, 0));
	int I = 0;
	while (I <= n) {
		while (!q[I].empty()) {
			int i = q[I].front().first, x = q[I].front().second;
			q[I].pop();
			if(i < n) {
				int len = x + d[i + 1] - d[i];
				ll s = dis[i][x] + d[i + 1] - d[i];
				if(i + 1 == n && len <= g) ns = min(ns, s);
				if(len == g) s += r, len = 0;
				if(len < g && !h[i + 1][len]) 
					h[i + 1][len] = true, dis[i + 1][len] = s, lm[i + 1][len] = lm[i][x] + (len == 0), 
					q[lm[i + 1][len]].push(make_pair(i + 1, len));
			}
			if(i > 1) {
				int len = x + d[i] - d[i - 1];
				ll s = dis[i][x] + d[i] - d[i - 1];
				if(len == g) s += r, len = 0;
				if(len < g && !h[i - 1][len]) 
					h[i - 1][len] = true, dis[i - 1][len] = s, lm[i - 1][len] = lm[i][x] + (len == 0), 
					q[lm[i - 1][len]].push(make_pair(i - 1, len));
			}
		}	
		I += 1;
	}
	if(ns == 1e18) 
		cout << -1 << "\n";
	else 
		cout << ns << "\n";
	return 0;
}