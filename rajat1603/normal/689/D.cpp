#include "bits/stdc++.h"
using namespace std;
const int N = 2e5 + 5;
const int LN = 18;
int n;
int a[N];//max
int b[N];//min
int st1[LN][N];
int st2[LN][N];
int logtable[N];
long long ans;
void pre(){
	logtable[1] = 0;
	for(int i = 2 ; i <= n ; ++i){
		logtable[i] = logtable[i >> 1] + 1;
	}
	for(int i = 1 ; i <= n ; ++i){
		st1[0][i] = a[i];
	}
	for(int i = 1 ; i < LN ; ++i){
		for(int j = 1 ; j + (1 << i) - 1 <= n ; ++j){
			st1[i][j] = max(st1[i - 1][j] , st1[i - 1][j + (1 << (i - 1))]);
		}
	}
	for(int i = 1 ; i <= n ; ++i){
		st2[0][i] = b[i];
	}
	for(int i = 1 ; i < LN ; ++i){
		for(int j = 1 ; j + (1 << i) - 1 <= n ; ++j){
			st2[i][j] = min(st2[i - 1][j] , st2[i - 1][j + (1 << (i - 1))]);
		}
	}
	ans = 0;
}
int getmax(int l , int r){
	int k = logtable[r - l + 1];
	return max(st1[k][l] , st1[k][r - (1 << k) + 1]);
}
int getmin(int l , int r){
	int k = logtable[r - l + 1];
	return min(st2[k][l] , st2[k][r - (1 << k) + 1]);
}
void solve(int idx){
	if(getmax(idx , idx) > getmin(idx , idx)){
		return;
	}
	if(getmax(idx , n) < getmin(idx , n)){
		return;
	}
	int l = idx;
	int r = n;
	while(l < r){
		int mid = l + r >> 1;
		if(getmax(idx , mid) >= getmin(idx , mid)){
			r = mid;
		}
		else{
			l = mid + 1;
		}
	}
	if(getmax(idx , l) > getmin(idx , l)){
		return;
	}
	int start = l;
	l = idx;
	r = n;
	if(getmax(idx , n) == getmin(idx , n)){
		l = n + 1;
		r = n + 1;
	}
	else{
		while(l < r){
			int mid = l + r >> 1;
			if(getmax(idx , mid) > getmin(idx , mid)){
				r = mid;
			}
			else{
				l = mid + 1;
			}
		}
	}
	int finish = l - 1;
	ans += finish - start + 1;
}
int main(){
	scanf("%d" , &n);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d" , a + i);
	}
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d" , b + i);
	}
	pre();
	for(int i = 1 ; i <= n ; ++i){
		solve(i);
	}
	printf("%lld\n" , ans);
}