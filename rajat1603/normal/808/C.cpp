#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
int n , w;
pair < int , int > arr[N];
int ans[N];
int pri[N];
int main(){
	scanf("%d %d" , &n , &w);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d" , &arr[i].first);
		arr[i].second = i;
	}
	sort(arr + 1 , arr + 1 + n);
	for(int i = 1 ; i <= n ; ++i){
		ans[i] = arr[i].first + 1 >> 1;
		w -= ans[i];
	}
	if(w < 0){
		printf("-1\n");
		return 0;
	}
	for(int i = n ; i >= 1 && w ; --i){
		if(arr[i].first - ans[i] >= w){
			ans[i] += w;
			w = 0;
		}
		else{
			w -= arr[i].first - ans[i];
			ans[i] = arr[i].first;
		}
	}
	if(w > 0){
		printf("-1\n");
		return 0;
	}
	for(int i = 1 ; i <= n ; ++i){
		pri[arr[i].second] = ans[i];
	}
	for(int i = 1 ; i <= n ; ++i){
		printf("%d%c" , pri[i] , " \n"[i == n]);
	}
}