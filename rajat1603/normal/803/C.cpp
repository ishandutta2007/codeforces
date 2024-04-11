#include "bits/stdc++.h"
using namespace std;
long long n , k;
void solve(long long g){
	long long sum = n / g;
	if(1LL * k * (k + 1LL) <= sum * 2LL){
		for(int i = 1 ; i < k ; ++i){
			printf("%lld " , g * i);
			n -= g * i;
		}
		printf("%lld\n" , n);
		exit(0);
	}
}
int main(){
	cin >> n >> k;
	if(k > 1e7){
		printf("-1\n");
		return 0;
	}
	int last;
	for(int i = 1 ; 1LL * i * i <= n ; ++i){
		if(n % i == 0){
			solve(n / i);
		}
		last = i;
	}
	for(int i = last ; i >= 1 ; --i){
		if(n % i == 0){
			solve(i);
		}
	}
	printf("-1\n");
}