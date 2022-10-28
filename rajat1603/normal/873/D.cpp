#include "bits/stdc++.h"
using namespace std;
const int N = 3e5 + 5;
int n , k;
int arr[N];
int siz;
void solve(int l , int r , int ql , int qr , int k){
	if(2 * (r - l) - 1 < k){
		printf("-1\n");
		exit(0);
	}
	if(!(k & 1)){
		printf("-1\n");
		exit(0);
	}
	if(k == 1){
		for(int i = l ; i < r ; ++i){
			arr[++siz] = ql + (i - l);
		}
		return;
	}
	--k;
	int mid = l + r >> 1;
	int lft = 2 * (mid - l) - 1;
	if(lft >= k - 1){
		solve(l , mid , qr - (mid - l) + 1 , qr , k - 1);
		solve(mid , r , ql , qr - (mid - l) , 1);
	}
	else{
		solve(l , mid , qr - (mid - l) + 1 , qr , lft);
		solve(mid , r , ql , qr - (mid - l) , k - lft);
	}
}
int main(){
	scanf("%d %d" , &n , &k);
	siz = 0;
	solve(0 , n , 1 , n , k);
	for(int i = 1 ; i <= n ; ++i){
		printf("%d%c" , arr[i] , " \n"[i == n]);
	}
}