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
#include <bitset>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <queue>
#define rep(i, n) for (int i = 0; i < (n); i++)
 
typedef long long ll;
typedef long double ld;
using namespace std;


int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n >> m;
	vector<vector<int>> a(n, vector<int>(m)), b(n, vector<int>(m)), r(n, vector<int>(m));
	string s, ch = "ACGT";
	rep(i, n) {
		cin >> s;
		rep(j, m)
			a[i][j] = ch.find(s[j]);
	}
	vector<int> p = {0, 1, 2, 3};
	int ans = -1, ca;
	do {
		ca = 0;
		rep(i, n) {
			int s1 = 0, s2 = 0;
			rep(j, m) {
				if (a[i][j] == p[i % 2 * 2 + j % 2])
					s1++;
				if (a[i][j] == p[i % 2 * 2 + 1 - j % 2])
					s2++;
			}
			if (s1 > s2) {
				ca += s1;
				rep(j, m)
					b[i][j] = p[i % 2 * 2 + j % 2];
			}
			else {
				ca += s2;
				rep(j, m)
					b[i][j] = p[i % 2 * 2 + 1 - j % 2];
			}
		}
		if (ca > ans) {
			ans = ca;
			r = b;
		}
		ca = 0;
		rep(i, m) {
			int s1 = 0, s2 = 0;
			rep(j, n) {
				if (a[j][i] == p[i % 2 * 2 + j % 2])
					s1++;
				if (a[j][i] == p[i % 2 * 2 + 1 - j % 2])
					s2++;
			}
			if (s1 > s2) {
				ca += s1;
				rep(j, n)
					b[j][i] = p[i % 2 * 2 + j % 2];
			}
			else {
				ca += s2;
				rep(j, n)
					b[j][i] = p[i % 2 * 2 + 1 - j % 2];
			}
		}
		if (ca > ans) {
			ans = ca;
			r = b;
		}
	} while (next_permutation(p.begin(), p.end()));
	rep(i, n) {
		rep(j, m)
			cout << ch[r[i][j]];
		cout << '\n';
	}
}