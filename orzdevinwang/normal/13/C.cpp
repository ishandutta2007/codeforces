#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j), i##E = k; i <= i##E; i++) 
#define R(i, j, k) for(int i = (j), i##E = k; i >= i##E; i--)
#define mkp make_pair
#define pii pair<int, int>
#define ll long long
#define db double
#define sz(a) a.size()
#define x first
#define y second
#define vi vector<int>
using namespace std;
const int N = 5005;
int n, a[N], arr[N], atot;
ll f[N], ns = 1e18;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	L(i, 1, n) cin >> a[i], arr[++atot] = a[i];
	sort(arr + 1, arr + atot + 1), atot = unique(arr + 1, arr + atot + 1) - arr - 1;
	memset(f, 0x3f, sizeof(f));
	arr[0] = -1e9, f[0] = 0;
	L(i, 1, n) {
		ll p = 1e18;
		L(j, 0, atot) p = min(p, f[j]), f[j] = p + abs(a[i] - arr[j]);
	}
	L(i, 1, atot) ns = min(ns, f[i]);
	cout << ns << "\n";
	return 0;
}