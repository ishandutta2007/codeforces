#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef long double ld;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define TEST freopen("in.txt","r",stdin);
#define ab(a) ((a < 0) ? (-(a)) : (a))

const ll MOD  =(ll)1e9 + 7;
const int V = 200999;
const int S = V * 2;

ll dp[S];
ll nex[S];
ll rem[S];

void init(){
	for(int i = 0;i<S;i++)
		dp[i] = nex[i] % MOD,nex[i] = 0,rem[i] = 0;
}

int main(){
	fastIO;
	int a,b,k,t;
	cin >> a >> b >> k >> t;
	dp[a-b + V] = 1;
	int li,ri;
	li = a-b;
	ri = a-b;
	int ix;
	int c;
	while(t-- ){
		for(int i = li;i<=ri;i++){
			ix = i + V;
			nex[ix] += 2 * (k + 1) * dp[ix];
			rem[ix] += -dp[ix];
			rem[ix + 2*k + 2] += dp[ix];
			// second part
			c = i - (2*k);
			c += V;
			nex[ix] -= dp[ix] * 2 * k;
			rem[c] += dp[ix];
			rem[ix] -= dp[ix];
		}
		for(int i = 1;i<S;i++)rem[i] += rem[i-1];
		li -= 2 * k;
		ri += 2 * k;
		for(int i = 1;i<S;i++)
			nex[i] += nex[i-1] + rem[i];
		for(int i = 0;i<S;i++)
			dp[i] = nex[i] % MOD,nex[i] = 0,rem[i] = 0;
	}
	ll ans = 0;
	for(int i = V+1;i<S;i++){
		ans += dp[i];
		ans %= MOD;
	}
	cout << ans << "\n";
	return 0;
}