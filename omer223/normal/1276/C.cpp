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
#include <numeric>
#include <queue>
#include <bitset>
#include <set>
#include <deque>
#include <map>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main() {
	fast;
	map<int, int> cnt;
	int n, bstr = 0, bstc = 0;
	ll bst = 0;
	cin >> n;
	foru(i, 0, n) {
		int tmp;
		cin >> tmp;
		cnt[tmp]++;
	}
	map<int, int> tcnt = cnt;
	queue<int> q, tq;
	for (pii ii : tcnt)q.push(ii.ff);
	int good = 0;
	for (int r = 1; r <= n; r++) {
		while (!q.empty()) {
			int x = q.front(); q.pop();
			tcnt[x]--;
			if (tcnt[x])tq.push(x);
			good++;
		}
		while (!tq.empty()) {
			q.push(tq.front()); tq.pop();
		}
		int c = good / r;
		if (c >= r) {
			if (bst < (ll)r*c) {
				bst = (ll)r*c;
				bstr = r, bstc = c;
			}
		}
	}
	vector<vector<int>> ret(bstr, vector<int>(bstc, -1));
	cout << bst << '\n' << bstr << ' ' << bstc << '\n';
	int tot = 0, crj = 0, crcnt = 0;
	vector<pii> cntarr;
	for (pii ii : cnt)cntarr.pb({ ii.ss,ii.ff });
	sort(cntarr.rbegin(), cntarr.rend());
	for (pii ii : cntarr) {
		for (int i = 0; i < min(ii.ff, bstr) && tot < bst; i++) {
			ret[crcnt][(crcnt + crj) % bstc] = ii.ss;
			crcnt++;
			if (crcnt == bstr)crcnt = 0, crj++;
			tot++;
		}
	}
	foru(i, 0, bstr) {
		foru(j, 0, bstc)cout << ret[i][j] << ' ';
		cout << '\n';
	}
	return 0;
}