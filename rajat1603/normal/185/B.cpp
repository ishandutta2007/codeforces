#include "bits/stdc++.h"
using namespace std;
const long double eps = 1e-9;
const long double inf = 1e15;
int s;
int a , b , c;
long double ans = -inf;
long double px , py , pz;
long double solve2(long double x , long double y , long double z){
	long double ret = a * log(x) + b * log(y) + c * log(z);
	if(ret > ans){
		ans = ret;
		px = x;
		py = y;
		pz = z;
	}
	return ret;
}
long double solve(double val){
	long double lft = s - val - eps;
	long double l = eps;
	long double r = lft;
	long double ret = -inf;
	for(int i = 0 ; i < 100 ; ++i){
		long double mid1 = (l + l + r) / 3;
		long double mid2 = (l + r + r) / 3;
		long double val1 = solve2(mid1 , lft - mid1 , val);
		long double val2 = solve2(mid2 , lft - mid2 , val);
		if(val1 >= val2){
			r = mid2;
		}
		else{
			l = mid1;
		}
		ret = max(ret , max(val1 , val2));
	}
	return ret;
}
int main(){
	cin >> s;
	cin >> a >> b >> c;
	if(a == b && b == c){
		px = s / 3.0;
		py = s / 3.0;
		pz = s / 3.0;
	}
	else{
		long double l = eps;
		long double r = s - eps;
		for(int i = 0 ; i < 100 ; ++i){
			long double mid1 = (l + l + r) / 3;
			long double mid2 = (l + r + r) / 3;
			long double val1 = solve(mid1);
			long double val2 = solve(mid2);
			if(val1 >= val2){
				r = mid2;
			}
			else{
				l = mid1;
			}
		}
	}
	cout << fixed << setprecision(12) << px << " " << py << " " << pz << endl;
}