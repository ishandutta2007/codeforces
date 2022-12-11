#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll ;
typedef double db;
typedef pair<int, int> pii;
 
#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

bool dp[25][25];
int c7[25][25];
int c4[25][25];

void solve(){
	for(int i = 0; i < 25; i ++ ){
		for(int j = 0 ; j < 25; j ++ ){
			dp[i][j] = false;
			c7[i][j] = 0;
			c4[i][j] = 0;
		}
	}
	string t;
	cin >> t;
	int n = t.size();
	dp[n][0] = true;
	int dig;
	int sum;
	for(int j = n - 1; j >= 0 ; j -- ){
		dig = t[j] - '0';
		for(int rem = 0; rem <= 20; rem ++ ){
			if(!dp[j + 1][rem])
				continue;
			for(int a4 = 0; a4 <= 6; a4 ++ ){
				for(int a7 = 0; a7 <= 6; a7 ++ ){
					if(a4 + a7 > 6)
						continue;
					sum = rem + a4 * 4 + a7 * 7;
					if(sum % 10 == dig){
						dp[j][sum/10] = true;
						c7[j][sum/10] = a7;
						c4[j][sum/10] = a4;
					}
				}
			}
		}
	}
	if(dp[0][0] == false){
		cout << "-1\n";
		return;
	}
	ll s4[n];
	ll s7[n];
	for(int i = 0 ; i < n; i ++ ){
		s4[i] = 0;
		s7[i] = 0;
	}
	int zd;
	zd = 0;
	for(int i = 0 ; i < n; i ++ ){
		s4[i] = c4[i][zd];
		s7[i] = c7[i][zd];
		zd *= 10;
		zd += t[i] - '0';
		zd -= s4[i] * 4;
		zd -= s7[i] * 7;
	}
	ll p4 = 4ll;
	ll p7 = 7ll;
	ll ret[6];
	for(int t = 0 ;t < 6; t ++ )
		ret[t] = 0;
	for(int i = n-1; i >= 0 ; i -- ){
		for(int t = 0 ; t < s4[i]; t ++ ){
			ret[t] += p4;
		}
		for(int t = s4[i] ; t < s4[i] + s7[i]; t ++ ){
			ret[t] += p7;
		}
		if(i > 0){
			p7 *= 10ll;
			p4 *= 10ll;
		}
	}
	for(int t = 0;t < 6; t ++ )
		cout << ret[t] << " ";
	cout << "\n";
}

int main(){
	fastIO;
	int tes;
	cin >> tes;
	string num;
	for(int i = 0; i < tes; i ++ ){
		solve();
	}
	return 0;
}