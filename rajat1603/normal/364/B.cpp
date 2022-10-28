#include "bits/stdc++.h"
using namespace std;
const int N = 55;
const int MAX = 1e4 + 4;
int n , d;
int arr[N];
bitset < MAX * N > dp;
int mxans , steps;
int main(){
	scanf("%d %d" , &n , &d);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d" , arr + i);
	}
	dp.set(0);
	for(int i = 1 ; i <= n ; ++i){
		dp |= dp << arr[i];
	}
	while(1){
		int val = min(mxans + d , MAX * N - 1);
		bool rekt = 1;
		for(int j = val ; j > mxans ; --j){
			if(dp.test(j)){
				rekt = 0;
				mxans = j;
				++steps;
				break;
			}
		}
		if(rekt){
			break;
		}
	}
	printf("%d %d\n" , mxans , steps);
}