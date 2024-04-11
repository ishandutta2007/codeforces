#include "bits/stdc++.h"
using namespace std;
const int N = 2e5 + 5;
int n , q;
int arr[N];
int idx[N];
vector < int > v[N];
vector < pair < int , int > > vq[N];
int ans[N];
int l , r;
int bit[N];
void update(int idx){
	while(idx){
		++bit[idx];
		idx -= idx & -idx;
	}
}
int query(int idx){
	int res = 0;
	while(idx <= n){
		res += bit[idx];
		idx += idx & -idx;
	}
	return res;
}
int main(){
	scanf("%d %d" , &n , &q);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d" , arr + i);
		idx[arr[i]] = i;
	}
	for(int i = 1 ; i <= n ; ++i){
		for(int j = arr[i] ; j <= n ; j += arr[i]){
			l = min(i , idx[j]);
			r = max(i , idx[j]);
			v[r].emplace_back(l);
		}
	}
	for(int i = 1 ; i <= q ; ++i){
		scanf("%d %d" , &l , &r);
		vq[r].emplace_back(make_pair(l , i));
	}
	for(int i = 1 ; i <= n ; ++i){
		for(int x : v[i]){
			update(x);
		}
		for(auto it : vq[i]){
			ans[it.second] = query(it.first);
		}
	}
	for(int i = 1 ; i <= q ; ++i){
		printf("%d\n" , ans[i]);
	}
}