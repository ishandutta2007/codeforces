#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int> 
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 1 << 19;
int n, q, a[N], v[N], stk[N], tp;
int main () {
	ios :: sync_with_stdio(false);
	cin.tie (0); cout.tie (0);
	cin >> n >> q;
	L(i, 1, n) cin >> a[i], v[i] = abs (a[i] - a[i - 1]);
	while (q--) {
		int l, r;
		cin >> l >> r;
		++l;
		ll ns = 0, ret = 0;
		stk[0] = l - 1, tp = 0;
		L(i, l, r) {
			while (tp > 0 && v[i] > v[stk[tp]]) ret -= (ll) v[stk[tp]] * (stk[tp] - stk[tp - 1]), -- tp;
			stk[++tp] = i;
			ret += (ll) v[stk[tp]] * (stk[tp] - stk[tp - 1]);
			ns += ret;
		}
		cout << ns << "\n";
	}
	return 0;
}