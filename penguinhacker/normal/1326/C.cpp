#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

#define ll long long
#define arr array

int n, k, cnt=0, p[200001];
ll ans=1;
vector<int> largest;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	for (int i=1; i<=n; ++i) {
		cin >> p[i];
		if (p[i] >= n-k+1)
			largest.push_back(i);
	}

	for (int i=0; i<k-1; ++i) {
		ans = ans*(largest[i+1]-largest[i])%MOD;
	}
	
	cout << 1ll*(2*n-k+1)*k/2 << ' ' << ans << '\n';
	return 0;
}