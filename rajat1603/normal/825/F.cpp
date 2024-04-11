#include "bits/stdc++.h"
using namespace std;
const int N = 8e3 + 3;
int n;
char str[N];
int lcp[N];
int dp[N];
int dig[N];
void calc(int idx){
	lcp[idx - 1] = idx - 1;
	lcp[idx] = idx - 1;
	for(int i = idx + 1 ; i <= n ; ++i){
		int tmp = lcp[i - 1];
		while(1){
			if(str[tmp + 1] == str[i]){
				lcp[i] = tmp + 1;
				break;
			}
			if(tmp == idx - 1){
				lcp[i] = idx - 1;
				break;
			}
			tmp = lcp[tmp];
		}
	}
}
int main(){
	scanf("%s" , str + 1);
	n = strlen(str + 1);
	dig[0] = 0;
	for(int i = 1 ; i <= n ; ++i){
		dig[i] = dig[i / 10] + 1;
	}
	dp[n + 1] = 0;
	for(int i = n ; i >= 1 ; --i){
		calc(i);
		int period;
		int res = 1e9;
		for(int j = i ; j <= n ; ++j){
			period = j - lcp[j];
			if((j - i + 1) % period){
				period = j - i + 1;
			}
			res = min(res , period + dig[(j - i + 1) / period] + dp[j + 1]);
		}
		dp[i] = res;
	}
	printf("%d\n" , dp[1]);
}