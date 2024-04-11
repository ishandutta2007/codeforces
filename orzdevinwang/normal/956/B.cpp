#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 2e5 + 7;
int n, U, E[N], W[N], m;
int main () {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cout.precision(12), cout << fixed;
	cin >> n >> U;
	L(i, 1, n) cin >> E[i];
	L(i, 1, n) W[i] = E[i + 1] - E[i];
	double ns = 2;
	L(i, 1, n - 2) {
		int z = upper_bound(E + 1, E + n + 1, U + E[i]) - E - 1;
		if(z >= i + 2) ns = min(ns, ((double) W[i]) / (E[z] - E[i]));
	}
	if(ns == 2) 
		cout << -1 << "\n";
	else 
		cout << 1. - ns << "\n";
	return 0;
}