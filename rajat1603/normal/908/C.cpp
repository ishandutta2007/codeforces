#include "bits/stdc++.h"
using namespace std;
const int N = 2e3 + 3;
int n , r;
int x[N];
double y[N];
void solve(int idx){
	double res = r;
	for(int i = 1 ; i < idx ; ++i){
		int dx = abs(x[idx] - x[i]);
		if(dx > 2 * r){
			continue;
		}
		if(dx == 2 * r){
			res = max(res , y[i]);
			continue;
		}
		double dy = sqrt(4LL * r * r - 1LL * dx * dx);
		res = max(res , y[i] + dy);
	}
	y[idx] = res;
}
int main(){
	scanf("%d %d" , &n , &r);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d" , x + i);
	}
	for(int i = 1 ; i <= n ; ++i){
		solve(i);
		printf("%.9lf%c" , y[i] , " \n"[i == n]);
	}
}