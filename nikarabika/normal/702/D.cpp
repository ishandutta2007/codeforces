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

LL d, k, a, b, t;

LL f(LL d1){
	if(d1 == 0)
		return d * b;
	LL ret = d1 * a + ((d1 - 1) / k) * t + (d - d1) * b;
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> d >> k >> a >> b >> t;
	LL lo = 0,
	   hi = d;
	while(hi - lo > 3000 * 1000){
		LL mid1 = (lo + lo + hi) / 3,
		   mid2 = (lo + hi + hi) / 3;
		if(f(mid1) < f(mid2))
			hi = mid2;
		else
			lo = mid1;
	}
	LL ans = 2e18;
	for(LL i = lo; i <= hi; i++)
		smin(ans, f(i));
	cout << ans << '\n';
	return 0;
}