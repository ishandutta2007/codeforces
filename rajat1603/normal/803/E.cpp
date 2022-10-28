#include "bits/stdc++.h"
using namespace std;
const int N = 1e3 + 3;
int n , k;
char str[N];
int dp[N][N + N];
bool solve(int pos , int sum){
	if(pos > n){
		return max(sum , -sum) == k;
	}
	if(max(sum , -sum) == k){
		return 0;
	}
	if(dp[pos][sum + n] != -1){
		return dp[pos][sum + n];
	}
	if(str[pos] == '?'){
		for(int i = -1 ; i <= 1 ; ++i){
			if(solve(pos + 1 , sum + i)){
				return dp[pos][sum + n] = 1;
			}
		}
		return dp[pos][sum + n] = 0;
	}
	else{
		return dp[pos][sum + n] = solve(pos + 1 , sum + (str[pos] == 'W' ? 1 : (str[pos] == 'L' ? -1 : 0)));
	}
}
void go(int pos , int sum){
	if(pos <= n){
		if(str[pos] == '?'){
			for(int i = -1 ; i <= 1 ; ++i){
				if(solve(pos + 1 , sum + i)){
					printf("%c" , "LDW "[i + 1]);
					go(pos + 1 , sum + i);
					return;
				}
			}
		}
		else{
			printf("%c" , str[pos]);
			go(pos + 1 , sum + (str[pos] == 'W' ? 1 : (str[pos] == 'L' ? -1 : 0)));
		}
	}
}
int main(){
	scanf("%d %d" , &n , &k);
	scanf("%s" , str + 1);
	memset(dp , -1 , sizeof(dp));
	if(solve(1 , 0)){
		go(1 , 0);
	}
	else{
		printf("NO\n");
	}
}