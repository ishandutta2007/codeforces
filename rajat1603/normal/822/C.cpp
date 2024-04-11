#include "bits/stdc++.h"
using namespace std;
const int N = 2e5 + 5;
int n , x;
int l[N] , r[N] , c[N];
vector < int > lft[N];
vector < int > rgt[N];
int ans;
int cst[N];
int main(){
	scanf("%d %d" , &n , &x);
	memset(cst , -1 , sizeof(cst));
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d %d %d" , l + i , r + i , c + i);
		lft[l[i]].emplace_back(i);
		rgt[r[i]].emplace_back(i);
	}
	ans = 2e9 + 9;
	for(int i = N - 1 ; i >= 1 ; --i){
		for(int j : rgt[i]){
			if(r[j] - l[j] + 1 <= x && cst[x - (r[j] - l[j] + 1)] != -1){
				ans = min(ans , c[j] + cst[x - (r[j] - l[j] + 1)]);
			}
		}
		for(int j : lft[i]){
			if(cst[r[j] - l[j] + 1] == -1){
				cst[r[j] - l[j] + 1] = c[j];
			}
			else{
				cst[r[j] - l[j] + 1] = min(cst[r[j] - l[j] + 1] , c[j]);
			}
		}
	}
	if(ans > 2e9 + 5){
		ans = -1;
	}
	printf("%d\n" , ans);
}