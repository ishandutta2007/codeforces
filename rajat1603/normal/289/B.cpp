#include "bits/stdc++.h"
using namespace std;
const int N = 1e4 + 4;
int n , m , d , ans;
int arr[N];
int main(){
	scanf("%d %d %d" , &n , &m , &d);
	n *= m;
	for(int i = 0 ; i < n ; ++i){
		scanf("%d" , arr + i);
	}
	for(int i = 1 ; i < n ; ++i){
		if((arr[i] % d) != (arr[0] % d)){
			printf("-1\n");
			return 0;
		}
	}
	for(int i = 0 ; i < n ; ++i){
		arr[i] /= d;
	}
	sort(arr , arr + n);
	for(int i = 0 ; i < n ; ++i){
		ans += abs(arr[i] - arr[n >> 1]);
	}
	printf("%d\n" , ans);
}