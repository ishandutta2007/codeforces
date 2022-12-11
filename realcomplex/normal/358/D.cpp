#include <bits/stdc++.h>

using namespace std;

typedef long long ll ;
typedef pair<ll, ll> pii;
typedef double db;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = 3005;

int dp[N][2];

/*
 * 0 - < 
 * 1 - >
 */

void upd(int &a, int b){
	a = max(a, b);
}

int main(){
	fastIO;
	int n;
	cin >> n;
	int a[n], b[n], c[n];
	for(int i = 0 ; i < n; i ++ ) cin >> a[i]; // none
	for(int i = 0 ; i < n; i ++ ) cin >> b[i]; // one
	for(int i = 0 ; i < n; i ++ ) cin >> c[i]; // both
	dp[0][0] = a[0];
	dp[0][1] = b[0];
	for(int i = 1; i < n; i ++ ){
		upd(dp[i][0], dp[i-1][1] + a[i]);
		upd(dp[i][0], dp[i-1][0] + b[i]);
		upd(dp[i][1], dp[i-1][0] + c[i]);
		upd(dp[i][1], dp[i-1][1] + b[i]);
	}
	cout << dp[n-1][0] << "\n";
	return 0;
}