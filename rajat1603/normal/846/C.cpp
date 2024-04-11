#include "bits/stdc++.h"
using namespace std;
const int N = 5005;
const long long inf = 1e15 + 15;
int n;
int arr[N];
long long sum[N];
int idx1[N];
int idx2[N];
int idx3;
long long pre[N];
long long suf[N];
long long ans;
int main(){
	scanf("%d" , &n);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d" , arr + i);
	}
	sum[0] = 0;
	for(int i = 1 ; i <= n ; ++i){
		sum[i] = sum[i - 1] + arr[i];
	}
	pre[0] = 0;
	for(int i = 1 ; i <= n ; ++i){
		pre[i] = -inf;
		for(int j = 0 ; j <= i ; ++j){
			long long tmp = sum[j] - (sum[i] - sum[j]);
			if(pre[i] < tmp){
				pre[i] = tmp;
				idx1[i] = j;
			}
		}
	}
	suf[n + 1] = 0;
	for(int i = n ; i >= 1 ; --i){
		suf[i] = -inf;
		for(int j = i ; j <= n + 1 ; ++j){
			long long tmp = sum[j - 1] - sum[i - 1] - (sum[n] - sum[j - 1]);
			if(suf[i] < tmp){
				suf[i] = tmp;
				idx2[i] = j;
			}
		}
	}
	ans = -inf;
	for(int i = 0 ; i <= n ; ++i){
		long long tmp = pre[i] + suf[i + 1];
		if(ans < tmp){
			ans = tmp;
			idx3 = i;
		}
	}
	printf("%d %d %d\n" , idx1[idx3] , idx3 , idx2[idx3 + 1] - 1);
}