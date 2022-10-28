#include "bits/stdc++.h"
using namespace std;
int n , k , x;
int arr;
int ans;
int main(){
	scanf("%d %d %d" , &n , &k , &x);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d" , &arr);
		if(i >= n - k + 1){
			arr = x;
		}
		ans += arr;
	}
	printf("%d\n" , ans);
}