#include "bits/stdc++.h"
using namespace std;
const int N = 2e5 + 5;
int n;
long long k;
int arr[N];
inline long long mult(long long a , long long b){
	if(a == 0 || b == 0){
		return 0;
	}
	if(a >= (k + b - 1) / b){
		return k;
	}
	return min(k , a * b);
}
inline long long add(long long a , long long b){
	return min(a + b , k);
}
long long get(long long cur , long long n , long long r){
	long long a = cur;
	long long b = n + 1;
	long long c = r + 1;
	if(a >= k){
		return k;
	}
	long long g = __gcd(a , c);
	a /= g;
	c /= g;
	g = __gcd(b , c);
	b /= g;
	c /= g;
	return mult(a , b);
}
bool check(long long row){
	long long res = 0;
	long long cur = 1;
	long long nn = row - 1;
	long long rr = 0;
	for(int i = 0 ; i < n && res < k ; ++i){
		res = add(res , mult(arr[n - i] , cur));
		cur = get(cur , nn , rr);
		++nn;
		++rr;
	}
	return res >= k;
}
int main(){
	scanf("%d %lld" , &n , &k);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d" , &arr[i]);
		if(arr[i] >= k){
			printf("%lld\n" , 0LL);
			return 0;
		}
	}
	long long l = 1;
	long long r = k + 5;
	while(l < r){
		long long mid = l + r >> 1;
		if(check(mid)){
			r = mid;
		}
		else{
			l = mid + 1;
		}
	}
	printf("%lld\n" , l);
}