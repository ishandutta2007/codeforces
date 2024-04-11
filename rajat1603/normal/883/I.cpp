#include "bits/stdc++.h"
using namespace std;
const int N = 5e5 + 5;
int n , k;
int arr[N];
int nxt[N];
int qr[N];
bool check(int mid){
	int ptr = n;
	for(int i = n ; i >= 1 ; --i){
		while(arr[ptr] - arr[i] > mid){
			--ptr;
		}
		qr[i] = ptr;
	}
	nxt[n + 1] = n + 1;
	for(int i = n ; i >= 1 ; --i){
		int start = i + k - 1;
		int finish = qr[i];
		if(start > finish){
			nxt[i] = nxt[i + 1];
		}
		else{
			if(nxt[start + 1] <= finish + 1){
				nxt[i] = i;
			}
			else{
				nxt[i] = nxt[i + 1];
			}
		}
	}
	return nxt[1] == 1;
}
int main(){
	scanf("%d %d" , &n , &k);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d" , &arr[i]);
	}
	sort(arr + 1 , arr + 1 + n);
	int l = 0;
	int r = 1e9 + 9;
	while(l < r){
		int mid = l + r >> 1;
		if(check(mid)){
			r = mid;
		}
		else{
			l = mid + 1;
		}
	}
	printf("%d\n" , l);
}