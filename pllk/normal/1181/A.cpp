#include <iostream>

using namespace std;

typedef long long ll;

ll x, y, z;
pair<ll,ll> u;

int main() {
	cin >> x >> y >> z;
	u = {x/z+y/z,0};
	ll e2 = z-x%z;
	ll x2 = x+e2;
	ll y2 = y-e2;
	if (y2 >= 0) u = max(u,{x2/z+y2/z,-e2});
	ll e3 = z-y%z;
	ll x3 = x-e3;
	ll y3 = y+e3;
	if (x3 >= 0) u = max(u,{x3/z+y3/z,-e3});
	cout << u.first << " " << -u.second << "\n";
}