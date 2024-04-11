#include "bits/stdc++.h"
using namespace std;
const int N = 1e3 + 3;
int n , x;
int arr[N];
int cnt[N];
int ans;
int main(){
	scanf("%d %d" , &n , &x);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d" , arr + i);
		cnt[arr[i]] = 1;
	}
	ans = cnt[x];
	for(int i = 0 ; i < x ; ++i){
		ans += !cnt[i];
	}
	printf("%d\n" , ans);
}