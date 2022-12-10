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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	LL n, ans = 0;
	cin >> n;
	for(int mask = 0; mask < (1 << 9); mask++){
		LL an = 1;
		for(LL i = 0; i < 9; i++)
			if((mask >> i) & 1)
				an = an / __gcd(an, i + 2) * (i + 2);
		if(__builtin_popcount(mask) & 1)
			ans -= n / an;
		else
			ans += n / an;
	}
	cout << ans << endl;
	return 0;
}