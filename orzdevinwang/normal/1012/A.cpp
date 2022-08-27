#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int> 
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 1 << 20;
int n, w[N];
int main () {
	ios :: sync_with_stdio(false);
	cin.tie (0); cout.tie (0);
	cin >> n;
	L(i, 1, n * 2) cin >> w[i];
	sort(w + 1, w + n * 2 + 1);
	ll ns = (ll) (w[n] - w[1]) * (w[n * 2] - w[n + 1]);
	L(l, 2, n) 
		ns = min(ns, (ll) (w[n * 2] - w[1]) * (w[l + n - 1] - w[l]));
	cout << ns << '\n';
	return 0;
}