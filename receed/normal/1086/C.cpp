#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <random>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <queue>
#define rep(i, n) for (int i = 0; i < (n); i++)
 
typedef long long ll;
typedef long double ld;
using namespace std;

int t, n, k;

void print(vector<int> &p, vector<int> &r) {
	cout << "YES\n";
	int pr = 0;
	rep(i, k) {
		if (p[i] == -1) {
			while (r[pr] != -1)
				pr++;
			p[i] = pr++;
		}
		cout << (char) ('a' + p[i]);
	}
	cout << '\n';
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> t;
	string a, b, s;
	rep(z, t) {
		cin >> k >> s >> a >> b;
		n = s.size();
		vector<int> p(k, -1), r(k, -1);
		int pos = 0, ans = 1;
		while (pos < n && a[pos] == b[pos]) {
			int ch = s[pos] - 'a', cc = a[pos] - 'a';
			if (p[ch] != -1 && p[ch] != cc || r[cc] != -1 && r[cc] != ch) {
				ans = 0;
				break;
			}
			p[ch] = a[pos] - 'a';
			r[a[pos] - 'a'] = ch;
			pos++;
		}
		if (!ans) {
			cout << "NO\n";
			continue;
		}
		int nc = s[pos] - 'a';
		if (pos == n || a[pos] - 'a' < p[nc] && p[nc] < b[pos] - 'a') {
			print(p, r);
			continue;
		}
		for (int i = a[pos] - 'a' + 1; i < b[pos] - 'a'; i++)
			if (p[nc] == -1 && r[i] == -1) {
				p[nc] = i;
				r[i] = nc;
				ans = 2;
				break;
			}
		if (ans == 2) {
			print(p, r);
			continue;
		}
		if (p[nc] == a[pos] - 'a' || p[nc] == -1 && r[a[pos] - 'a'] == -1) {
			vector<int> np = p, nr = r;
			np[nc] = a[pos] - 'a';
			nr[a[pos] - 'a'] = nc;
			vector<int> ls;
			rep(i, k)
				if (nr[i] == -1)
					ls.push_back(i);
			for (int i = pos + 1; i < n; i++) {
				int ch = s[i] - 'a';
				if (np[ch] == -1) {
					np[ch] = ls.back();
					nr[ls.back()] = ch;
					ls.pop_back();
				}
				if (np[ch] < a[i] - 'a') {
					ans = 0;
					break;
				}
				if (np[ch] > a[i] - 'a') {
					break;
				}
			}
			if (ans) {
				print(np, nr);
				continue;
			}
		}
		
		if (p[nc] == b[pos] - 'a' || p[nc] == -1 && r[b[pos] - 'a'] == -1) {
			ans = 1;
			vector<int> np = p, nr = r;
			np[nc] = b[pos] - 'a';
			nr[b[pos] - 'a'] = nc;
			vector<int> ls;
			for (int i = k - 1; i >= 0; i--)
				if (nr[i] == -1)
					ls.push_back(i);
			for (int i = pos + 1; i < n; i++) {
				int ch = s[i] - 'a';
				if (np[ch] == -1) {
					np[ch] = ls.back();
					nr[ls.back()] = ch;
					ls.pop_back();
				}
				if (np[ch] > b[i] - 'a') {
					ans = 0;
					break;
				}
				if (np[ch] < b[i] - 'a') {
					break;
				}
			}
			if (ans) {
				print(np, nr);
				continue;
			}
		}
		cout << "NO\n";
	}
}