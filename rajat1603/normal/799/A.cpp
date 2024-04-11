#include "bits/stdc++.h"
using namespace std;
long long n , t , k , d;
bool check(long long mx){
	long long tot = 0;
	tot += (mx / t) * k;
	mx -= d;
	if(mx > 0){
		tot += (mx / t) * k;
	}
	return tot >= n;
}
int main(){
	cin >> n >> t >> k >> d;
	long long t1 = (n + k - 1) / k;
	t1 *= t;
	if(check(t1 - 1)){
		printf("YES\n");
	}
	else{
		printf("NO\n");
	}
}