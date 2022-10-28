#include "bits/stdc++.h"
using namespace std;
long long n , l , v1 , v2 , k;
bool check(double busdist){
	int times = (n + k - 1) / k;
	double humans = 0;
	for(int i = 0 ; i < times ; ++i){
		double newd = humans + busdist;
		if(newd > l){
			return 0;
		}
		double nhumans = humans + (busdist / v2) * v1;
		double dist = newd - nhumans;
		dist /= v1 + v2;
		humans = nhumans + v1 * dist;
	}
	return 1;
}
int main(){
	cin >> n >> l >> v1 >> v2 >> k;
	double L = 0.0;
	double R = 1e10;
	for(int i = 0 ; i < 100 ; ++i){
		double mid = (L + R) / 2;
		if(check(mid)){
			L = mid;
		}
		else{
			R = mid;
		}
	}
	printf("%.9lf\n" , (L / v2) + (l - R) / v1);
}