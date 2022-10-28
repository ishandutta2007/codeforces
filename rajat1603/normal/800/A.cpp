#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
int n , p;
int a[N] , b[N];
bool check(double t){
	double tot = 0;
	for(int i = 1 ; i <= n ; ++i){
		double tmp = t * a[i] - b[i];
		if(tmp >= 0){
			tot += tmp / p;
		}
	}
	return tot <= t;
}
int main(){
	scanf("%d %d" , &n , &p);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d %d" , a + i , b + i);
	}
	double l = 0;
	double r = 5e18 + 18;
	if(check(r + 10)){
		printf("-1\n");
		return 0;
	}
	for(int i = 0 ; i < 100 ; ++i){
		double mid = (l + r) / 2;
		if(check(mid)){
			l = mid;
		}
		else{
			r = mid;
		}
	}
	printf("%.9lf\n" , (l + r) / 2);
}