#include "bits/stdc++.h"
using namespace std;
int t;
long long n;
bool check1(long long mid){
	long long edges = 0;
	edges += n - 1;
	edges += (mid * (mid - 1LL)) >> 1;
	long long bridges = n - 1LL - ((mid == 1) ? 0 : mid);
	return bridges * 2LL >= edges;
}
int main(){
	scanf("%d" , &t);
	while(t--){
		scanf("%lld" , &n);
		long long l = 1;
		long long r = n - 1;
		while(l < r){
			long long mid = l + r + 1 >> 1;
			if(check1(mid)){
				l = mid;
			}
			else{
				r = mid - 1;
			}
		}
		long long edges = 0;
		edges += n - 1LL;
		edges += (l * (l - 1LL)) >> 1;
		long long bridges = n - 1 - ((l == 1) ? 0 : l);
		long long ql = 0;
		long long qr = l - 1;
		while(ql < qr){
			long long mid = ql + qr + 1 >> 1;
			long long ed = edges + mid;
			long long br = bridges - (mid > 0);
			if(br * 2LL >= ed){
				ql = mid;
			}
			else{
				qr = mid - 1;
			}
		}
		printf("%lld\n" , edges + ql);
	}
}