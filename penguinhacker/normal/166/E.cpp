#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pi pair<int, int>
const int MOD=1e9+7;

ll n, ans=1, pow3=1;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	while (n--) {
		ans = pow3-ans;
		ans = (ans+MOD)%MOD;
		pow3 = pow3*3%MOD;
	}
	cout << ans;
	return 0;
}