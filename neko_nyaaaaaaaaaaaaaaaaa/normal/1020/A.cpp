#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	 
	ll n, h, a, b, k;
	cin >> n >> h >> a >> b >> k;
	while (k--) {
		ll ta, fa, tb, fb; 
		cin >> ta >> fa >> tb >> fb;
		
		if (ta == tb) {
			cout << abs(fa - fb) << '\n';
		} else {
			ll ans1 = abs(fa - fb);
			ll ans2 = abs(ta - tb);
			
			if ((fa > b && fb > b) || (fa < a && fb < a)) {
				ll ans3 = min(abs(fa - a)*2, abs(fa - b)*2);
				ll ans4 = min(abs(fb - a)*2, abs(fb - b)*2);
				ans2 += min(ans3, ans4);
			}
			
			cout << ans1+ans2 << '\n';
		}
	}
	
	return 0;
}