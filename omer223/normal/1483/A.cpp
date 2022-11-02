#define _CRT_SECURE_NO_WARNINGS
#define fast ios::sync_with_stdio(false); cin.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back
#define ff first
#define ss second

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <list>
#include <set>
#include <stack>
#include <tuple>
#include <bitset>
#include <queue>
#include <numeric>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


int n, m;

void solve() {
	cin >> n >> m;
	vector<vector<int>> v(m), fr(n);
	vector<int> dys, cnt(n, 0), ass(m, 0);
	foru(i, 0, m) {
		dys.pb(i);
		int k;
		cin >> k;
		foru(j, 0, k) {
			int tmp;
			cin >> tmp;
			tmp--;
			v[i].pb(tmp);
			fr[tmp].pb(i);
		}
	}
	sort(dys.begin(),dys.end(), [&](const int& a, const int& b) -> bool
	{
		return v[a].size() < v[b].size();
	});
	foru(j, 0, m) {
		int mn = 1e9, mni = -1;
		for (int x : v[dys[j]]) {
			if (cnt[x] < mn) {
				mni = x;
				mn = cnt[x];
			}
		}
		cnt[mni]++;
		ass[dys[j]] = mni;
	}
	foru(i, 0, n) {
		if (cnt[i] > (m + 1) / 2) {
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
	foru(i, 0, m) {
		cout << ass[i] + 1 << ' ';
	}
	cout << '\n';
}

int main() {
	fast;
	int t;
	cin >> t;
	while (t--)solve();
	return 0;
}