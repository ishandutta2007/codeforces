#include <bits/stdc++.h>
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 2e18;
const int OO = 1;
const int OOO = 1;
using namespace std;

const int B = 20;

int n;
vector<int> a;
int cnt[B] = {};

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	a.resize(n);
	for (auto &i : a) {
		cin >> i;
		for (int j = 0; j < B; j++) {
			if (i & (1 << j)) cnt[j]++;
		}
	}
	ll ans = 0;
	while (1) {
		ll x = 0;
		for (int j = 0; j < B; j++)
			if (cnt[j] > 0) {
				cnt[j]--;
				x |= (1 << j);
			}
		if (x == 0) break;
		ans += x * x;
	}
	finish(ans);
}