#include "bits/stdc++.h"
using namespace std;
const int N = 2505;
int n;
int x[N] , y[N];
double dp[N][N][2];
double ans;
inline double dist(int i , int j){
	int dx = x[i] - x[j];
	int dy = y[i] - y[j];
	return sqrt(1LL * dx * dx + 1LL * dy * dy);
}
inline void setmax(double &x , double y){
	x = (x < y) ? y : x;
}
int main(){
	scanf("%d" , &n);
	for(int i = 0 ; i < n ; ++i){
		scanf("%d %d" , x + i , y + i);
	}
	for(int i = 0 ; i < n ; ++i){
		dp[i][i][0] = 0;
		dp[i][i][1] = 0;
	}
	for(int siz = 1 ; siz < n ; ++siz){
		for(int i = 0 ; i < n ; ++i){
			int j = (i + siz - 1) % n;
			setmax(dp[i][(j + 1) % n][1] , dp[i][j][0] + dist(i , (j + 1) % n));
			setmax(dp[i][(j + 1) % n][1] , dp[i][j][1] + dist(j , (j + 1) % n));
			setmax(dp[(i + n - 1) % n][j][0] , dp[i][j][0] + dist(i , (i + n - 1) % n));
			setmax(dp[(i + n - 1) % n][j][0] , dp[i][j][1] + dist(j , (i + n - 1) % n));
		}
	}
	ans = 0;
	for(int i = 0 ; i < n ; ++i){
		ans = max(ans , dp[i][(i + n - 1) % n][0]);
	}
	printf("%.12lf\n" , ans);
}