#include "bits/stdc++.h"
using namespace std;
long long xs , ys;
long long xe , ye;
long long v , t;
long long vx , vy;
long long wx , wy;
int main(){
	cin >> xs >> ys;
	cin >> xe >> ye;
	cin >> v >> t;
	cin >> vx >> vy;
	cin >> wx >> wy;
	double l = 0.0;
	double r = 1e8;
	for(int i = 0 ; i < 100 ; ++i){
		double mid = (l + r) / 2;
		double x = xs + min(mid , 1.0 * t) * vx + max(0.0 , mid - t) * wx;
		double y = ys + min(mid , 1.0 * t) * vy + max(0.0 , mid - t) * wy;
		x = abs(xe - x);
		y = abs(ye - y);
		if(x * x + y * y <= v * mid * v * mid){
			r = mid;
		}
		else{
			l = mid;
		}
	}
	printf("%.9lf\n" , l);
}