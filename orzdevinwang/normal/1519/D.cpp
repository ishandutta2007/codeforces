#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); i++) 
#define R(i, j, k) for(int i = (j); i >= (k); i--)
#define ll long long
#define sz(a) ((int) a.size())
#define vi vector<int>
using namespace std;
const int N = 2e5 + 7;
int n;
ll a[N], b[N], all, ns;

void calc(ll l, ll r) {
	ll res = 0;
	while((--l) >= 1 && (++r) <= n) {
		res += a[l] * b[r] + a[r] * b[l] - a[l] * b[l] - a[r] * b[r];
		ns = max(ns, res);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	L(i, 1, n) cin >> a[i];
	L(i, 1, n) cin >> b[i], all += a[i] * b[i];
	L(i, 1, n) calc(i, i);
	L(i, 1, n - 1) calc(i + 1, i);
	cout << ns + all << "\n";
	return 0;
}