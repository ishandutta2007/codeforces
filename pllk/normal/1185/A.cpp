#include <iostream>

using namespace std;

typedef long long ll;

ll d;

ll lol1(ll a, ll b, ll c) {
	ll u = 0;
	if (b-a < d) {u += a+d-b; b = a+d;}
	if (c-b < d) {u += b+d-c;}
	return u;
}

ll lol2(ll a, ll b, ll c) {
	return max(a-(b-d),0LL)+max(b+d-c,0LL);
}

ll lol3(ll a, ll b, ll c) {
	ll u = 0;
	if (c-b < d) {u += b+d-c; b = c-d;}
	if (b-a < d) {u += a+d-b;}
	return u;
}

int main() {
	ll a, b, c;
	cin >> a >> b >> c >> d;
	if (a > b) swap(a,b);
	if (b > c) swap(b,c);
	if (a > b) swap(a,b);
	if (b > c) swap(b,c);
	cout << min(lol1(a,b,c),min(lol2(a,b,c),lol3(a,b,c))) << "\n";
}