//sobskdrbhvk
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef long double LD;
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

const int maxn = 1000 * 1000 + 85 - 69;
const LL Mod = (1000 * 1000 * 1000 + 7);
LL Pm[maxn],
   Pmm[maxn],
   n, m;

LL Pow(LL x, LL y){
	LL an = x, ret = 1;
	while(y){
		if(y & 1)
			ret = (ret * an) % Mod;
		an = (an * an) % Mod;
		y >>= 1;
	}
	return ret;
}

LL Div(LL x, LL y){
	return (x * Pow(y, Mod - 2)) % Mod;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	if(m == 1){
		cout << n + 1 << endl;
		return 0;
	}
	Pm[0] = Pmm[0] = 1;
	for(int i = 1; i < maxn; i++){
		Pm[i] = (Pm[i - 1] * m) % Mod;
		Pmm[i] = (Pmm[i - 1] * (m - 1)) % Mod;
	}
	LL C = 1,
	   ans = 0;
	for(LL x = 1; x <= n; x++){
		ans += (((Pm[x] * Pmm[n - x]) % Mod) * C) % Mod;
		ans %= Mod;
		C = (C * (n - x + 1)) % Mod;
		C = Div(C, x);
	}
	ans = (ans + Pm[n]) % Mod;
	cout << (ans + Mod) % Mod << endl;
	return 0;
}