#include "bits/stdc++.h"
using namespace std;
const int N = 2e5 + 5;
int n;
int arr[N];
int ans;
int lst[N];
int val[N];
int main(){
	scanf("%d" , &n);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d" , arr + i);
	}
	memset(lst , -1 , sizeof(lst));
	ans = 1;
	val[0] = 1;
	lst[1] = 0;
	for(int i = 1 ; i <= n ; ++i){
		if(lst[val[arr[i]]] == arr[i]){
			val[i] = val[arr[i]];
			lst[val[i]] = i;
		}
		else{
			val[i] = ++ans;
			lst[val[i]] = i;
		}
	}
	printf("%d\n" , ans);
}