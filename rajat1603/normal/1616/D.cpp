#include "bits/stdc++.h"
using namespace std;
const int N = 5e4 + 4;
const int inf = 1e7 + 7;
int t;
int n;
int arr[N];
int x;
int dp[N][2][2];
int main(){
	scanf("%d" , &t);
	while(t--){
		scanf("%d" , &n);
		for(int i = 2 ; i <= n + 1 ; ++i){
			scanf("%d" , arr + i);
		}
		scanf("%d" , &x);
		for(int i = 0 ; i < 4 ; ++i){
			dp[n + 2][i >> 1][i & 1] = 0;
		}
		for(int pos = n + 1 ; pos >= 2 ; --pos){
			for(int slast = 0 ; slast < 2 ; ++slast){
				for(int last = 0 ; last < 2 ; ++last){
					dp[pos][slast][last] = dp[pos + 1][last][0] + 1;
					int sval = slast ? arr[pos - 2] - x : inf;
					int lval = last ? arr[pos - 1] - x : inf;
					if(arr[pos] + lval >= x && arr[pos] + lval + sval >= x){
						dp[pos][slast][last] = min(dp[pos][slast][last] , dp[pos + 1][last][1]);
					}
				}
			}
		}
		printf("%d\n" , n - dp[2][0][0]);
	}
}