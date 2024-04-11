#include <bits/stdc++.h>

using namespace std;

typedef long long ll ;
typedef pair<ll, int> pii;
typedef double db;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = 1005;
ll d1[N][N];
ll d2[N][N];
ll d3[N][N];
ll d4[N][N];
int f[N][N];

int n, m;

void calc(){
	for(int tes = 0 ; tes < 1 ; tes++ ){
		for(int i = 1; i <= n; i ++ ){
			for(int j = 1; j <= m ; j ++ ){
				d1[i][j] = max(d1[i - 1][j], d1[i][j - 1]) + f[i][j];
			}
		}
		for(int i = n; i >= 1; i -- ){
			for(int j = m; j >= 1; j -- ){
				d2[i][j] = max(d2[i + 1][j], d2[i][j + 1]) + f[i][j];
			}
		}
		for(int i = n; i >= 1; i -- ){
			for(int j = 1; j <= m; j ++ ){
				d3[i][j] = max(d3[i + 1][j], d3[i][j - 1]) + f[i][j];
			}
		}
		for(int i = 1; i <= n; i ++ ){
			for(int j = m ; j >= 1; j -- ){
				d4[i][j] = max(d4[i - 1][j], d4[i][j + 1]) + f[i][j];
			}
		}
	}
}

int main(){
	fastIO;
	cin >> n >> m;
	for(int i = 1; i <= n; i ++ )
		for(int j = 1; j <= m ; j ++ )
			cin >> f[i][j];
	calc();
	ll answ = 0;
	for(int i = 2; i < n; i ++ ){
		for(int j = 2; j < m ; j ++ ){
			answ = max(answ, d1[i - 1][j] + d2[i + 1][j] + d3[i][j - 1] + d4[i][j + 1]);
			answ = max(answ, d1[i][j - 1] + d2[i][j + 1] + d3[i + 1][j] + d4[i - 1][j]);
		}
	}
	cout << answ << "\n";
	return 0;
}