#include <bits/stdc++.h>
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 4e18;
const int OO = 1;
const int OOO = 1;
using namespace std;

const int M = 1 << 18;

int n;
vector<int> b, a;

int ans[M];
int cnt[M];

void calc(int b) {
	int B = 2 * b;
	for (int i = 0; i < B; i++)
		cnt[i] = 0;
	for (auto &i : a)
		cnt[i % B]++;
	int l = b, r = B - 1, s = 0;
	for (int i = l; i <= r; i++)
		s += cnt[i];
	for (int add = 0; add < M; add++) {
		if (s) ans[add]++;
		s -= cnt[r];
		l = (l - 1 + B) % B;
		r = (r - 1 + B) % B;
		s += cnt[l];
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	b.resize(n);
	for (auto &i : b) cin >> i;
	b.push_back(0);
	n++;
	sort(b.begin(), b.end());
	a = b;
	for (auto &i : a) i -= b[0];
	for (int b = 1; b < M; b <<= 1) calc(b);
	int at = 0;
	for (int i = 1; i < M; i++)
		if (ans[i] < ans[at]) at = i;
	for (auto &i : a) i += at;

	vector<int> ans;
	for (int b = 1; b < M; b <<= 1) {
		bool found = false;
		for (auto &i : a)
			if (i & b) found = true;
		if (found) ans.push_back(b);
	}
	int need = at - b[0];
	for (auto &i : ans) {
		if (need & i) {
			need ^= i;
			i = -i;
		}
	}
	cout << ans.size() << '\n';
	for (const auto &i : ans) cout << i << " "; cout << '\n';
}