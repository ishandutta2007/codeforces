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

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10); srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	int n; cin >> n;
	string s; cin >> s;
	int mi = n + 1;
	int in = 0;
	int ob = 0;
	int cb = 0;
	for (int i = 0; i < n; ++i) {
		if (s[i] == ')') cb++, in--;
		else if(s[i] == '(') in++, ob++;
		mi = min(in, mi);
	}
	if (mi >= -1 && cb == ob) {
		cout << "Yes";
	} else {
		cout << "No";
	}
}