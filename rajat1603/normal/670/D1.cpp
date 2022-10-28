#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
int n , k;
int a[N];
int b[N];
bool check(int val){
	long long kleft = k;
	for(int i = 1 ; i <= n ; ++i){
		long long co = 1LL * a[i] * val;
		kleft -= max(0LL , co - b[i]);
		if(kleft < 0){
			return 0;
		}
	}
	return 1;
}
int main(){
	scanf("%d %d" , &n , &k);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d" , a + i);
	}
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d" , b + i);
	}
	int l = 1;
	int r = 2e9 + 9;
	while(l < r){
		unsigned mid = l + r;
		mid >>= 1;
		if(check(mid)){
			l = mid + 1;
		}
		else{
			r = mid;
		}
	}
	printf("%d\n" , l - 1);
}