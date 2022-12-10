#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define sz(x) ((int)(x).size())
#define smin(x, y) (x) = min((x), (y))
#define smax(x, y) (x) = max((x), (y))

const LL Mod = 1000LL * 1000 * 1000 + 7;
LL n, m, r, q, b, ans;

LL sum(LL x){
	if(x & 1)
		return ((x % Mod) * (((x - 1) / 2) % Mod)) % Mod;
	return (((x / 2) % Mod) * ((x - 1) % Mod)) % Mod;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	b = 1;
	ans = 0;
	while(b <= n and b <= m){
		if(n % b == 0){
			b++;
			continue;
		}
		r = n % b;
		q = n / b;
		LL cnt = (r + q) / q;
		ans = (ans + (r % q) * cnt + sum(cnt) * q) % Mod;
		if(b + cnt - 1 >= m){
			LL cnt2 = b + cnt - m - 1;
			ans = (ans - (r % q) * cnt2 - sum(cnt2) * q) % Mod;
			ans = (ans + Mod) % Mod;
		}
		b += cnt;
	}
	ans += max(0LL, (m - n) % Mod) * (n % Mod);
	ans %= Mod;
	cout << ans << endl;
	return 0;
}