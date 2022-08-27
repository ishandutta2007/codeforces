#include<bits/stdc++.h>
#define ll long long
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define vi vector < int > 
#define sz(a) ((int) a.size()) 
using namespace std;
const int N = 1e6 + 7, mod = 998244353;
int n, a[N], R[N + N];
int main () {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	L(i, 1, n) cin >> a[i];
	ll res = 0;
	L(i, 1, n) if(i & 1) {
		ll lst = a[i], now = a[i];
		L(j, i + 1, n) {
			if(!(j & 1)) {
				now -= a[j];
				if(now <= lst) {
					if(lst == a[i]) res += lst - max(now, 0LL);
					else res += lst - max(now, 0LL) + 1;
					lst = max(now, 0LL);
					if(now < 0) break;
				}
			}
			else {
				now += a[j];
			}
		}
	} 
	cout << res << "\n";
	return 0;
}