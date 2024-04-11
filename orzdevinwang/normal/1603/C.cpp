#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int> 
#define sz(a) ((int) (a).size())
#define ull unsigned long long 
using namespace std;
const int N = 1 << 20, mod = 998244353;
int n, a[N];
int stk[N], cnt[N], tp;
int nstk[N], ncnt[N], ntp;
void Main () {
	int ns = 0;
	cin >> n;
	L(i, 1, n) cin >> a[i];
	tp = 0;
	R(i, n, 1) { 
		++tp, stk[tp] = 1e9, cnt[tp] = 1;
		ntp = 0;
		R(j, tp, 1) {
			int k = (a[i] - 1) / stk[j] + 1;
			(ns += (ll) (k - 1) * i % mod * cnt[j] % mod) %= mod;
			if(!ntp || a[i] / k != nstk[ntp]) 
				++ntp, nstk[ntp] = a[i] / k, ncnt[ntp] = cnt[j];
			else 
				ncnt[ntp] += cnt[j];
//			stk[j] = a[i] / k;
		}
		tp = ntp;
		L(j, 1, tp) stk[j] = nstk[j], cnt[j] = ncnt[j];
	}
	cout << ns << '\n';
}
int main () {
	ios :: sync_with_stdio(false);
	cin.tie (0); cout.tie (0);
	int T;
	cin >> T ;
	while (T--) Main (); 
	return 0;
}