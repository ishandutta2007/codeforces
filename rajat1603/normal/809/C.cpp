#include "bits/stdc++.h"
using namespace std;
const int LN = 30;
const int mod = 1e9 + 7;
int n , m , k;
pair < int , int > dp[LN][2][2][2];
bool calc[LN][2][2][2];
pair < int , int > solve(int pos , bool prea , bool preb , bool prek){
	if(pos < 0){
		return {0 , 1};
	}
	if(calc[pos][prea][preb][prek]){
		return dp[pos][prea][preb][prek];
	}
	int res = 0;
	int resb = 0;
	int diga = (n >> pos) & 1;
	int digb = (m >> pos) & 1;
	int digk = (k >> pos) & 1;
	for(int i = 0 ; i < 2 ; ++i){
		if(!prea && i > diga){
			continue;
		}
		for(int j = 0 ; j < 2 ; ++j){
			if(!preb && j > digb){
				continue;
			}
			bool kbit = i ^ j;
			if(!prek && kbit > digk){
				continue;
			}
			auto it = solve(pos - 1 , prea | (i < diga) , preb | (j < digb) , prek | (kbit < digk));
			res = (res + 1LL * it.second * kbit * (1LL << pos) + it.first) % mod;
			resb += it.second;
			resb -= (resb >= mod) * mod;
		}
	}
	calc[pos][prea][preb][prek] = 1;
	return dp[pos][prea][preb][prek] = {res , resb};
}
int solve(int x , int y , int kk){
	n = x - 1;
	m = y - 1;
	k = kk - 1;
	if(n < 0 || m < 0 || k < 0){
		return 0;
	}
	return solve(LN - 1 , 0 , 0 , k >= 1 << LN).first + solve(LN - 1 , 0 , 0 , k >= 1 << LN).second;
}
int main(){
	int t;
	cin >> t;
	while(t--){
		int x1 , y1 , x2 , y2 , k;
		cin >> x1 >> y1 >> x2 >> y2 >> k;
		long long res = 0;
		for(int i = 0 ; i < LN ; ++i){
			calc[i][0][0][0] = calc[i][0][0][1] = calc[i][0][1][0] = calc[i][0][1][1] = calc[i][1][0][0] = calc[i][1][0][1] = calc[i][1][1][0] = 0;
		}
		res += solve(x2 , y2 , k);
		for(int i = 0 ; i < LN ; ++i){
			calc[i][0][0][0] = calc[i][0][0][1] = calc[i][0][1][0] = calc[i][0][1][1] = 0;
		}
		res -= solve(x1 - 1 , y2 , k);
		for(int i = 0 ; i < LN ; ++i){
			calc[i][0][0][0] = calc[i][0][0][1] = calc[i][1][0][0] = calc[i][1][0][1] = 0;
		}
		res += solve(x1 - 1 , y1 - 1 , k);
		for(int i = 0 ; i < LN ; ++i){
			calc[i][0][0][0] = calc[i][0][0][1] = calc[i][0][1][0] = calc[i][0][1][1] = calc[i][1][1][0] = 0;
		}
		res -= solve(x2 , y1 - 1 , k);
		res %= mod;
		res += mod;
		res %= mod;
		printf("%lld\n" , res);
	}
}