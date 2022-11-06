#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define int long long
#ifndef print
#define print(...)
#endif
using namespace std;
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int l) { uniform_int_distribution<int> uid(0, l - 1); return uid(rang); }

int lp[100005];
void pre() {
	lp[1] = 1;
	for (int i = 0; i <= 100000; ++i) 
		lp[i] = i;
	for (int i = 2; i <= 100000; ++i) {
		if (lp[i] == i)
			for (int j = i * 2; j <= 100000; j += i)
				lp[j] = min(lp[j], i);
	}
}
int a[200000];
int b[200000];

std::map<int, int> mp;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10); srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	pre();
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; ++i) 
		cin >> a[i];
	int to = 0;
	for (int i = 0; i < n; ++i) {
		int aa = 1;
		b[i] = 1;
		while (a[i] != 1) {
			int ll = lp[a[i]];
			int cn = 0;
			while (lp[a[i]] == ll) {
				a[i] /= ll;
				cn++;
			}
			cn %= k;
			// print(ll, cn);
			for (int j = 0; j < cn; ++j) 
				aa *= ll;
			if (cn) {
				cn = k - cn;
				for (int j = 0; j < cn && b[i] <= 100000; ++j) {
					b[i] *= ll;
				}
			}
		}
		a[i] = aa;
		// print(a[i]);
		to += mp[b[i]];
		mp[a[i]]++;
	}
	cout << to;
}