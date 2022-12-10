#include <bits/stdc++.h>

using namespace std;

#define rep(i, t) for(ll (i) = 0; (i) < (ll)(t); (i)++)
#define reu(i, s, e) for(ll (i) = (ll)(s); (i) <= (ll)(e); (i)++)
#define rer(i, s, e) for(ll (i) = (ll)(s); (i) < (ll)(e); (i)++)
#define For(i, v) for(__typeof((v).begin()) (i) = (v).begin(); (i) != (v).end(); (i) ++)
#define mset(arr, val) memset(arr, (val), sizeof arr)
#define pb push_back
#define mp make_pair
#define p1 first
#define p2 second

typedef long long int ll;
typedef pair<int, int> pie;

const int maxn = 100 + 10;
ll D = 1e9 + 7;
ll dp[maxn], pd[maxn];
int n, k, d;

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n >> k >> d;
	dp[0] = 1;
	dp[1] = 1;
	reu(i, 2, n){
		dp[i] = 2 * dp[i - 1];
		if(i > k)
			dp[i] -= dp[i - k - 1];
		dp[i] %= D;
		dp[i] += D;
		dp[i] %= D;
	}
	pd[0] = 1;
	pd[1] = 1;
	if(d == 1)
		pd[1] = 0;
	reu(i, 2, n){
		pd[i] = 2 * pd[i - 1];
		if(i >= d)
			pd[i] -= pd[i - d];
		pd[i] %= D;
		pd[i] += D;
		pd[i] %= D;
	}
	cout << (dp[n] - pd[n] + D) % D << endl;
	return 0;
}