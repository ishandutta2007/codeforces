#include "bits/stdc++.h"
using namespace std;
const int N = 2e3 + 3;
int n , m , c;
int val;
int idx;
int arr[N];
void solveleft(int val){
	for(int i = 1 ; i <= n ; ++i){
		if(arr[i] == -1 || arr[i] > val){
			arr[i] = val;
			idx = i;
			return;
		}
	}
	arr[n] = val;
	idx = n;
}
void solveright(int val){
	for(int i = n ; i >= 1 ; --i){
		if(arr[i] == -1 || arr[i] < val){
			arr[i] = val;
			idx = i;
			return;
		}
	}
	arr[1] = val;
	idx = 1;
}
void solve(int val){
	if(val <= (c >> 1)){
		solveleft(val);
	}
	else{
		solveright(val);
	}
}
void check(){
	for(int i = 1 ; i <= n ; ++i){
		if(arr[i] == -1){
			return;
		}
	}
	exit(0);
}
int main(){
	memset(arr , - 1 , sizeof(arr));
	scanf("%d %d %d" , &n , &m , &c);
	for(int i = 1 ; i <= m ; ++i){
		scanf("%d" , &val);
		solve(val);
		printf("%d\n" , idx);
		fflush(stdout);
		check();
	}
}