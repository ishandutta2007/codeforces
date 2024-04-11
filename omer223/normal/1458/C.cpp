#define fast ios::sync_with_stdio(false); cin.tie(0);
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back
#define ff first
#define ss second

#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
#include <set>
#include <map>
#include <random>
#include <time.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;


inline ll md(ll x, ll n) {
	x--;
	x %= n;
	if (x < 0)x += n;
	return x + 1;
}

void solve() {
	int n, q;
	cin >> n >> q;
	vector<vector<int>> v(n + 1, vector<int>(n + 1)), ret = v;
	foru(i, 0, n) {
		foru(j, 0, n)cin >> v[i + 1][j + 1];
	}
	vector<pair<char, int>> delta{ {'R',0},{'C',0},{'V',0} };
	string s;
	cin >> s;
	foru(i, 0, q) {
		switch (s[i]) {
		case 'U':
			delta[0].ss--;
			break;
		case 'D':
			delta[0].ss++;
			break;
		case 'L':
			delta[1].ss--;
			break;
		case 'R':
			delta[1].ss++;
			break;
		case 'I':
			swap(delta[1], delta[2]);
			break;
		case 'C':
			swap(delta[0], delta[2]);
			break;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int p[3];
			foru(k, 0, 3) {
				if (delta[k].ff == 'R')p[k] = md(i + delta[k].ss, n);
				else if (delta[k].ff == 'C')p[k] = md(j + delta[k].ss, n);
				else p[k] = md(v[i][j] + delta[k].ss, n);
			}
			ret[p[0]][p[1]]= p[2];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)cout << ret[i][j] << ' ';
		cout << '\n';
	}
}



int main() {
	fast;
	int t;
	cin >> t;
	while (t--)solve();
	return 0;
}
/*
1
5 10000
1 4 3 5 2
3 1 5 2 4
5 3 2 4 1
4 2 1 3 5
2 5 4 1 3*/