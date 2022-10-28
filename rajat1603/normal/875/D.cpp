#include "bits/stdc++.h"
using namespace std;
const int N = 2e5 + 5;
const int LN = 30;
int n;
int arr[N];
int lft[N];
int rgt[N];
int pre[N][LN];
int suf[N][LN];
stack < int > s;
long long ans;
int main(){
	scanf("%d" , &n);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d" , arr + i);
	}
	for(int i = 1 ; i <= n ; ++i){
		for(int j = 0 ; j < LN ; ++j){
			if((arr[i] >> j) & 1){
				pre[i][j] = i;
			}
			else{
				pre[i][j] = pre[i - 1][j];
			}
		}
	}
	for(int i = 0 ; i < LN ; ++i){
		suf[n + 1][i] = n + 1;
	}
	for(int i = n ; i >= 1 ; --i){
		for(int j = 0 ; j < LN ; ++j){
			if((arr[i] >> j) & 1){
				suf[i][j] = i;
			}
			else{
				suf[i][j] = suf[i + 1][j];
			}
		}
	}
	while(!s.empty()){
		s.pop();
	}
	arr[0] = 2e9 + 9;
	s.push(0);
	for(int i = 1 ; i <= n ; ++i){
		while(arr[s.top()] <= arr[i]){
			s.pop();
		}
		lft[i] = s.top() + 1;
		s.push(i);
	}
	while(!s.empty()){
		s.pop();
	}
	arr[n + 1] = 2e9 + 9;
	s.push(n + 1);
	for(int i = n ; i >= 1 ; --i){
		while(arr[s.top()] < arr[i]){
			s.pop();
		}
		rgt[i] = s.top() - 1;
		s.push(i);
	}
	ans = 1LL * n * (n + 1LL);
	ans /= 2;
	for(int i = 1 ; i <= n ; ++i){
		int l = 1;
		int r = n;
		for(int j = 0 ; j < LN ; ++j){
			if(!((arr[i] >> j) & 1)){
				l = max(l , pre[i][j] + 1);
				r = min(r , suf[i][j] - 1);
			}
		}
		ans -= 1LL * (i - max(lft[i] , l) + 1LL) * (min(rgt[i] , r) - i + 1LL);
	}
	printf("%lld\n" , ans);
}