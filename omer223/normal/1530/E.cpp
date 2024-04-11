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



void solve() {
	string s;
	int n;
	cin >> s;
	n = s.length();
	vector<int> cnt(26, 0);
	int lets;
	vector<pair<char, int>> mcnt, tmcnt;
	for (char c : s)cnt[c - 'a']++;
	foru(i, 0, 26)if (cnt[i])mcnt.push_back({ 'a' + i,cnt[i] });
	lets = mcnt.size();
	sort(s.begin(), s.end());
	if (s.front() == s.back()) {
		cout << s << '\n';
		return;
	}
	else if (n < 3) {
		cout << s << '\n';
		return;
	}
	//check uniue
	foru(i, 0, lets) {
		if (mcnt[i].ss == 1) {
			string ret = "";
			ret.push_back(mcnt[i].ff);
			mcnt[i].ss--;
			foru(j, 0, lets) {
				while (mcnt[j].ss) {
					ret.push_back(mcnt[j].ff);
					mcnt[j].ss--;
				}
			}
			cout << ret << '\n';
			return;
		}
	}
	string s1 = "", s2 = "";
	//ab
	if (mcnt.size() == 2) {
		s1.push_back(mcnt[0].ff);
		foru(i, 0, mcnt[1].ss)s1.push_back(mcnt[1].ff);
		foru(i, 0, mcnt[0].ss - 1)s1.push_back(mcnt[0].ff);
	}
	else {
		tmcnt = mcnt;
		s1.push_back(tmcnt[0].ff);
		tmcnt[0].ss--;
		s1.push_back(tmcnt[1].ff);
		tmcnt[1].ss--;
		while (tmcnt[0].ss) {
			s1.push_back(tmcnt[0].ff);
			tmcnt[0].ss--;
		}
		s1.push_back(tmcnt[2].ff);
		tmcnt[2].ss--;
		foru(i, 1, lets) {
			while (tmcnt[i].ss) {
				s1.push_back(tmcnt[i].ff);
				tmcnt[i].ss--;
			}
		}
	}
	//aa
	bool flag = 0;
	if (mcnt[0].second >= 2) {
		int sa = 0, sb = 0;
		sa = mcnt[0].ss - 2;
		foru(i, 1, lets)sb += mcnt[i].ss;
		if (sb >= sa) {
			flag = 1;
			tmcnt = mcnt;
			s2.push_back(tmcnt[0].ff);
			s2.push_back(tmcnt[0].ff);
			tmcnt[0].ss -= 2;
			int ptr = 1;
			while (tmcnt[0].ss) {
				s2.push_back(tmcnt[ptr].ff);
				tmcnt[ptr].ss--;
				if (!tmcnt[ptr].ss)ptr++;
				s2.push_back(tmcnt[0].ff);
				tmcnt[0].ss--;
			}
			foru(i, ptr, lets) {
				while (tmcnt[i].ss) {
					s2.push_back(tmcnt[i].ff);
					tmcnt[i].ss--;
				}
			}
		}
	}
	if (flag)cout << s2 << '\n';
	else cout << s1 << '\n';
}

int main() {
	fast;
	int t;
	cin >> t;
	while (t--)solve();
	return 0;
}