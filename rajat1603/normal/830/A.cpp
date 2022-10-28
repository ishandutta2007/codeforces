#include "bits/stdc++.h"
using namespace std;
const int N = 2e3 + 3;
int n , k , p;
int a[N];
int b[N];
long long ans;
long long solve(int l , int r){
	long long res = 0;
	for(int i = l ; i <= r ; ++i){
		long long tmp = 0;
		tmp += abs(a[i - l + 1] - b[i]);
		tmp += abs(b[i] - p);
		res = max(res , tmp);
	}
	return res;
}
int main(){
	scanf("%d %d %d" , &n , &k , &p);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d" , a + i);
	}
	for(int i = 1 ; i <= k ; ++i){
		scanf("%d" , b + i);
	}
	sort(a + 1 , a + 1 + n);
	sort(b + 1 , b + 1 + k);
	ans = 1LL << 60;
	for(int i = 1 ; i + n - 1 <= k ; ++i){
		ans = min(ans , solve(i , i + n - 1));
	}
	printf("%lld\n" , ans);
}