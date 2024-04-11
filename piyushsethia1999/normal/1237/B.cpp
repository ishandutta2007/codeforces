#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#ifndef print
#define print(...)
#endif
using namespace std;
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int l) { uniform_int_distribution<int> uid(0, l - 1); return uid(rang); }

int a[100005];
int b[100005];
int p[100005];

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10); srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) 
		cin >> a[i + 1];
	for (int i = 0; i < n; ++i) 
		cin >> b[i + 1];
	for (int i = 0; i < n; ++i) {
		p[b[i + 1]] = i + 1;
	}
	int ma = 0;
	int cn = 0;
	for (int i = 1; i <= n; ++i) {
		if (ma >= p[a[i]])
			cn++;
		ma = max(ma, p[a[i]]); 
	}
	cout << cn;
}