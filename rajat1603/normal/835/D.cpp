#include "bits/stdc++.h"
using namespace std;
const int N = 5e3 + 3;
char str[N];
int n;
int dp[N][N];
int lcp[N][N];
bool pal[N][N];
int ans[N];
int main(){
	scanf("%s" , str + 1);
	n = strlen(str + 1);
	for(int i = n ; i >= 1 ; --i){
		for(int j = n ; j >= 1 ; --j){
			if(str[i] == str[j]){
				lcp[i][j] = lcp[i + 1][j + 1] + 1;
			}
			else{
				lcp[i][j] = 0;
			}
		}
	}
	for(int i = 1 ; i <= n ; ++i){
		dp[i][i] = 1;
		pal[i][i] = 1;
	}
	for(int i = 1 ; i < n ; ++i){
		if(str[i] == str[i + 1]){
			dp[i][i + 1] = 2;
			pal[i][i + 1] = 1;
		}
		else{
			dp[i][i + 1] = 0;
		}
	}
	for(int siz = 3 ; siz <= n ; ++siz){
		for(int i = 1 ; i + siz - 1 <= n ; ++i){
			int j = i + siz - 1;
			if(str[i] == str[j]){
				pal[i][j] = pal[i + 1][j - 1];
			}
			int lft = i;
			int rgt = j - (siz >> 1) + 1;
			if(lcp[lft][rgt] >= (siz >> 1)){
				int x = dp[i][i + (siz >> 1) - 1];
				int y = dp[rgt][j];
				if(x && y){
					dp[i][j] = min(x , y) + 1;
				}
			}
			else{
				dp[i][j] = pal[i][j];
			}
		}
	}
	for(int i = 1 ; i <= n ; ++i){
		for(int j = i ; j <= n ; ++j){
			++ans[dp[i][j]];
		}
	}
	for(int i = n ; i >= 1 ; --i){
		ans[i] += ans[i + 1];
	}
	for(int i = 1 ; i <= n ; ++i){
		printf("%d%c" , ans[i] , " \n"[i == n]);
	}
}