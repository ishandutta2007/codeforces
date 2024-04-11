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

const int maxn = 1000 + 10;
const LL Mod = 1000LL * 1000000 + 7;
LL fact[maxn], P2[maxn];
int n, m;
vector<int> ons;

LL Pow(LL x, LL y){
	LL ret = 1, an = x;
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
	fact[0] = P2[0] = 1;
	for(LL i = 1; i < maxn; i++){
		fact[i] = (fact[i - 1] * i) % Mod;
		P2[i] = (P2[i - 1] * 2) % Mod;
	}
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int x;
		cin >> x;
		ons.PB(x);
	}
	sort(ons.begin(), ons.end());
	LL ans = fact[n - m];
	ans = Div(ans, fact[ons[0] - 1]);
	ans = Div(ans, fact[n - ons.back()]);
	for(int i = 0; i + 1 < sz(ons); i++){
		int cnt = ons[i + 1] - ons[i] - 1;
		ans = Div(ans, fact[cnt]);
		if(cnt)
			ans = (ans * P2[cnt - 1]) % Mod;
	}
	cout << ans << endl;
	return 0;
}