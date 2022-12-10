#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

ll F(ll x){
	if(x <= 100){
		ll ans = 0;
		ans = min(x, (ll)9);
		for(int i = 10; i <= x; i++)
			if(i % 10 == i / 10)
				ans++;
		return ans;
	}
	ll t = 1, ans = 0;
	while(t * 10 < x)
		ans += 9 * max((ll)1, t / 10), t *= 10;
	for(int i = 1; i <= 9; i++){
		ll tt = t * (ll)i + i;
		ll lo = 0, hi = t / 10;
		while(hi - lo > 1){
			ll mid = (lo + hi) >> 1;
			if(tt + mid * 10 <= x)
				lo = mid;
			else
				hi = mid;
		}
		if(tt + (hi - 1) * 10 <= x)
			ans += hi;
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(false);
	ll l, r;
	cin >> l >> r;
	cout << F(r) - F(l - 1) << endl;
	return 0;
}