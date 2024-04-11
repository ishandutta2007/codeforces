#include "bits/stdc++.h"
using namespace std;
const int C = 500;
const int N = 5e4 + 4;
int n , start , x;
int val , nxt;
int arr[N];
int main(){
	srand(clock());
	scanf("%d %d %d" , &n , &start , &x);
	for(int i = 1 ; i <= n ; ++i){
		arr[i] = i;
	}
	random_shuffle(arr + 1 , arr + 1 + n);
	int idx = -1;
	int mx = -1;
	for(int i = 1 ; i <= 999 && i <= n ; ++i){
		printf("? %d\n" , arr[i]);
		fflush(stdout);
		scanf("%d %d" , &val , &nxt);
		if(val <= x){
			if(val > mx){
				mx = val;
				idx = arr[i];
			}
		}
	}
	if(idx == -1){
		idx = start;
	}
	int steps = 0;
	do{
		printf("? %d\n" , idx);
		fflush(stdout);
		scanf("%d %d" , &val , &nxt);
		if(val >= x){
			printf("! %d\n" , val);
			fflush(stdout);
			return 0;
		}
		idx = nxt;
		++steps;
	}
	while(steps < 999 && idx != -1);
	printf("! -1\n");
	fflush(stdout);
}