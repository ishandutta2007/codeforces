#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;
typedef double db;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define all(x) ((x).begin(),(x).end())
#define len(x) ((ll)(x).size())

const ll MOD = 998244353;
const int N = 20;
const int MASK = 1 << 10;

ll dp[N][MASK][2]; // number of ways
ll dp2[N][MASK][2];

string to_str(ll y){
	string ans;
	do{
		ans.push_back(char(y % 10 + '0'));
		y /= 10;
	}while(y > 0);
	reverse(ans.begin(), ans.end());
	return ans;
}

ll add(ll x, ll y){
	x += y;
	if(x >= MOD)
		x -= MOD;
	if(x < 0)
		x += MOD;
	return x;
}

ll multi(ll x, ll y){
	return (1ll * x * y) % MOD;
}

int popcount(int mask){
	return __builtin_popcount(mask);
}

int k;


ll Calc(string t){
	memset(dp, 0ll, sizeof dp);
	memset(dp2, 0ll, sizeof dp2);
	dp[0][0][0] = 1;
	int nx_mask;
	int dig;
	ll ad;
	ll ad1;
	for(int i = 0 ; i < (int)t.size() ; i ++ ){
		dig = t[i] - '0';
		for(int mask = 0 ; mask < MASK; mask ++ ){
			for(int nx = (i == 0); nx < 10; nx ++ ){
				nx_mask = (mask | (1 << nx));
				if(popcount(nx_mask) > k)
					continue;
				if(nx < dig){
					// 0 -> 1
					// 1 -> 1
					ad = add(dp[i][mask][0], dp[i][mask][1]);
					ad1 = add(dp2[i][mask][0], dp2[i][mask][1]);
					dp[i + 1][nx_mask][1] = add(dp[i + 1][nx_mask][1], ad);
					dp2[i + 1][nx_mask][1] = add(dp2[i + 1][nx_mask][1],
					add(multi(nx, ad), multi(ad1, 10)));

				}
				else if(nx == dig){
					// 0 -> 0
					// 1 -> 1
					ad = dp[i][mask][0];
					ad1 = dp2[i][mask][0];
					dp[i + 1][nx_mask][0] = add(dp[i + 1][nx_mask][0], ad);
					dp2[i + 1][nx_mask][0] = add(dp2[i + 1][nx_mask][0],
					add(multi(nx, ad), multi(ad1, 10)));
					/* && ! && */
					ad = dp[i][mask][1];
					ad1 = dp2[i][mask][1];
					dp[i + 1][nx_mask][1] = add(dp[i + 1][nx_mask][1], ad);
					dp2[i + 1][nx_mask][1] = add(dp2[i + 1][nx_mask][1],
					add(multi(nx, ad), multi(ad1, 10)));
				}
				else{
					// 1 -> 1
					ad = dp[i][mask][1];
					ad1 = dp2[i][mask][1];
					dp[i + 1][nx_mask][1] = add(dp[i + 1][nx_mask][1], ad);
					dp2[i + 1][nx_mask][1] = add(dp2[i + 1][nx_mask][1],
					add(multi(nx, ad), multi(ad1, 10)));
				}
			}
		}
	}
	int n = t.size();
	ll ret = 0ll;
	for(int mk = 0; mk < MASK; mk ++ ){
		if(popcount(mk) <= k)
			ret = add(ret, add(dp2[n][mk][0], dp2[n][mk][1]));
	}
	return ret;
}

ll full_calc(string t){
	ll ret = Calc(t);
	string py;
	for(int i = 1; i < t.size(); i ++ ){
		py.push_back('9');
		ret = add(ret, Calc(py));
	}
	return ret;
}

int main(){
	fastIO;
	ll l, r;
	cin >> l >> r >> k;
	string al, ar;
	al = to_str(l - 1);
	ar = to_str(r);
	cout << (full_calc(ar) - full_calc(al) + MOD) % MOD << "\n";
	return 0;
}