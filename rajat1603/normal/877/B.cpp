#include "bits/stdc++.h"
using namespace std;
const int N = 1e4 + 4;
char str[N];
int n;
int dp[N][5];
int solve(int pos , int phase){
	if(pos > n){
		return 0;
	}
	if(dp[pos][phase] != -1){
		return dp[pos][phase];
	}
	int res = 0;
	res = max(res , solve(pos + 1 , phase));
	if(phase == 1 || phase == 3){
		if(str[pos] == 'a'){
			res = max(res , 1 + solve(pos + 1 , phase));
		}
	}
	if(phase == 2){
		if(str[pos] == 'b'){
			res = max(res , 1 + solve(pos + 1 , phase));
		}
	}
	if(phase < 3){
		res = max(res , solve(pos , phase + 1));
	}
	return dp[pos][phase] = res;
}
int main(){
	scanf("%s" , str + 1);
	n = strlen(str + 1);
	memset(dp , -1 , sizeof(dp));
	printf("%d\n" , solve(1 , 1));
}