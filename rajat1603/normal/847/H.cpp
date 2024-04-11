#include "bits/stdc++.h"
using namespace std;
const int N = 2e5 + 5;
int n;
int arr[N];
long long preval[N];
long long sufval[N];
int pre[N];
int suf[N];
long long ans;
int main(){
	scanf("%d" , &n);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d" , arr + i);
	}
	pre[0] = 0;
	preval[0] = 0;
	for(int i = 1 ; i <= n ; ++i){
		preval[i] = preval[i - 1];
		if(arr[i] > pre[i - 1]){
			pre[i] = arr[i];
		}
		else{
			pre[i] = pre[i - 1] + 1;
			preval[i] += pre[i] - arr[i];
		}
	}
	suf[n + 1] = 0;
	sufval[n + 1] = 0;
	for(int i = n ; i >= 1 ; --i){
		sufval[i] = sufval[i + 1];
		if(arr[i] > suf[i + 1]){
			suf[i] = arr[i];
		}
		else{
			suf[i] = suf[i + 1] + 1;
			sufval[i] += suf[i] - arr[i];
		}
	}
	ans = 1LL << 61;
	for(int i = 1 ; i <= n ; ++i){
		long long tmp = 0;
		tmp += preval[i];
		tmp += sufval[i + 1];
		if(pre[i] == suf[i + 1]){
			++tmp;
		}
		ans = min(ans , tmp);
	}
	printf("%lld\n" , ans);
}