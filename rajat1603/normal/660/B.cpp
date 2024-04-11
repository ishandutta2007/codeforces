#include "bits/stdc++.h"
using namespace std;
const int N = 105;
int arr[N][5];
int n , m;
int cur;
void print(int num){
	if(num <= m && num >= 1){
		printf("%d " , num);
	}
}
int main(){
	cin >> n >> m;
	cur = 0;
	memset(arr , 0 , sizeof(arr));
	for(int i = 1 ; i <= n ; ++i){
		arr[i][1] = ++cur;
		arr[i][4] = ++cur;
	}
	for(int i = 1 ; i <= n ; ++i){
		arr[i][2] = ++cur;
		arr[i][3] = ++cur;
	}
	for(int i = 1 ; i <= n ; ++i){
		print(arr[i][2]);
		print(arr[i][1]);
		print(arr[i][3]);
		print(arr[i][4]);
	}
}