#include <bits/stdc++.h>

using namespace std;
typedef long long int li;
typedef pair<int,int> pii;
typedef pair<li,li> pll;
#define mp make_pair
#define pb push_back

li n, m, b, mod = 1e9+7, t;
li ans[200005], dp[200005]; // dp[i] = last b[i] = sum ai at i;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while (t--){
		unordered_map<li, li> ma;
		li sum = 0, sum1;
		cin >> n;
		ans[1] = dp[1] = 1;
		ma[0] = 1;
		for (int i=2; i<=n+1; i++){
			cin >> b;
			if (i==2){
				dp[i] = ans[i] = 1;
				sum += b;
				sum1 = 1;
				continue;
			}
			dp[i] = ans[i-1];
			li y = dp[i];
			li x;
			ans[i] = (2*sum1)%mod;
			if (ma[sum] != 0){
				x = ma[sum];
				ans[i] = (ans[i] - dp[x+1] + mod)%mod;
				sum1 -= dp[x+1];
			}
			ma[sum] = i-1;
			sum += b;
			sum1 = (sum1+y+mod)%mod;
		}
		cout << ans[n+1] << "\n";
	}
}