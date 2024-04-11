#include "bits/stdc++.h"
using namespace std;
const int N = 1e3 + 3;
int n;
int x[N] , y[N];
double d;
double dist(int x1 , int y1 , int x2 , int y2){
	long long dx = x2 - x1;
	long long dy = y2 - y1;
	return sqrt(dx * dx + dy * dy);
}
void solve(int x1 , int y1 , int x2 , int y2 , int x3 , int y3){
	double res;
	if(y1 == y3){
		res = max(y2 - y1 , y1 - y2);
	}
	else if(x1 == x3){
		res = max(x2 - x1 , x1 - x2);
	}
	else{
		double m = y3 - y1;
		m /= x3 - x1;
		double c = y1 - m * x1;
		double x = m * (y2 - c) + x2;
		x /= m * m + 1;
		double a = m;
		double b = -1;
		res = a * x2 + b * y2 + c;
		res = max(res , -res);
		res /= sqrt(a * a + b * b);
	}
	d = min(d , res / 2.0);
}
int main(){
	scanf("%d" , &n);
	for(int i = 0 ; i < n ; ++i){
		scanf("%d %d" , x + i , y + i);
	}
	d = 1e15 + 15;
	for(int i = 1 ; i < n ; ++i){
		for(int j = 0 ; j < i ; ++j){
			d = min(d , dist(x[i] , y[i] , x[j] , y[j]) / 2.0);
		}
	}
	for(int i = 0 ; i < n ; ++i){
		solve(x[i] , y[i] , x[(i + 1) % n] , y[(i + 1) % n] , x[(i + 2) % n] , y[(i + 2) % n]);
	}
	printf("%.9lf\n" , d);
}