#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cassert>
#include <set>
#include <map>
#include <random>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <queue>

typedef long long ll;
typedef long double ld;
using namespace std;

vector<int> zf(string &s) {
	int n = s.size();
	vector<int> z(n);
	for (int i = 1, l = -1, r = -1; i < n; i++) {
		z[i] = max(min(r - i + 1, z[i - l]), 0);
		while (i + z[i] < n && s[i + z[i]] == s[z[i]])
			z[i]++;
		if (i + z[i] - 1 > r) {
			l = i;
			r = i + z[i] - 1;
		}
	}
	return z;
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	vector<string> a(n), b(n);
	vector<int> pl(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	string s1, s2, p1, t1;
	bool f = 0;
	for (int i = 0; i < n; i++) {
		cin >> b[i];
		int lp = -1, rp = -1;
		for (int j = 0; j < a[i].size(); j++) {
			if (a[i][j] != b[i][j]) {
				if (lp == -1)
					lp = j;
				rp = j;
			}
		}
		pl[i] = lp;
		if (lp == -1)
			continue;
		string c1 = a[i].substr(lp, rp - lp + 1), c2 = b[i].substr(lp, rp - lp + 1);
		if (!f) {
			s1 = c1;
			s2 = c2;
		}
		else if (s1 != c1 || s2 != c2) {
			cout << "NO\n";
			return 0;
		}
		if (!f) {
			p1 = a[i].substr(0, lp);
			reverse(p1.begin(), p1.end());
			t1 = a[i].substr(rp + 1, a[i].size() - rp);
			f = 1;
		}
		else {
			for (int j = 0; j < p1.size(); j++) {
				if (lp - j - 1 < 0 || a[i][lp - j - 1] != p1[j]) {
					p1.resize(j);
					break;
				}
			}
			for (int j = 0; j < t1.size(); j++) {
				if (rp + j + 1 >= a[i].size() || a[i][rp + j + 1] != t1[j]) {
					t1.resize(j);
					break;
				}
			}
		}
	}
	reverse(p1.begin(), p1.end());
	s1 = p1 + s1 + t1;
	s2 = p1 + s2 + t1;
	for (int i = 0; i < n; i++) {
		string ss = s1 + "#" + a[i];
		vector<int> z = zf(ss);
		int lp = -1;
		for (int j = 0; j < a[i].size(); j++) {
			if (z[s1.size() + j + 1] >= s1.size()) {
				lp = j;
				break;
			}
		}
		if (lp != -1)
			lp += p1.size();
		if (lp != pl[i]) {
			cout << "NO\n";
			return 0;
		}
	}
	cout << "YES\n" << s1 << '\n' << s2;
}