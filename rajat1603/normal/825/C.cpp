#include "bits/stdc++.h"
using namespace std;
const int N = 1e3 + 5;
int n , k;
int arr[N];
int ans;
int main(){
	scanf("%d %d" , &n , &k);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d" , arr + i);
	}
	sort(arr + 1 , arr + 1 + n);
	for(int i = 1 ; i <= n ; ++i){
		while(k + k < arr[i]){
			k += k;
			++ans;
		}
		k = max(k , arr[i]);
	}
	printf("%d\n" , ans);
}