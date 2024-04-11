#include "bits/stdc++.h"
using namespace std;
const int N = 2e5 + 5;
int n , k;
int arr[N];
long long sum[N];
long long tot;
int main(){
	tot = 0;
	scanf("%d %d" , &n , &k);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d" , arr + i);
		sum[i] = sum[i - 1] + arr[i];
	}
	for(int i = 1 ; i + k - 1 <= n ; ++i){
		tot += sum[i + k - 1] - sum[i - 1];
	}
	printf("%.9lf\n" , 1.0 * tot / (n - k + 1.0));
}