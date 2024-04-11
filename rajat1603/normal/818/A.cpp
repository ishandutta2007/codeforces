#include "bits/stdc++.h"
using namespace std;
long long n , k;
bool check(long long val){
	return val <= (n >> 1);
}
int main(){
	cin >> n >> k;
	long long l = 0;
	long long r = n / (k + 1);
	while(l < r){
		long long mid = l + r + 1 >> 1;
		if(check((k + 1LL) * mid)){
			l = mid;
		}
		else{
			r = mid - 1;
		}
	}
	cout << l << " " << l * k << " " << n - (k + 1LL) * l << endl;
}