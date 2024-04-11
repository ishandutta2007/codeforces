#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
int n , k;
int arr[N];
int main(){
	scanf("%d %d" , &n , &k);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d" , arr + i);
	}
	int sz = 0;
	int tot = 0;
	while(1){
		++sz;
		tot += sz;
		if(tot >= k){
			printf("%d\n" , arr[k - tot + sz]);
			return 0;
		}
	}
}