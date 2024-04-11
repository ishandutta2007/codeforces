#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define fast ios::sync_with_stdio(false); cin.tie(0);
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define ff first
#define ss second

#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
#include <stack>
#include <set>
#include <map>
#include <deque>
#include <queue>
#include <unordered_map>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<ll> vi;

vector<int> v1{ -1,3,6,1,5,4,7,2 }, v2{ -1, 3,6,1,5,4,2 };

bool check(vector<int> v) {
	int n = v.size() - 1;
	for (int i = 1; i <= n; i++) {
		if ((v[i] & i) != 0)return 0;
	}
	return 1;
}

int msb(int n) {
	if (n == 0)return -1;
	for (int i = 20; i >= 0; i--) {
		if (n & (1 << i))return i;
	}
	return -1;
}

void solvezero(int n) {
	if (n & 1) {
		cout << "NO\n";
		return;
	}
	cout << "YES\n";
	vector<int> v(n + 1, 0);
	int nn = n;
	while (nn >= 1) {
		int m = msb(nn);
		int mx = (1 << (m + 1)) - 1;
		int mn = mx - nn;
		for (int i = mn; i <= nn; i++) {
			v[i] = mx - i;
		}
		nn = mn - 1;
	}
	for (int i = 1; i <= n; i++)cout << v[i] << ' ';
	cout << '\n';
	//cout << check(v) << '\n';
}

void solvenotzero(int n) {
	vector<int> v;
	if (n & 1) {
		if (n < 7) {
			cout << "NO\n";
			return;
		}
		cout << "YES\n";
		v = v1;
		int nn = 7;
		while (nn < n) {
			v.push_back(nn + 2);
			v.push_back(nn + 1);
			nn += 2;
		}
		for (int i = 1; i <= n; i++)cout << v[i] << ' ';
		cout << '\n';
	}
	else {
//#define DEBUG
#ifndef DEBUG
#define __popcnt(x) __builtin_popcount(x)
#endif
		if (__popcnt(n) == 1) {
			cout << "NO\n";
			return;
		}
		cout << "YES\n";
		v = v2;
		int nn = 6;
		while (nn < n) {
			int c1 = nn + 1, c2 = nn + 2, c3 = nn + 3, c4 = nn + 4;
			if ((c1 & c2) != 0) {
				v.push_back(c2);
				v.push_back(c1);
				nn += 2;
			}
			else {
				v.push_back(c3);
				v.push_back(c4);
				v.push_back(c1);
				v.push_back(c2);
				nn += 4;
			}
		}
		for (int i = 1; i <= n; i++)cout << v[i] << ' ';
		cout << '\n';
	}
	//cout << check(v) << '\n';
}

void foo(int n, bool flag) {
	vector<int> v;
	foru(i, 0, n)v.push_back(i);
	do {
		bool bad = 0;
		foru(i, 0, n) {
			int stat = (v[i] + 1) & (i + 1);
			if (v[i]==i||((stat == 0) != flag))bad = 1;
		}
		if (!bad) {
			cout << "YES\n";
			foru(i, 0, n)cout << v[i] + 1 << ' ';
			cout << '\n';
			return;
		}
	} while (next_permutation(v.begin(), v.end()));
	cout << "NO\n";
}

int main() {
	fast;
	int n;
	cin >> n;
	solvezero(n);
	solvenotzero(n);
	return 0;
}