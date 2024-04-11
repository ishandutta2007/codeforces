#include "bits/stdc++.h"
using namespace std;
const int N = 3e5 + 5;
int n , k;
int arr[N];
int mxans = 0;
int mxl;
int mxr;
int cur;
int l;
int main(){
	scanf("%d %d" , &n , &k);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d" , arr + i);
	}
	l = 1;
	for(int i = 1 ; i <= n ; ++i){
		if(arr[i] == 0){
			++cur;
		}
		while(cur > k){
			if(arr[l] == 0){
				--cur;
			}
			++l;
		}
		if(i - l + 1 > mxans){
			mxans = i - l + 1;
			mxl = l;
			mxr = i;
		}
	}
	printf("%d\n" , mxans);
	if(mxans == 0){
		mxl = 0;
		mxr = 0;
	}
	for(int i = mxl ; i <= mxr ; ++i){
		if(arr[i] == 0){
			arr[i] = 1;
		}
	}
	for(int i = 1 ; i <= n ; ++i){
		printf("%d " , arr[i]);
	}
}