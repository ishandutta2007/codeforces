#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define x fi
#define y se.fi
#define z se.se
#ifndef print
#define print(...)
#endif
#define erase1(i) s0.erase(i); s1.erase(i); s2.erase(i); s3.erase(i); s4.erase(i); s5.erase(i); s6.erase(i); s7.erase(i); 
using namespace std;
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int l) { uniform_int_distribution<int> uid(0, l - 1); return uid(rang); }

std::vector<int> pts[100005];
int vis[100005];
int n;
int dis(int i, int j) {
	int as = 0;
	for (int k = 0; k < 3; ++k) 
		as += abs(pts[i][k] - pts[j][k]);
	return as;
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10); srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	cin >> n;
	for (int i = 0; i < n; ++i) pts[i].resize(3);
	for (int i = 0; i < n; ++i) cin >> pts[i][0] >> pts[i][1] >> pts[i][2];
	int j = 0;
	for (int i = 0; i < n / 2; ++i) {
		while (vis[j])
			j++;
		vis[j] = 1;
		int k;
		int ma = 1000000000;
		int in = 0;
		for (k = j + 1; k < n; ++k)
			if (!vis[k] && ma > dis(j, k)) {
				in = k;
				ma = dis(j, k);
			}
		vis[in] = 1;
		cout << j + 1 << " " << in + 1 << "\n";
	}
}