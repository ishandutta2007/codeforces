#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
int n , q;
int arr[N];
int nxt[N];
int prv[N];
int l , r;
int main(){
	scanf("%d %d" , &n , &q);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d" , arr + i);
	}
	nxt[n] = n;
	for(int i = n - 1 ; i >= 1 ; --i){
		if(arr[i] <= arr[i + 1]){
			nxt[i] = nxt[i + 1];
		}
		else{
			nxt[i] = i;
		}
	}
	prv[n] = n;
	for(int i = n - 1 ; i >= 1 ; --i){
		if(arr[i + 1] <= arr[i]){
			prv[i] = prv[i + 1];
		}
		else{
			prv[i] = i;
		}
	}
	while(q--){
		scanf("%d %d" , &l , &r);
		if(prv[nxt[l]] >= r){
			printf("Yes\n");
		}
		else{
			printf("No\n");
		}
	}
}