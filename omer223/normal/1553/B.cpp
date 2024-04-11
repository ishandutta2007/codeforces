#pragma GCC optimize("Ofast", "-funroll-loops", "-fdelete-null-pointer-checks")
#pragma GCC target("ssse3", "sse3", "sse2", "sse", "avx2", "avx")
#pragma GCC optimize(3, "Ofast", "inline")
#define fast ios::sync_with_stdio(false); cin.tie(0);
#define foru(i, k, n) for (ll i = k; i < n; i++)
#define ford(i, k, n) for (ll i = k; i >= n; i--)
#define ff first
#define ss second
#define pb push_back

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <bitset>
#include <set>
#include <cmath>
#include <queue>
#include <stack>
#include <map>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;

string s, t;
int n, m;

string goLeft(int pos, int amt) {
	string cur = "";
	int cnt = amt;
	while (cnt-- && pos) {
		cur.push_back(s[--pos]);
	}
	return cur;
}

string goRight(int pos, int amt) {
	string cur = "";
	int cnt = amt;
	while (cnt-- && (pos != n - 1)) {
		cur.push_back(s[++pos]);
	}
	return cur;
}

void solve() {
	cin >> s >> t;
	n = s.length();
	m = t.length();
	foru(st, 0, n) {
		foru(l, 0, n) {
			int r = m - (l + 1);
			int rpos = st + r, lpos = rpos - l;
			if (lpos < 0 || rpos >= n)continue;
			string cur = s[st] + goRight(st, r) + goLeft(rpos, l);
			if (cur == t) {
				cout << "YES\n";
				return;
			}
		}
	}
	cout << "NO\n";
}

int main() {
	fast;
	int t;
	cin >> t;
	while (t--)solve();
	return 0;
}