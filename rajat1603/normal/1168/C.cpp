#include "bits/stdc++.h"
using namespace std;
const int N = 3e5 + 5;
const int LN = 19;
int n , q;
int arr[N];
int dp[N][LN];
int nxt[LN];
int main(){
	scanf("%d %d" , &n , &q);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d" , arr + i);
	}
	for(int i = 0 ; i < LN ; ++i){
		dp[n+1][i] = n + 1;
		nxt[i] = n + 1;
	}
	for(int i = n ; i >= 1 ; --i){
		vector < int > ones;
		ones.clear();
		for(int j = 0 ; j < LN ; ++j){
			if((arr[i] >> j) & 1){
				ones.push_back(j);
			}
		}
		for(int j = 0 ; j < LN ; ++j){
			if((arr[i] >> j) & 1){
				dp[i][j] = i;
			}
			else{
				int idx = n + 1;
				for(int k : ones){
					idx = min(idx , dp[nxt[k]][j]);
				}
				dp[i][j] = idx;
			}
		}
		for(int j : ones){
			nxt[j] = i;
		}
	}
	while(q--){
		int a , b;
		scanf("%d %d" , &a , &b);
		bool ans = 0;
		for(int j = 0 ; j < LN ; ++j){
			if((arr[b] >> j) & 1){
				ans |= dp[a][j] <= b;
			}
		}
		printf(ans ? "Shi\n" : "Fou\n");
	}
}