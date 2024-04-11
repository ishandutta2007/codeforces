#include "bits/stdc++.h"
using namespace std;
const int N = 2e6 + 6;
int n , q;
int arr[N];
int nxt[N];
long long sum[N];
long long b;
int main(){
	scanf("%d %d" , &n , &q);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d" , arr + i);
		sum[i] = sum[i - 1] + arr[i];
	}
	for(int i = 1 ; i <= n ; ++i){
		arr[i + n] = arr[i];
		sum[i + n] = sum[i + n - 1] + arr[i];
	}
	sum[n + n + 1] = 1e17 + 17;
	while(q--){
		scanf("%lld" , &b);
		if(sum[n] <= b){
			printf("1\n");
			continue;
		}
		int ptr = 0;
		int idx = 0;
		int sz = N;
		for(int i = 1 ; i <= n ; ++i){
			while(sum[ptr + 1] - sum[i - 1] <= b){
				++ptr;
			}
			nxt[i] = ptr;
			if(ptr - i + 1 < sz){
				sz = ptr - i + 1;
				idx = i;
			}
		}
		for(int i = 1 ; i <= n ; ++i){
			nxt[i + n] = nxt[i] + n;
		}
		int ans = N;
		for(int i = idx ; i <= idx + sz ; ++i){
			int cnt = 0;
			int cur = i;
			while(cur < i + n){
				++cnt;
				cur = nxt[cur] + 1;
			}
			ans = min(ans , cnt);
		}
		printf("%d\n" , ans);
	}
}