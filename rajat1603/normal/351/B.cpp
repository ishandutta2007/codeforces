#include "bits/stdc++.h"
using namespace std;
const int N = 3e3 + 3;
int n;
int arr[N];
int bit[N];
void update(int idx){
	while(idx <= n){
		++bit[idx];
		idx += idx & -idx;
	}
}
int query(int idx){
	int res = 0;
	while(idx){
		res += bit[idx];
		idx -= idx & -idx;
	}
	return res;
}
int ans;
int main(){
	scanf("%d" , &n);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d" , arr + i);
	}
	for(int i = n ; i >= 1 ; --i){
		ans += query(arr[i] - 1);
		update(arr[i]);
	}
	printf("%d\n" , ans * 2 - (ans & 1));
}