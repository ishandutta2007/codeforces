#define fast ios::sync_with_stdio(false); cin.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back
#define mp make_pair

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void solve() {
	int n;
	map<int, int> cnt;
	cin >> n;
	foru(i,0,n) {
		int tmp;
		cin >> tmp;
		cnt[tmp]++;
	}
	int mxocc = 0;
	for (auto ii : cnt)
		mxocc = max(mxocc, ii.second);
	if (mxocc * 2 <= n)
		cout << (n & 1) << '\n';
	else
		cout << (2 * mxocc - n) << '\n';
}

int main() {
	fast;
	int t;
	cin >> t;
	while (t--)solve();
	return 0;
}