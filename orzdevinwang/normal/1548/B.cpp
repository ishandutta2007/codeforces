#include<bits/stdc++.h>
#define ll long long
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define vi vector < int >
#define sz(a) ((int) a.size())
using namespace std;
const int N = 5e5 + 7, mod = 998244353;
int n, tp, pos[N];
ll val[N];
ll w[N], a[N];
void Main () {
	int ns = 0;
	cin >> n;
	L(i, 1, n) cin >> w[i];
	--n ;
	L(i, 1, n) a[i] = abs(w[i] - w[i + 1]);
//	L(i, 1, n) cout << a[i] << " ";
//	cout << "\n";
	tp = 0;
	L(i, 1, n) {
		L(j, 1, tp) val[j] = __gcd(val[j], a[i]);
		++tp, val[tp] = a[i], pos[tp] = i;
		int c = tp;
		ll lst = -1;
		tp = 0;
		L(j, 1, c) if(val[j] != lst) 
			++tp, lst = val[j], val[tp] = val[j], pos[tp] = pos[j]; 
		L(j, 1, tp) 
			if(val[j] != 1) 
				ns = max(ns, i - pos[j] + 1);
	}
	cout << ns + 1 << "\n";
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
	while (T--) Main ();
	return 0;
}