#include "bits/stdc++.h"
using namespace std;
const int N = 2e3 + 3;
int n;
int arr[N];
int pos[N];
int q;
int l , r;
int cur;
int main(){
	scanf("%d" , &n);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d" , arr + i);
		pos[arr[i]] = i;
	}
	for(int i = 1 ; i <= n ; ++i){
		if(arr[i] != i){
			pos[arr[i]] = pos[i];
			swap(arr[i] , arr[pos[i]]);
			pos[i] = i;
			cur ^= 1;
		}
	}
	scanf("%d" , &q);
	while(q--){
		scanf("%d %d" , &l , &r);
		cur ^= (((r - l + 1) * (r - l)) / 2) & 1;
		puts(cur ? "odd" : "even");

	}
}