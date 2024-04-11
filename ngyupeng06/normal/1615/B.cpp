#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define mp make_pair
#define pb push_back

ll n, m, t, p[20], a, b;
ll dp[200005][20];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	p[0]=1;
	for (int i=1; i<19; i++){
		p[i] = p[i-1]*2;
	}
	for (int i=1; i<=200000; i++){
		for (int j=0; j<19; j++){
			if (p[j] > i) continue;
			dp[i][j] = i-p[j] - dp[i-p[j]][j] + 1;
		}
	}
	while (t--){
		cin >> a >> b;
		ll ans = 0;
		for (int i=0; i<19; i++){
			ans = max(ans, dp[b][i] - dp[a-1][i]);
		}
		cout << b-a+1-ans << '\n';
	}
}