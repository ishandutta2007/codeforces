#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
#define me(f, x) memset(f, x, sizeof(f))
#define uint unsigned int
using namespace std;
const int N = 2007, mod = 998244353;
int n, x[N * N], y[N * N];
int a[N][N], c1[N], c2[N];
int main () {
    ios :: sync_with_stdio(false);
    cin.tie (0); cout.tie (0);
    cin >> n;
    L(i, 1, n) {
    	L(j, 1, n) {
    		cin >> a[i][j];
    		x[a[i][j]] = i;
    		y[a[i][j]] = j;
		} 
	}
	ll all = (ll) n * (n - 1) * n * (n - 1) / 2;
	L(i, 1, n * n) {
		all -= c1[x[i]] * c2[y[i]];
		c1[x[i]] += 1;
		c2[y[i]] += 1;
	}
	cout << all << '\n';
    return 0;
}