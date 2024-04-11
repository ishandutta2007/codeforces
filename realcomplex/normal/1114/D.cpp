#include <bits/stdc++.h>

using namespace std;

typedef long long ll ;
typedef pair<ll, ll> pii;
typedef double db;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = 5005;

int dp[N][N];

int main(){
	fastIO;
	int n;
	cin >> n;
	vector<int> t;
	int l, c;
	l = 0;
	for(int i = 0 ;i < n; i ++ ){
		cin >> c;
		if(l != c)
			t.push_back(c);
		l = c;
	}
	int m = t.size();
	for(int i = 0 ; i < m ; i ++ ){
		for(int j = 0 ; j <m  ;j ++ )
			dp[i][j] = 2141425;
	}
	for(int i = 0 ; i < m ; i ++ ){
		dp[i][i] = 0;
	}
	int r;
	for(int sz = 2; sz <= m ; sz ++ ){
		for(int i = 0 ;i < m ; i ++ ){
			l = i;
			r = i + sz -  1;
			if(r > m)
			    continue;
			if(sz > 2 && t[l] == t[r]){
				dp[l][r] = min(dp[l][r], dp[l + 1][r - 1] + 1);
			}
			dp[l][r] = min(dp[l][r], dp[l + 1][r] + 1);
			dp[l][r] = min(dp[l][r], dp[l][r - 1] +  1);
		}
	}
	cout << dp[0][m  - 1] << "\n";
	return 0;
}