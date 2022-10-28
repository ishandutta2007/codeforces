#include "bits/stdc++.h"
using namespace std;
const int N = 1e3 + 3;
int n;
int arr[N];
int ans;
int inp;
int q;
int type;
int main(){
	scanf("%d" , &n);
	for(int i = 1 ; i <= n ; ++i){
		for(int j = 1 ; j <= n ; ++j){
			scanf("%d" , &inp);
			if(j == i){
				arr[i] = inp;
				ans ^= inp;
			}
		}
	}
	scanf("%d" , &q);
	while(q--){
		scanf("%d" , &type);
		if(type == 3){
			printf("%d" , ans);
		}
		else{
			scanf("%d" , &inp);
			ans ^= 1;
		}
	}
}