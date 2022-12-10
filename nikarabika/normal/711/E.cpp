//sobskdrbhvk
//remember the flying, the bird dies ):(
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

const LL Mod = 1000 * 1000 + 3;
LL n, k;

LL Pow(LL x, LL y){
	LL an = x,
	   ret = 1;
	while(y){
		if(y&1) ret = (ret * an) % Mod;
		an = (an * an) % Mod;
		y >>= 1;
	}
	return ret;
}

LL count(LL x){
	return x < 2 ? 0 : (x>>1) + count(x>>1);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	if(n < 63 and (1LL << n) < k){
		cout << 1 << ' ' << 1 << endl;
		return 0;
	}
	LL cnt = n + count(k - 1);
	LL nim = Pow(2, Mod - 2);
	LL B = Pow(Pow(2, n), k);
	B = (B * Pow(nim, cnt)) % Mod;
	if(k >= Mod){
		cout << B << ' ' << B << endl;
		return 0;
	}
	LL A = 1;
	LL day = Pow(2, n);
	for(int i = 0; i < k; i++)
		A = (A * (day - i)) % Mod;
	A = (A * Pow(nim, cnt)) % Mod;
	A = (A + Mod) % Mod;
	cout << (B - A + Mod) % Mod << ' ' << B << endl;
	return 0;
}