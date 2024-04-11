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

const LL Mod = 1e9 + 7;

LL Pow(LL x, LL y){
	LL an = x, ret = 1;
	while(y){
		if(y&1) ret = (ret * an) % Mod;
		an = (an * an) % Mod;
		y >>= 1;
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	LL n;
	cin >> n;
	n = Pow(2, n);
	cout << (n * (n + 1) / 2) % Mod << '\n';
	return 0;
}