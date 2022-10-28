#include "bits/stdc++.h"
using namespace std;
const int N = 105;
int n , q , c;
int sum[11][N][N];
int main(){
	scanf("%d %d %d" , &n , &q , &c);
	int x , y , s;
	++c;
	while(n--){
		scanf("%d %d %d" , &x , &y , &s);
		++sum[s][x][y];
	}
	for(int x = 0 ; x < c ; ++x){
		for(int i = 1 ; i < N ; ++i){
			for(int j = 1 ; j < N ; ++j){
				sum[x][i][j] += sum[x][i][j - 1] + sum[x][i - 1][j] - sum[x][i - 1][j - 1];
			}
		}
	}
	int t , x1 , y1 , x2 , y2;
	while(q--){
		scanf("%d %d %d %d %d" , &t , &x1 , &y1 , &x2 , &y2);
		long long ans = 0;
		for(int i = 0 ; i < c ; ++i){
			int cur = (i + t) % c;
			ans += (sum[i][x2][y2] - sum[i][x2][y1 - 1] - sum[i][x1 - 1][y2] + sum[i][x1 - 1][y1 - 1]) * cur;
		}
		printf("%lld\n" , ans);
	}
}