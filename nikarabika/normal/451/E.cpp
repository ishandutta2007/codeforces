//sobskdrbhvk
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
#define smax(x, y) ((x) = max((x), (y)))
#define smin(x, y) ((x) = min((x), (y)))
#define all(x) x.begin(),x.end()

const int maxn = 20;
const LL Mod = 1e9 + 7;
LL a[maxn], sum[1 << maxn];
LL makh, s;
int n;

LL Pow(LL x, LL y){
	LL ret = 1, an = x;
	while(y){
		if(y & 1LL)
			ret = (ret * an) % Mod;
		an = (an * an) % Mod;
		y >>= 1;
	}
	return ret;
}

LL Div(LL x, LL y){
	return ((x % Mod) * Pow((y % Mod), Mod - 2)) % Mod;
}

LL C(LL nn, LL rr = n - 1){
	if(rr > nn)
		return 0;
	LL ret = 1;
	for(LL i = 0; i < rr; i++)
		ret = (ret * ((nn - i) % Mod)) % Mod;
	return (ret * makh) % Mod;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> s;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		sum[1 << i] = a[i] + 1;
	}
	for(int mask = 1; mask < (1 << n); mask++)
		if(__builtin_popcount(mask) > 1)
			sum[mask] = sum[mask & -mask] + sum[mask - (mask & -mask)];

	makh = 1;
	for(LL i = 1; i <= (LL)n - 1; i++)
		makh = (makh * i) % Mod;
	makh = Div(1, makh);

	LL ans = 0;
	for(int mask = 0; mask < (1 << n); mask++){
		if(sum[mask] > s)
			continue;
		LL sign = (__builtin_popcount(mask) & 1 ? -1 : +1);
		ans += C(s - sum[mask] + (LL)(n - 1)) * sign;
		if(ans < 0)
			ans += Mod + Mod;
		if(ans >= Mod)
			ans -= Mod;
	}
	cout << ans << endl;
	return 0;
}