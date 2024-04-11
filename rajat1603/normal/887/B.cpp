#include "bits/stdc++.h"
using namespace std;
const int N = 10;
int n;
int arr[N][10];
set < int > s;
int ans;
int main(){
	scanf("%d" , &n);
	for(int i = 1 ; i <= n ; ++i){
		for(int j = 0 ; j < 6 ; ++j){
			scanf("%d" , &arr[i][j]);
		}
	}
	for(int i = 1 ; i <= n ; ++i){
		for(int j = 0 ; j < 6 ; ++j){
			s.insert(arr[i][j]);
		}
	}
	for(int i = 1 ; i <= n ; ++i){
		for(int x = 1 ; x <= n ; ++x){
			if(x == i){
				continue;
			}
			for(int j = 0 ; j < 6 ; ++j){
				for(int k = 0 ; k < 6 ; ++k){
					s.insert(arr[i][j] * 10 + arr[x][k]);
				}
			}
		}
	}
	if(n == 3){
		for(int i = 0 ; i < 6 ; ++i){
			for(int j = 0 ; j < 6 ; ++j){
				for(int k = 0 ; k < 6 ; ++k){
					s.insert(arr[1][i] * 100 + arr[2][j] * 10 + arr[3][k]);
					s.insert(arr[1][i] * 100 + arr[2][j] + arr[3][k] * 10);
					s.insert(arr[1][i] * 10 + arr[2][j] * 100 + arr[3][k]);
					s.insert(arr[1][i] * 10 + arr[2][j] + arr[3][k] * 100);
					s.insert(arr[1][i]+ arr[2][j] * 100 + arr[3][k] * 10);
					s.insert(arr[1][i]+ arr[2][j] * 10 + arr[3][k] * 100);
				}
			}
		}
	}
	for(int i = 1 ; ; ++i){
		if(s.find(i) == s.end()){
			break;
		}
		ans = i;
	}
	printf("%d\n" , ans);
}