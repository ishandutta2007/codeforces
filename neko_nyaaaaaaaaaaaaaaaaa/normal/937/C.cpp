#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
	ios::sync_with_stdio(0);
	
	ll k, d, t;
	cin >> k >> d >> t;
	ld interval = (k + d-1)/d * d;
	ld on = k;
	ld off = interval - on;
	ld speed = on + off/2;
	ld ans = 0;
	ld need = t;
	ans += floor(need/speed)*interval;
	need -= floor(need/speed)*speed;
	if (need <= on) {ans += need;}
	else {
		need -= on;
		ans += on;
		ans += need*2;
	}
	cout << fixed << setprecision(12) << ans;
	
	return 0;
}