//sobskdrbhvk
//remember the flying, the bird dies ):(
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

const int maxn = 1e6 + 85 - 69;
int dp[maxn];
string s;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> s;
	s = '*' + s;
	int mn;
	mn = dp[0] = 0;
	for(int i = 1; i < sz(s); i++){
		if(s[i] == '0'){
			dp[i] = dp[i - 1];
			mn++;
			smin(mn, dp[i]);
		}
		else{
			dp[i] = min(1 + dp[i - 1], 2 + mn);
			smin(mn, dp[i]);
		}
	}
	cout << dp[sz(s) - 1] << '\n';
	return 0;
}