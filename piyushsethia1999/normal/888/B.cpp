#include <bits/stdc++.h>
#define pb emplace_back
#define fi first
#define se second
using namespace std;
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int l) { uniform_int_distribution<int> uid(0, l - 1); return uid(rang); }

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10); srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	int n; cin >> n;
	string s; cin >> s;
	int r = 0;
	int c = 0;
	for (int i = 0; i < n; ++i) {
		switch(s[i]) {
			case 'U':r++;
				break;
			case 'D':r--;
				break;
			case 'L':c++;
				break;
			case 'R':c--;
				break;
		} 
	}
	cout << n - abs(r) - abs(c);
}