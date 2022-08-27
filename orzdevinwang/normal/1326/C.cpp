#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 4e5 + 7, mod = 998244353;
int n, m, p[N], ns = 1;
int main () {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	L(i, 1, n) cin >> p[i];
	int lst = -1;
	ll ret = 0;
	L(i, 1, n) if(p[i] >= n - m + 1) {
		ret += p[i];
		if(lst != -1) ns = (ll) ns * (i - lst) % mod;
		lst = i;
	}
	cout << ret << ' ' << ns << '\n';
	return 0;
}