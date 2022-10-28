#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
const long double eps = 1e-12;
int n;
int botx , boty , topx , topy;
int x[N] , y[N] , vx[N] , vy[N];
pair < long double , long double > solve(int x , int v , int l , int r){
	if(x > r && v >= 0){
		return {-1 , -10};
	}
	if(x < l && v <= 0){
		return {-1 , -10};
	}
	if(x >= l && x <= r){
		long double s = 0;
		long double e;
		if(v == 0){
			if(x == l || x == r){
				return {-1 , -10};
			}
			e = 1e18 + 18;
		}
		else if(v > 0){
			e = (1.0 * (r - x)) / (1.0 * v);
		}
		else{
			e = (1.0 * (x - l)) / (1.0 * (-v));
		}
		return {s , e};
	}
	if(x < l){
		long double s = (1.0 * (l - x)) / (1.0 * v);
		long double e = (1.0 * (r - x)) / (1.0 * v);
		return {s , e};
	}
	if(x > r){
		long double s = (1.0 * (x - r)) / (1.0 * (-v));
		long double e = (1.0 * (x - l)) / (1.0 * (-v));
		return {s , e};
	}
}
int main(){
	scanf("%d" , &n);
	scanf("%d %d %d %d" , &botx , &boty , &topx , &topy);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d %d %d %d" , x + i , y + i , vx + i , vy + i);
	}
	long double l = 0.00000001;
	long double r = 1e18 + 18;
	for(int i = 1 ; i <= n ; ++i){
		pair < long double , long double > xx = solve(x[i] , vx[i] , botx , topx);
		pair < long double , long double > yy = solve(y[i] , vy[i] , boty , topy);
		l = max(l , xx.first);
		l = max(l , yy.first);
		r = min(r , xx.second);
		r = min(r , yy.second);
	}
	if(l + eps < r){
	    double tmp = l;
		printf("%.9lf\n" , tmp);
	}
	else{
		printf("-1\n");
	}
}