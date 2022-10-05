#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
#define endl '\n'
#define fast ios::sync_with_stdio(0), cin.tie(0)
#define debug cout << "ok" << endl
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7, inf = 1e9 + 7;
const ll hs = 199;
const ldb eps = 1e-9, pi = acos(-1);
using namespace std;

struct fenwick {
	int n;
	vector<int> tree;
	fenwick() {}
	fenwick(int sz) {
		n = sz;
		tree.resize(n + 1, 0);
	}
	void add(int pos) {
		pos++;
		while (pos <= n) {
			tree[pos]++;
			pos += (pos & -pos);
		}
	}
	void sub(int pos) {
		pos++;
		while (pos <= n) {
			tree[pos]--;
			pos += (pos & -pos);
		}
	}
	int sum(int to) {
		to++;
		int rtn = 0;
		while (to) {
			rtn += tree[to];
			to -= (to & -to);
		}
		return rtn;
	}
	int sum(int l, int r) {
		l = max(l, 0);
		r = min(r, n - 1);
		if (l > r) return 0;
		return sum(r) - sum(l - 1);
	}
};

vector<pair<int, int>> simplify(vector<pair<int, int>> &a) {
	vector<pair<int, int>> b;
	sort(a.begin(), a.end());
	for (auto &i : a) {
		if (!b.size() || b.back().second < i.first) b.push_back(i);
		else b.back().second = max(b.back().second, i.second);
	}
	return b;
}

int M[256];
int n, q;
string s;
vector<int> a;

int cnt[3] = {};
fenwick f[3];

int calc() {
	int ans = 0;
	int lo, hi, mid, P[2], S[2];
	vector<pair<int, int>> aa;
	for (int i = 0; i < 3; i++) {
		int j = (i + 1) % 3;
		int k = (j + 1) % 3;
		if (cnt[j] == 0) ans += cnt[i];
		else if (cnt[k] == 0 || cnt[i] == 0) ans += 0;
		else {
			lo = 0, hi = n - 1, mid;
			while (lo < hi) {
				mid = (lo + hi) / 2;
				if (f[j].sum(0, mid) && f[k].sum(0, mid)) hi = mid;
				else lo = mid + 1;
			}
			if (f[j].sum(0, lo) == 0 || f[k].sum(0, lo) == 0) lo++;
			S[0] = lo;

			lo = 0, hi = n - 1, mid;
			while (lo < hi) {
				mid = (lo + hi + 1) / 2;
				if (f[j].sum(0, mid) == 0) lo = mid;
				else hi = mid - 1;
			}
			if (f[j].sum(0, lo) != 0) lo--;
			P[1] = lo;

			lo = 0, hi = n - 1, mid;
			while (lo < hi) {
				mid = (lo + hi + 1) / 2;
				if (f[j].sum(mid, n - 1) && f[k].sum(mid, n - 1)) lo = mid;
				else hi = mid - 1;
			}
			if (f[j].sum(lo, n - 1) == 0 || f[k].sum(lo, n - 1) == 0) lo--;
			P[0] = lo;

			lo = 0, hi = n - 1, mid;
			while (lo < hi) {
				mid = (lo + hi) / 2;
				if (f[j].sum(mid, n - 1) == 0) hi = mid;
				else lo = mid + 1;
			}
			if (f[j].sum(lo, n - 1) != 0) lo++;
			S[1] = lo;

			aa.clear();
//			cout << "i j k " << i << " " << j << " " << k << " " << P[0] << " " << P[1] << " " << S[0] << " " << S[1] << endl;
			if (S[0] <= P[0]) aa.push_back({ S[0], P[0] });
			if (S[1] <= P[1]) aa.push_back({ S[1], P[1] });
			if (max(S[0], S[1]) <= n - 1) aa.push_back({ max(S[0], S[1]), n - 1 });
			if (0 <= min(P[0], P[1])) aa.push_back({ 0, min(P[0], P[1]) });
//			for (const auto &xx : aa) cout << xx.first << " " << xx.second << endl;
			aa = simplify(aa);
//			cout << "to" << endl;
//			for (const auto &xx : aa) cout << xx.first << " " << xx.second << endl;
			for (const auto &xx : aa) ans += f[i].sum(xx.first, xx.second);
		}
	}
	return ans;
}

int main() {
	fast;
	M['S'] = 0;
	M['R'] = 1;
	M['P'] = 2;
	cin >> n >> q >> s;
	a.resize(n);
	f[0] = f[1] = f[2] = fenwick(n);
	for (int i = 0; i < n; i++) {
		a[i] = M[s[i]], cnt[a[i]]++;
		f[a[i]].add(i);
	}
	cout << calc() << endl;
	while (q--) {
		int pos;
		char ch;
		cin >> pos >> ch;
		pos--;
		f[a[pos]].sub(pos);
		cnt[a[pos]]--;
		a[pos] = M[ch];
		cnt[a[pos]]++;
		f[a[pos]].add(pos);
		cout << calc() << endl;
	}
}