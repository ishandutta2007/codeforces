#include "bits/stdc++.h"
using namespace std;
const int N = 2e5 + 5;
int h;
int arr[N];
void solve(int k){
	printf("0");
	int cur = 1;
	int lst = 1;
	for(int i = 1 ; i <= h ; ++i){
		for(int j = 0 ; j < arr[i] ; ++j){
			printf(" %d" , lst);
		}
		lst = cur + 1;
		cur += arr[i];
	}
	printf("\n");
	printf("0");
	cur = 1;
	lst = 1;
	for(int i = 1 ; i <= k ; ++i){
		for(int j = 0 ; j < arr[i] ; ++j){
			printf(" %d" , lst);
		}
		lst = cur + 1;
		cur += arr[i];	
	}
	printf(" %d" , lst + 1);
	for(int j = 1 ; j < arr[k + 1] ; ++j){
		printf(" %d" , lst);
	}
	lst = cur + 1;
	cur += arr[k + 1];
	for(int i = k + 2 ; i <= h ; ++i){
		for(int j = 0 ; j < arr[i] ; ++j){
			printf(" %d" , lst);
		}
		lst = cur + 1;
		cur += arr[i];	
	}
	printf("\n");
}
int main(){
	scanf("%d" , &h);
	for(int i = 0 ; i <= h ; ++i){
		scanf("%d" , arr + i);
	}
	for(int i = 1 ; i < h ; ++i){
		if(arr[i] > 1 && arr[i + 1] > 1){
			printf("ambiguous\n");
			solve(i);
			return 0;
		}
	}
	printf("perfect\n");
}