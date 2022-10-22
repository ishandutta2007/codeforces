#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <cmath>
#include <set>
#include <stack>
#include <map>
#include <queue>
#include <iterator>
#include <sstream>
#include <cassert>
#include <locale>
#define int long long
#define ull unsigned long long
#define ld double
#define debug(x) cout << #x << " is " << x << endl;
using namespace std;
const int N = 21;
int fact[N];
vector <int> perm(int n, int num) {
	vector <int> ans(n);
	vector <bool> used(n);
	for (int i = 0; i < n; ++i) {
		int f = fact[n - i - 1];
		int cur = 0, cnt = 0;
		while (f * (cur + 1) <= num)
			cur++;
		num -= f * cur;
		for (int j = 0; j < n; ++j) {
			if (!used[j]) {
				if (cur == cnt) {
					ans[i] = j + 1;
					used[j] = true;
					break;
				}
				cnt++;
			}
		}
	}

	return ans;
}
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(7);
	fact[0] = 1;
	for (int i = 1; i < N; ++i)
		fact[i] = fact[i - 1] * i;
	int n, q; cin >> n >> q;
	int curn = 0;
	vector <int> pref(n + 1);
	for (int i = 1; i <= n; ++i)
		pref[i] = pref[i - 1] + i;
	while (q --> 0){
		int command;
		cin >> command;
		if (command == 1) {
			int l, r; cin >> l >> r;
			cout << pref[r] - pref[l - 1] << '\n';
		}
		else {
			int x; cin >> x;
			curn += x;
			vector <int> res = perm(min(n, 19ll), curn);

			for (int i = n - min(n, 19ll); i < n; ++i) 
				pref[i + 1] = pref[i] + n - min(n, 19ll) + res[i + min(n, 19ll) - n];
		}
	}

	return 0;
}