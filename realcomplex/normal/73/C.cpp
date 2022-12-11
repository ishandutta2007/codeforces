#include <bits/stdc++.h>

using namespace std;

typedef long long ll ;
typedef pair<ll, int> pii;
typedef double db;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = 105;
const int AL = 26;
int dp[N][N][AL];

int f[AL][AL];

int main(){
	fastIO;
	string t;
	cin >> t;
	int k;
	cin >> k;
	char ai, bi;
	int c;
	int m;
	cin >> m;
	for(int i = 0; i < m ; i ++ ){
		cin >> ai >> bi >> c;
		f[ai - 'a'][bi - 'a'] = c;
	}
	for(int j = 0 ; j < N ; j ++ )
		for(int x = 0 ; x < N; x ++ )
			for(int t = 0 ; t < AL; t ++ )
				dp[j][x][t] = -(int)1e9;
	int vl = t[0] - 'a';
	for(int x = 0 ;x < AL ; x ++ ){
		dp[0][(x != vl)][x] = 0;
	}
	int op;
	for(int i = 1; i < t.size(); i ++ ){
		vl = t[i] - 'a';
		for(int x = 0 ; x <= k; x ++ ){
			for(int l = 0; l < AL; l ++ ){
				for(int r = 0; r < AL ; r ++ ){
					op = (vl != r) + x;
					if(op>k)
						continue;
					dp[i][op][r] = max(dp[i][op][r], dp[i - 1][x][l] + f[l][r]);
				}
			}
		}
	}
	int answ = -(int)1e9 ;
	for(int i = 0 ; i <= k ; i ++ ){
		for(int j = 0; j < AL ;j ++ ){
			answ = max(answ, dp[(int)t.size() - 1][i][j]);
		}
	}
	cout << answ << "\n";
	return 0;
}