#include "bits/stdc++.h"
using namespace std;
const int N = 405;
int n;
char str[N][N];
set < int > s[N][N];
int siz[N];
int lft[N];
int rgt[N];
int arr[N + N];
int cursize;
void getlast(int idx , int req){
	if(idx <= n){
		if(siz[idx] <= req){
			for(int j = 1 ; j <= siz[idx] ; ++j){
				arr[++cursize] = str[idx][j] - '0';
			}
		}
		else{
			for(int j = siz[idx] - req + 1 ; j <= siz[idx] ; ++j){
				arr[++cursize] = str[idx][j] - '0';
			}
		}
		return;
	}
	if(siz[rgt[idx]] >= req){
		getlast(rgt[idx] , req);
	}
	else{
		getlast(lft[idx] , req - siz[rgt[idx]]);
		getlast(rgt[idx] , siz[rgt[idx]]);
	}
}
void getfirst(int idx , int req){
	if(idx <= n){
		for(int j = 1 ; j <= min(req , siz[idx]) ; ++j){
			arr[++cursize] = str[idx][j] - '0';
		}
		return;
	}
	if(siz[lft[idx]] >= req){
		getfirst(lft[idx] , req);
	}
	else{
		getfirst(lft[idx] , siz[lft[idx]]);
		getfirst(rgt[idx] , req - siz[lft[idx]]);
	}
}
int kmps[N * 3];
int lcp[N * 3];
int dp[N][1 << 11][11];
bool there(int idx , int mask , int k){
	if(dp[idx][mask][k] != -1){
		return dp[idx][mask][k];
	}
	if(idx <= n){
		return s[idx][k].find(mask) != s[idx][k].end();
	}
	if(there(lft[idx] , mask , k) || there(rgt[idx] , mask , k)){
		return 1;
	}
	cursize = 0;
	getlast(lft[idx] , k - 1);
	getfirst(rgt[idx] , k - 1);
	for(int i = 0 ; i < k ; ++i){
		kmps[i + 1] = (mask >> (k - 1 - i)) & 1;
	}
	kmps[k + 1] = 2;
	int sz = k + 1;
	for(int i = 1 ; i <= cursize ; ++i){
		kmps[++sz] = arr[i];
	}
	lcp[0] = 0;
	lcp[1] = 0;
	for(int i = 2 ; i <= sz ; ++i){
		lcp[i] = 0;
		int idx = lcp[i - 1];
		while(1){
			if(kmps[idx + 1] == kmps[i]){
				lcp[i] = idx + 1;
				break;
			}
			else{
				if(idx == 0){
					break;
				}
				idx = lcp[idx];
			}
		}
	}
	for(int i = k + 2 ; i <= sz ; ++i){
		if(lcp[i] == k){
			return dp[idx][mask][k] = 1;
		}
	}
	return dp[idx][mask][k] = 0;
}
bool check(int idx , int k){
	for(int i = 0 ; i < (1 << k) ; ++i){
		if(!there(idx , i , k)){
			return 0;
		}
	}
	return 1;
}
void solve(int idx){
	int l = 1;
	int r = 10;
	while(l < r){
		int mid = l + r >> 1;
		if(check(idx , mid)){
			l = mid + 1;
		}
		else{
			r = mid;
		}
	}
	printf("%d\n" , l - 1);
}
int main(){
	scanf("%d" , &n);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%s" , str[i] + 1);
		siz[i] = strlen(str[i] + 1);
	}
	for(int i = 1 ; i <= n ; ++i){
		int m = siz[i];
		for(int j = 1 ; j <= m ; ++j){
			int mask = 0;
			for(int k = j ; k <= m && k - j + 1 <= 10 ; ++k){
				mask <<= 1;
				mask += str[i][k] - '0';
				s[i][k - j + 1].insert(mask);
			}
		}
	}
	memset(dp , -1 , sizeof(dp));
	int q;
	scanf("%d" , &q);
	for(int i = n + 1 ; i <= n + q ; ++i){
		int a , b;
		scanf("%d %d" , &a , &b);
		lft[i] = a;
		rgt[i] = b;
		siz[i] = siz[a] + siz[b];
		siz[i] = min(siz[i] , N);
		solve(i);
	}
}