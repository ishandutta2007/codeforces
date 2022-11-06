#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair
#define int long long

using namespace std;

int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	int x1; cin >> x1;
	int y1; cin >> y1;
	int x2; cin >> x2;
	int y2; cin >> y2;
	x2 -= x1;
	y2 -= y1;
	y2 /= 2ll;
	x2++;
	int r = x2 * y2 + (x2 + 1ll) / 2ll;
	cout << r;
}