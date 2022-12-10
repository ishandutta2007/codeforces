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

LL b, c;

pll F(LL n){
	if(n < b)
		return MP(0, n);
	LL base = b - (b % (b - c));
	LL Mod = n % (b - c);
	base += Mod;
	if(base >= b)
		base -= b - c;
	LL ans1 = (n - base) / (b - c);
	return MP(ans1, base);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	LL n, a;
	cin >> n >> a >> b >> c;
	LL ans2 = n / a + F(n % a).L;
	pll an = F(n);
	LL ans1 = an.L;
	cout << max(ans1 + an.R / a, ans2) << endl;
	return 0;
}