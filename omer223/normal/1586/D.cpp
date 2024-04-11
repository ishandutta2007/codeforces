#pragma GCC optimize("Ofast", "-funroll-loops", "-fdelete-null-pointer-checks")
#pragma GCC target("ssse3", "sse3", "sse2", "sse", "avx2", "avx")
#pragma GCC optimize(3, "Ofast", "inline")
#define fast ios::sync_with_stdio(false); cin.tie(0);
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
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
#include <cmath>
#include <math.h>
#include <iomanip>
#include <numeric>
#include <random>
#include <time.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


int ask(vector<int> a) {
	cout << "? ";
	for (int x : a)cout << x << ' ';
	cout << endl;
	fflush(stdout);
	int idx;
	cin >> idx;
	fflush(stdout);
	return idx;
}


int n;

void solve() {
	cin >> n;
	vector<int> idx(n + 1, -1), p(n + 1, -1);
	for (int i = n; i > 1; i--) {
		vector<int> a(n);
		foru(j, 0, n - 1)a[j] = 1;
		a[n - 1] = (n-i+2);
		if (ask(a) == 0) {
			p[n] = i;
			break;
		}
	}
	if (p[n] == -1) {
		p[n] = 1;
	}
	for (int i = 1; i <= n; i++) {
		if (i == p[n])continue;
		int del = n + 1 - i;
		vector<int> a(n);
		foru(j, 0, n - 1)a[j] = del;
		a[n - 1] = n + 1 - p[n];
		int tmp = ask(a);
		p[tmp] = i;
	}
	cout << "! ";
	for (int i = 1; i <= n; i++)cout << p[i] << ' ';
	cout << endl;
	fflush(stdout);
}

int main() {
	fast;
	int t=1;
	//cin >> t;
	while (t--)solve();
	return 0;
}