#include "bits/stdc++.h"
using namespace std;
const int N = 35;
int n , l;
long long arr[N];
long long ans , sum;
int main(){
	scanf("%d %d" , &n , &l);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%lld" , arr + i);
	}
	for(int i = 2 ; i <= n ; ++i){
		arr[i] = min(arr[i] , arr[i - 1] << 1);
	}
	for(int i = n + 1 ; i < N ; ++i){
		arr[i] = arr[i - 1] << 1;
	}
	ans = 1LL << 60;
	sum = 0;
	for(int i = N - 2 ; i >= 0 ; --i){
		long long w = 1LL << i;
		if(w >= l){
			ans = min(ans , arr[i + 1] + sum);
		}
		else{
			l -= w;
			sum += arr[i + 1];
		}
	}
	printf("%lld\n" , ans);
}