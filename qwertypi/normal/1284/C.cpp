/* Hello, 2020! */

#include <bits/stdc++.h>

#define int long long
#define fi first
#define se second
#define pii pair<int, int>
#define vpii vector<pair<int, int>>
#define vppii vector<pair<pair<int, int>, pair<int, int>>>

using namespace std;

vector<pair<int, int>> A;

int fact[250001];
int32_t main(){
	int n, m;
	cin >> n >> m;
	fact[0] = 1;
	for(int i = 1; i <= n; i++){
		fact[i] = (fact[i - 1] * i) % m;
	}
	int ans = 0;
	for(int i = 1; i <= n; i++){
		ans += (n - i + 1)  * (fact[i] * fact[(n - i + 1)] % m) % m;
		ans %= m;
	}
	cout << ans << endl;
}