#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
int n , m;
int l , r;
int arr[N];
int dp1[N];
int dp2[N];
int bit1[N];
int bit2[N];
void update1(int idx , int val){
	if(!idx){
		bit1[0] = max(bit1[0] , val);
		++idx;
	}
	while(idx <= n){
		bit1[idx] = max(bit1[idx] , val);
		idx += idx & -idx;
	}
}
int query1(int idx){
	int res = bit1[0];
	while(idx){
		res = max(res , bit1[idx]);
		idx -= idx & -idx;
	}
	return res;
}
void update2(int idx , int val){
	if(!idx){
		bit2[0] = max(bit2[0] , val);
	}
	while(idx){
		bit2[idx] = max(bit2[idx] , val);
		idx -= idx & -idx;
	}
}
int query2(int idx){
	int res = 0;
	if(!idx){
		res = max(res , bit2[idx]);
		++idx;
	}
	while(idx <= n){
		res = max(res , bit2[idx]);
		idx += idx & -idx;
	}
	return res;
}
int main(){
	scanf("%d %d" , &n , &m);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d %d" , &l , &r);
		++arr[l];
		--arr[r + 1];
	}
	for(int i = 1 ; i <= m ; ++i){
		arr[i] += arr[i - 1];
	}
	for(int i = m ; i >= 1 ; --i){
		dp2[i] = 1 + query1(arr[i]);
		dp1[i] = max(query2(arr[i]) + 1 , dp2[i]);
		update1(arr[i] , dp2[i]);
		update2(arr[i] , dp1[i]);
	}
	printf("%d\n" , query2(0));
}