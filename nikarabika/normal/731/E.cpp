//sobskdrbhvk
//remember the flight, the bird dies ):(
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

const int maxn = 2e5 + 85 - 69;
LL dp[maxn],
   a[maxn],
   sum[maxn],
   n;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	for(int i = n - 1; i >= 0; i--)
		sum[i] = sum[i + 1] + a[i];
	LL mx = 0;
	for(int i = n - 1; i > 0; i--){
		dp[i] = sum[0] + mx;
		smax(mx, -(dp[i] + sum[i]));
	}
	cout << dp[1] << '\n';
	return 0;
}