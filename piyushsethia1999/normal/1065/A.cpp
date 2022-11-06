#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair
#define int long long

using namespace std;

int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	int t; cin >> t;
	while (t--) {

		int s; cin >> s;
		int a; cin >> a;
		int b; cin >> b;
		int c; cin >> c;
		int w = (s / c);
		cout << (w / a) * (b) + w << "\n";
	}
}