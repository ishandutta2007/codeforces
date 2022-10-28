#include "bits/stdc++.h"
using namespace std;
const int N = 1e6 + 6;
const int mod = 1e9 + 7;
int n;
int arr[N];
int bit[N];
int add(int a , int b){
	int res = a + b;
	if(res >= mod){
		return res - mod;
	}
	return res;
}
int mult(int a , int b){
	long long res = a;
	res *= b;
	if(res >= mod){
		return res % mod;
	}
	return res;
}
int query(int idx){
	int res = 0;
	while(idx){
		res = add(res , bit[idx]);
		idx -= idx & -idx;
	}
	return res;
}
void update(int idx , int val){
	while(idx < N){
		bit[idx] = add(bit[idx] , val);
		idx += idx & -idx;
	}
}
int main(){
	scanf("%d" , &n);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d" , arr + i);
		++arr[i];
	}
	update(1 , 1);
	for(int i = 1 ; i <= n ; ++i){
		update(arr[i] , add(mult(query(arr[i]) , arr[i] - 2) , query(arr[i] - 1)));
	}
	printf("%d\n" , add(query(N - 1) , mod - 1));
}