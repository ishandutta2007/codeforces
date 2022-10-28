#include "bits/stdc++.h"
using namespace std;
int n , l , m;
const int mod = 1e9 + 7;
vector < int > v;
vector < int > mult(vector < int > a , vector < int > b){
	vector < int > res;
	res.clear();
	res.resize(m , 0);
	for(int i = 0 ; i < m ; ++i){
		for(int j = 0 ; j < m ; ++j){
			res[(i + j) % m] = (res[(i + j) % m] + 1LL * a[i] * b[j]) % mod;
		}
	}
	return res;
}
vector < int > power(vector < int > a , int b){
	vector < int > res;
	res.clear();
	res.resize(m , 0);
	res[0] = 1;
	while(b){
		if(b & 1){
			res = mult(res , a);
		}
		a = mult(a , a);
		b >>= 1;
	}
	return res;
}
vector < int > top;
const int N = 1e6 + 6;
int arr[N];
int bot[N];
int main(){
	scanf("%d %d %d" , &n , &l , &m);
	top.clear();
	top.resize(m , 0);
	for(int i = 0 ; i < n ; ++i){
		int idx;
		scanf("%d" , &idx);
		idx %= m;
		++top[idx];
	}
	v.clear();
	v.resize(m , 0);
	for(int i = 0 ; i < n ; ++i){
		int idx;
		scanf("%d" , &idx);
		idx %= m;
		++v[idx];
		arr[i] = idx;
	}
	for(int i = 0 ; i < n ; ++i){
		int idx;
		scanf("%d" , &idx);
		idx %= m;
		bot[i] = idx;
	}
	auto it = mult(top , power(v , l - 2));
	int ans = 0;
	for(int i = 0 ; i < n ; ++i){
		int tmp = (arr[i] + bot[i]) % m;
		int need = (m - tmp) % m;
		ans = (ans + it[need]) % mod;
	}
	printf("%d\n" , ans);
}