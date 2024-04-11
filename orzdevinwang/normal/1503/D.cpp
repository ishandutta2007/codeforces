#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define pii pair<int, int>
#define mkp make_pair
#define db double
#define x first
#define y second
#define sz(a) ((int) (a).size())
#define vi vector<int>
using namespace std;
const int N = 4e5 + 7;
int n, a[N], c[N], suf[N];
int mx1 = 1e9, mx2 = 1e9, p, len, ns, Mn = 1e9;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	L(i, 1, n) {
		int u, v, ok = false;
		cin >> u >> v;
		if(min(u, v) > n) return cout << "-1\n", 0;
		if(u > v) swap(u, v), c[u] = true;
		a[u] = v;
	}
	R(i, n, 1) suf[i] = max(suf[i + 1], a[i]);
	L(i, 1, n) {
		++len, Mn = min(Mn, a[i]);
		if(a[i] < mx1) mx1 = a[i], p += ! c[i];
		else if(a[i] < mx2) mx2 = a[i], p += c[i];
		else return cout << "-1\n", 0;
		if(Mn > suf[i + 1]) ns += min(p, len - p), mx1 = mx2 = 1e9, p = len = 0;
	}
	cout << ns << "\n";
	return 0;
}