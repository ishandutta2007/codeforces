#include "bits/stdc++.h"
using namespace std;
const int N = 1e6 + 6;
const int LN = 20;
int n , k;
int arr1[N];
int arr2[N];
int st1[LN][N];
int st2[LN][N];
int logtable[N];
int val[N];
double ans = 0.0;
double cur;
inline int query1(int l , int r){
	int k = logtable[r - l + 1];
	return max(st1[k][l] , st1[k][r - (1 << k) + 1]);
}
inline int query2(int l , int r){
	int k = logtable[r - l + 1];
	return min(st2[k][l] , st2[k][r - (1 << k) + 1]);	
}
inline int get(int i , int j){
	return min(query1(i , j) , query2(i , j));
}
inline int solve(int pos){
	if(query1(pos , pos) >= query2(pos , pos)){
		return query2(pos , pos);
	}
	if(query2(pos , n) >= query1(pos , n)){
		return query1(pos , n);
	}
	int l = pos;
	int r = n;
	while(l < r){
		int mid = l + r >> 1;
		if(query1(pos , mid) < query2(pos , mid)){
			l = mid + 1;
		}
		else{
			r = mid;
		}
	}
	return max(get(pos , l) , get(pos , max(l - 1 , pos)));
}
int main(){
	scanf("%d %d" , &n , &k);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d" , arr1 + i);
		st1[0][i] = arr1[i] * 100;
	}
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d" , arr2 + i);
		st2[0][i] = arr2[i];
	}
	logtable[1] = 0;
	for(int i = 2 ; i <= n ; ++i){
		logtable[i] = logtable[i >> 1] + 1;
	}
	for(int i = 1 ; i < LN ; ++i){
		for(int j = 1 ; j + (1 << i) - 1 <= n ; ++j){
			st1[i][j] = max(st1[i - 1][j] , st1[i - 1][j + (1 << (i - 1))]);
			st2[i][j] = min(st2[i - 1][j] , st2[i - 1][j + (1 << (i - 1))]);
		}
	}
	for(int i = 1 ; i <= n ; ++i){
		val[i] = solve(i);
	}
	sort(val + 1 , val + 1 + n);
	cur = 1.0 * k / n;
	for(int i = 1 ; i <= n ; ++i){
		if(n - i < k - 1){
			break;
		}
		ans += val[i] * cur;
		cur *= 1.0 * (n - i - k + 1) / (n - i);
	}
	printf("%.9lf\n" , ans);
}