//sobskdrbhvk
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define sz(x) ((int)(x).size())
#define smax(x, y) ((x) = max((x), (y)))
#define smin(x, y) ((x) = min((x), (y)))
#define all(x) x.begin(),x.end()

const int maxn = 1e5 + 85 - 69;
LL a[maxn],
   su[maxn],
   dp[maxn];
int n;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 1; i < n; i++)
		cin >> a[i];
	for(int i = n - 1; i > 0; i--){
		su[i] = su[i + 1] + a[i] - (a[i]&1);
		if(a[i] == 1) su[i] = 0;
	}
	dp[0] = 0;
	LL sum = 0, ans = 0;
	for(int i = 1; i < n; i++){
		sum += a[i] - (a[i]&1);
		if(a[i] == 1) sum = 0;
		dp[i] = max(dp[i - 1] + a[i] - (a[i] % 2 == 0), sum);
		ans = max(ans, dp[i] + su[i + 1]);
	}
	cout << ans << endl;
	return 0;
}