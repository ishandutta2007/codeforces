#include "bits/stdc++.h"
using namespace std;
const int N = 1e6 + 6;
int n;
int arr[N];
int lst[N];
long long ans;
long long sum;
int main(){
	scanf("%d" , &n);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d" , arr + i);
		lst[arr[i]] = n + 1;
	}
	ans = 0;
	sum = 0;
	for(int i = n ; i >= 1 ; --i){
		sum += lst[arr[i]] - i;
		lst[arr[i]] = i;
		ans += sum * 2 - 1;
	}
	printf("%.9lf\n" , 1.0 * ans / (1LL * n * n));
}