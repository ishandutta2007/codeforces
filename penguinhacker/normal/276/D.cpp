#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pi pair<int, int>
const int MOD=1e9+7;

ll a, b, ans=0;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> a >> b;
	for (int i=61; i>=0; --i) {
		if ((a&(1ll<<i))^(b&(1ll<<i))) {
			ans=(1ll<<(i+1))-1;
			break;
		}
	}
	cout << ans;
	return 0;
}