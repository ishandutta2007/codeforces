#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef long double ld;
#define mp make_pair
#define pb push_back
#define nl "\n"
#define all(v) v.begin(),v.end()

ll n, m, q, k, t, a, b, c;
ll arr[100005];
ll dp[105][105][2];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	dp[0][0][0] = 0;
	dp[0][0][1] = 1;
	
	for (int i = 0; i<105; i++){
		for (int j=0; j<105; j++){
			if (i == 0 && j == 0) continue;
			dp[i][j][0] = dp[i][j][1] = 1;
			if (i > 0){
				if (dp[i-1][j][(i-1)%2] == 1) dp[i][j][0] = 0;
				if (dp[i-1][j][i%2] == 1) dp[i][j][1] = 0;
			}
			if (j > 0) {
				if (dp[i][j-1][(i+1)%2] == 1) dp[i][j][0] = 0;
				if (dp[i][j-1][i%2] == 1) dp[i][j][1] = 0;
			}
		}
	}
	
	cin >> t;
	while (t--){
		cin >> n;
		ll cnt[2];
		cnt[0] = cnt[1] = 0;
		for (int i = 0; i<n; i++){
			cin >> a;
			a += 2e9;
			cnt[a%2]++;
		}
		if (dp[cnt[1]][cnt[0]][0] == 0) cout << "Alice\n";
		else cout << "Bob\n";
	}
}