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

int n;
ll k, ans = 0;
string s, t;

int main() {
	fast;
	cin >> n >> k >> s >> t;
	if (k == 1) finish(n);
	if (s == t) finish(n);

	int pos = 0;
	while (pos < n - 1 && s[pos] == t[pos]) pos++;
	ans = 2 * n - pos;
	pos++;

	vector<int> sz1, sz2;

	// s
	for (int i = pos; i < n; i++) {
		if (s[i] == 'a') sz1.push_back(n - i);
	}
	while (sz1.size() && sz1.back() + 60 < sz1[0]) sz1.pop_back();
	for (int i = pos; i < n; i++) {
		if (t[i] == 'b') sz2.push_back(n - i);
	}
	while (sz2.size() && sz2.back() + 60 < sz2[0]) sz2.pop_back();

	map<int, ll> M, S;
	for (auto &i : sz1) S[i]++;
	for (auto &i : sz2) S[i]++;
	k -= 2;
	while (k > 0 && (M.size() > 0 || S.size() > 0)) {
		if (M.size() && (S.size() == 0 || M.rbegin()->first > S.rbegin()->first)) {
			auto p = *M.rbegin();
			M.erase(prev(M.end()));
			ans += p.first * min(k, p.second);
//			cout << "M " << p.first << " " << p.second << endl;
			k = max(0LL, k - p.second);
			if (p.first > 1) {
				M[p.first - 1] += (2 * p.second);
			}
		}
		else {
			auto p = *S.rbegin();
			S.erase(prev(S.end()));
			ans += p.first * min(k, p.second);
//			cout << "S " << p.first << " " << p.second << endl;
			k = max(0LL, k - p.second);
			if (p.first > 1) {
				M[p.first - 1] += p.second;
			}
		}
	}
	finish(ans);
}