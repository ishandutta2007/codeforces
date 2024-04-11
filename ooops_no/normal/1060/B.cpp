/*
_NUUUUUUU_
*/
#include<iostream>
#include<vector>
#include<algorithm>

typedef long long ll;
using namespace std;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll x, f = 9, s;
	cin >> x;
	if (x <= 9){
	    cout << x;
	    return 0;
	}
	while (f * 10 + 9 <= x) {
		f = f * 10 + 9;
	}
	s = x - f;
	ll cnt = 0;
	while (f > 0 ) {
		cnt += f % 10;
		f /= 10;
	}
	while (s > 0) {
		cnt += s % 10;
		s /= 10;
	}
	cout << cnt;
}