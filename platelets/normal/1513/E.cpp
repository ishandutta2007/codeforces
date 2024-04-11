#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back

using namespace std;
const int N = 2e5 + 5;
typedef long long ll;
const ll P = 1e9 + 7;
int n, a[N];
ll Pow(ll a, int n, ll r = 1) {
	for(; n; n /= 2, a = a * a % P)
	if(n & 1) r = r * a % P;
	return r;
}		
ll f(int x, ll r = 1) { while(x) r = r * x-- % P; return r; }
int main() {
	#ifdef local
		freopen(".in", "r", stdin);
	#endif
	cin >> n;
	long long su = 0, as = 1;  
	rep(i, 1, n) scanf("%d", &a[i]), su += a[i];
	if(su % n) puts("0"), exit(0);
	su /= n;
	sort(a + 1, a + n + 1);
	int cn1 = 0, cn2 = 0;
	rep(i, 1, n) if(i == 1 || a[i] ^ a[i - 1]) {
		int cn = upper_bound(a + 1, a + n + 1, a[i]) - lower_bound(a + 1, a + n + 1, a[i]);
		if(a[i] < su) cn1 += cn;
		if(a[i] > su) cn2 += cn; 
		if(a[i] ^ su) (as *= f(cn)) %= P;
	}
	if(cn1 <= 1 || cn2 <= 1) cout << f(n) * Pow(as * f(n - cn1 - cn2) % P, P - 2) % P;
	else cout << 2 * f(n) * f(cn1) % P * f(cn2) % P * Pow(as * f(n - cn1 - cn2) % P * f(cn1 + cn2) % P, P - 2) % P;
	return 0;
}