#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define sz(x) (int) ((x).size())
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define fornr(i, n) for (int i = (n) - 1; i >= 0; --i)
#define forab(i, a, b) for (int i = (a); i < (b); ++i)
#define all(c) (c).begin(), (c).end()

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) static_cast<void>(0)
#endif

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using uint = unsigned int;
using vi = vector<int>;
using pii = pair<int, int>;

const int N = 1e5 + 5;

vi g[N];
int used[N];

bool mergeSort(int l, int r, const string& s, int& cur) {
	if (r - l <= 1)
		return false;
	int m = (l + r) / 2;
	if (mergeSort(l, m, s, cur))
		return true;
	if (mergeSort(m, r, s, cur))
		return true;
	int i = l, j = m;
	while (i < m && j < r) {
		if (cur >= s.size()) 
			return true;
		if (s[cur] == '0')
			i++;
		else
			j++;
		cur++;
	}
	return false;
}

bool check(int m, const string& s) {
	int cur = 0;
	return mergeSort(0, m, s, cur);
}

vi mergeSortAns(int l, int r, const string& s, int& cur) {
	if (r - l <= 1)
		return {l};
	int m = (l + r) / 2;
	vi vL = mergeSortAns(l, m, s, cur);
	vi vR = mergeSortAns(m, r, s, cur);
	int i = l, j = m;
	vi res;
	while (i < m && j < r) {
		if (s[cur] == '0') {
			g[vL[i - l]].pb(vR[j - m]);
			res.pb(vL[i - l]);
			i++;
		}
		else {
			g[vR[j - m]].pb(vL[i - l]);
			res.pb(vR[j - m]);
			j++;
		}
		cur++;
	}
	while (i < m)
		res.pb(vL[i - l]), i++;
	while (j < r)
		res.pb(vR[j - m]), j++;
	return res;
}

void dfs(int v, vi& ans) {
	used[v] = 1;
	for (int u : g[v])
		if (!used[u])
			dfs(u, ans);
	ans.pb(v);
}

vi getAns(int m, const string &s) {
	int cur = 0;
	mergeSortAns(0, m, s, cur);
	vector<int> ans;
	forn (i, m)
		if (!used[i])
			dfs(i, ans);
	reverse(all(ans));
	return ans;
}

int main() {
#ifdef LOCAL
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
#endif
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	string s;
	cin >> s;
	int l = 1, r = 1e5 + 1; 
	while (r - l > 1) {
		int m = (l + r) / 2;
		if (check(m, s))
			r = m;
		else
			l = m;
	}
	cout << l << "\n";
	auto revAns = getAns(l, s);
	vector<int> ans(l);
	for (int i = 0; i < l; i++)
		ans[revAns[i]] = i + 1;
	for (int k : ans)
		cout << k << " ";
	cout << "\n";
	
	return 0;
}