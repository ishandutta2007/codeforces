#include "bits/stdc++.h"
using namespace std;
const int N = 1e3 + 3;
const int M = 1e6 + 6;
int n;
int arr[N];
int mark[M];
int val;
int main(){
	scanf("%d" , &n);
	val = -M;
	for(int i = 0 ; i * i < M ; ++i){
		mark[i * i] = 1;
	}
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d" , arr + i);
		if(arr[i] >= 0 && mark[arr[i]]){
			continue;
		}
		val = max(val , arr[i]);
	}
	printf("%d\n" , val);
}