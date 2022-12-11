#include <bits/stdc++.h>

using namespace std;

typedef long long ll ;
typedef pair<ll, ll> pii;
typedef double db;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int n, s, m, k;
const int N = 1505;

int a[N];
int b[N];
int rig[N];

int dp[N][N];

bool check(int x){
	for(int i = 1; i <= n; i ++ ){
		b[i] = (a[i] <= x);
		b[i] += b[i - 1];
	}
	for(int i = 0 ; i <= n; i ++ )for(int j = 0 ;j  <= m; j ++ )
		dp[i][j] = 0;
	for(int i = 0 ; i < n ; i ++ ){
		for(int j = 0 ; j <= m ; j ++ ){
			dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
			if(rig[i + 1] != 0 && j < m){
				dp[rig[i + 1]][j + 1] = max(dp[rig[i + 1]][j + 1], dp[i][j] + b[rig[i + 1]] - b[i]);
			}
		}
	}
	int answ = 0;
	for(int j = 0 ;j  <= m ; j ++ )answ = max(answ, dp[n][j]);
	return answ >= k;
	
}

int main(){
	fastIO;
	cin >> n >> s >> m >> k;
	for(int i = 1; i <= n; i ++ ){
		cin >> a[i];
	}
	int l, r;
	for(int i = 0 ;i  < s; i ++ ){
		cin >> l >> r;
		rig[l] = max(rig[l], r);
	}
	for(int i = 2; i <= n; i ++ )
		rig[i] = max(rig[i], rig[i - 1]);
	int lf = 0, rf = (int)2e9;
	if(!check(rf)){
		cout << -1 << "\n";
		return 0;
	}
	int md;
	while(lf < rf){
		md = (lf + rf) / 2;
		// <= md
		if(check(md))
			rf = md;
		else
			lf = md + 1;
	}
	cout << rf;
	return 0;
}