#include <bits/stdc++.h>
#define pb emplace_back
#define fi first
#define se second
#define int long long
using namespace std;
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int l) { uniform_int_distribution<int> uid(0, l - 1); return uid(rang); }

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10); srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	string s; cin >> s;
	int cn = 0;
	for (char c : s) {
		if ((c - '0') % 4 == 0) {
			cn += 1;
		} 
	} 
	for (int i = 1; i < s.size(); ++i) {
		if (((s[i] - '0') + 10 * (s[i - 1] - '0')) % 4 == 0) {
			cn += i;
		}
	}
	cout << cn;
}