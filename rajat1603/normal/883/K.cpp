#include "bits/stdc++.h"
using namespace std;
const int N = 4e5 + 5;
int n;
int a[N] , b[N];
int ql[N] , qr[N];
long long ans;
int print[N];
int main(){
	scanf("%d" , &n);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d %d" , &a[i] , &b[i]);
		b[i] += a[i];
	}
	ql[1] = a[1];
	qr[1] = b[1];
	for(int i = 2 ; i <= n ; ++i){
		ql[i] = max(ql[i - 1] - 1 , a[i]);
		qr[i] = min(qr[i - 1] + 1 , b[i]);
		if(ql[i] > qr[i]){
			printf("-1\n");
			return 0;
		}
	}
	int cur = qr[n];
	print[n] = cur;
	ans = cur - a[n];
	for(int i = n - 1 ; i >= 1 ; --i){
		cur = min(cur + 1 , qr[i]);
		ans += cur - a[i];
		print[i] = cur;
	}
	printf("%lld\n" , ans);
	for(int i = 1 ; i <= n ; ++i){
		printf("%d%c" , print[i] , " \n"[i == n]);
	}
}