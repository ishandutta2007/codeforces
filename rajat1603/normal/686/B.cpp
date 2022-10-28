#include "bits/stdc++.h"
using namespace std;
const int N = 105;
int n;
int arr[N];
int main(){
	scanf("%d" , &n);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d" , arr + i);
	}
	for(int i = 1 ; i < n ; ++i){
		for(int j = 1 ; j < n ; ++j){
			if(arr[j] > arr[j + 1]){
				swap(arr[j] , arr[j + 1]);
				printf("%d %d\n" , j , j + 1);
			}
		}
	}
}