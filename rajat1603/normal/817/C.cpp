#include "bits/stdc++.h"
using namespace std;
const int N = 19;
const int S = 9 * 19 + 5;
long long n , s;
long long ans;
long long dp1[N][S][2];
long long dp2[N][S][2];
string a , b;
long long solve(int pos , bool pre , int sum , long long dp[N][S][2] , const string &num){
	if(sum < 0){
		return 0;
	}
	if(pos >= num.size()){
		return sum == 0;
	}
	if(dp[pos][sum][pre] != -1){
		return dp[pos][sum][pre];
	}
	long long res = 0;
	int dig = num[pos] - '0';
	for(int i = 0 ; i < 10 ; ++i){
		if(!pre && i > dig){
			break;
		}
		res += solve(pos + 1 , pre | (i < dig) , sum - i , dp , num);
	}
	return dp[pos][sum][pre] = res;
}
long long solve(long long l , long long r , int sum){
	if(l > r){
		return 0;
	}
	b = to_string(r);
	a = to_string(l - 1);
	memset(dp2 , -1 , sizeof(dp2));
	return solve(0 , 0 , sum , dp1 , b) - solve(0 , 0 , sum , dp2 , a);
}
int main(){
	cin >> n >> s;
	ans = 0;
	memset(dp1 , -1 , sizeof(dp1));
	for(int i = 1 ; i < S ; ++i){
		ans += solve(s + i , n , i);
	}
	printf("%lld\n" , ans);
}