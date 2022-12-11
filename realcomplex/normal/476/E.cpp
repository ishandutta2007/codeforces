#include <bits/stdc++.h>

using namespace std;

typedef long long ll ;
typedef pair<int, int> pii;
typedef double db;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = 2005;

int answ[N];

void upd(int &a, int b){
	a = min(a, b);
}

int main(){
	fastIO;
	int n, m;
	string s, t;
	cin >> s >> t;
	n = s.size();
	m = t.size();
	s = '#' + s;
	t = '#' + t;
	if(n < m){
		for(int j = 0 ; j <= n; j ++ )
			cout << 0 << " ";
		return 0;
	}
	int k = n/m;
	int dp[n + 1][m][k + 1];
	for(int i = 0 ; i <= n ; i ++ )for(int j = 0 ; j < m ; j ++ )for(int z = 0 ;z <= k ; z ++ )
		dp[i][j][z] = 15579;
	dp[0][0][0] = 0;
	int nx;
	int sm;
	for(int i = 0 ; i < n ; i ++ ){
		for(int l = 0 ;l <= k; l++ ){
			for(int j = 1 ; j < m; j ++ ){
				upd(dp[i + 1][j][l], dp[i][j][l] + 1);
				if(s[i + 1] == t[j + 1]){
					nx = j + 1;
					sm = l;
					if(nx == m){
						nx = 0, sm ++ ;
					}
					if(sm <= k){
						upd(dp[i + 1][nx][sm], dp[i][j][l]);
					}
				}
			}
			
			// j == 0  
			upd(dp[i + 1][0][l], dp[i][0][l]);
			if(s[i + 1] == t[1]){
				if(m==1){	
					if(l + 1 <= k)upd(dp[i + 1][0][l + 1], dp[i][0][l]);
				}
				else{
					upd(dp[i + 1][1][l], dp[i][0][l]);
				}
			}
		}
	}
	int lbound, rbound;
	int rem;
	for(int j = k; j >= 1; j -- ){
		lbound = dp[n][0][j];
		rbound = n - m * j;
		for(int t = lbound ; t <= rbound ; t ++ ){
			answ[t] = max(answ[t], j);
		}
	}
	for(int i = 0 ; i <= n; i ++ ){
		cout << answ[i] << " ";
	}
	return 0;
}