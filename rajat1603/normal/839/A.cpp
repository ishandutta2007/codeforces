#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
int n , k;
int arr[N];
int cur;
int main(){
	scanf("%d %d" , &n , &k);
	cur = 0;
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d" , arr + i);
		cur += arr[i];
		int tmp = min(8 , cur);
		k -= tmp;
		cur -= tmp;
		if(k <= 0){
			printf("%d\n" , i);
			return 0;
		}
	}
	printf("-1\n");
}