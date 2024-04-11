#include "bits/stdc++.h"
using namespace std;
int n , k;
const int arr[5] = {0 , 0 , 1 , 2 , 9};
long long ans;
long long ncr(int n , int r){
	long long prod = 1;
	for(int i = n - r + 1 ; i <= n ; ++i){
		prod *= i;
	}
	for(int i = 1 ; i <= r ; ++i){
		prod /= i;
	}
	return prod;
}
int main(){
	cin >> n >> k;
	ans = 1;
	for(int i = 1 ; i <= k ; ++i){
		ans += ncr(n , i) * arr[i];
	}
	cout << ans << endl;
}