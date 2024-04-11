#include "bits/stdc++.h"
using namespace std;
long long m;
bool check(long long n , bool print){
	long long ret = 0;
	for(int i = 2 ; ; ++i){
		long long tmp = n / (1LL * i * i * i);
		if(!tmp){
			break;
		}
		ret += tmp;
	}
	if(print){
		if(ret == m){
			printf("%lld\n" , n);
		}
		else{
			printf("-1\n");
		}
	}
	return (ret >= m);
}
int main(){
	cin >> m;
	long long l = 1;
	long long r = 1e18;
	while(l < r){
		long long mid = l + r >> 1;
		if(check(mid , 0)){
			r = mid;
		}
		else{
			l = mid + 1;
		}
	}
	check(l + r >> 1 , 1);
}