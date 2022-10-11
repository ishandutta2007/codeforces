// Not my code, playing around with
// https://codeforces.com/contest/1176/submission/55364833

#include <bits/stdc++.h>
#include <bits/basic_ios.h>

using namespace std;

#define int long long

bool codejam = 0;

typedef long long li;
typedef long double ld;

void solve();

int32_t main () {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout << fixed << setprecision(20);
	#ifdef LOCAL
		freopen("input.txt", "r", stdin);
	#endif
	int t = 1;
	// int t; 
	// cin >> t;
	int tt = t;
	while (t--) { 
		if (codejam) cout << "Case #" << tt - t << ": ";
		solve();
	}
	return 0;
}

const int mx = 2750150;
int spf[2750151];
int p[2750151];	
void precompute() {
	for (int i = 1; i <= mx; ++i)
		spf[i] = i;
	for (int i = 2; i <= mx; ++i) {
		if (spf[i] != i)
			continue;
		for (int j = i * i; j <= mx; j += i)
			spf[j] = min(spf[j], i);
	}
	int cur = 0;
	for (int i = 2; i <= mx; ++i) {
		if (spf[i] == i)
			p[++cur] = i;
	}
}
multiset<int> pr, npr;
vector<int> prr, nprr;
vector<int> ans;
void solve() {
	precompute();
	int n;
	cin >> n;
	for (int i = 1; i <= 2 * n; ++i) {
		int lol;
		cin >> lol;
		if (spf[lol] == lol)
			pr.insert(lol), prr.push_back(lol);
		else 
			npr.insert(lol), nprr.push_back(lol);
	}
	sort(prr.begin(), prr.end());
	sort(nprr.begin(), nprr.end());
	reverse(nprr.begin(), nprr.end());
	for (auto i: nprr) {
		if (npr.find(i) == npr.end())
			continue;
		int lol = spf[i];
		lol = i / lol;
		if (spf[lol] != lol) npr.erase(npr.find(lol));
		else pr.erase(pr.find(lol));
		npr.erase(npr.find(i));
		ans.push_back(i);
	}
	for (auto i: prr) {
		if (pr.find(i) == pr.end())
			continue;
		int lol = p[i];
		pr.erase(pr.find(lol));
		pr.erase(pr.find(i));
		ans.push_back(i);
	}
	assert((int) ans.size() == n);
	for (auto i: ans) {
		cout << i << " ";
	}
}