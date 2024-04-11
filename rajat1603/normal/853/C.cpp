#include "bits/stdc++.h"
using namespace std;
const int N = 2e5 + 5;
int n , q;
int col[N];
int l[N] , d[N] , r[N] , u[N];
vector < int > v[N];
long long cnt[N];
int bit[N];
void update(int idx){
	while(idx <= n){
		++bit[idx];
		idx += idx & -idx;
	}
}
int query(int idx){
	int res = 0;
	while(idx){
		res += bit[idx];
		idx -= idx & -idx;
	}
	return res;
}
long long c2(int x){
	return (1LL * x * (x - 1LL)) / 2LL;
}
int main(){
	scanf("%d %d" , &n , &q);
	for(int i = 1 ; i <= n ; ++i){
		int row;
		scanf("%d" , &row);
		col[row] = i;
	}
	for(int i = 1 ; i <= q ; ++i){
		scanf("%d %d %d %d" , l + i , d + i , r + i , u + i);
		v[u[i] + 1].emplace_back(i);
	}
	for(int i = n ; i >= 1 ; --i){
		update(col[i]);
		for(int idx : v[i]){
			cnt[idx] += c2(query(n) - query(r[idx]));
			cnt[idx] += c2(query(l[idx] - 1));
		}
	}
	memset(bit , 0 , sizeof(bit));
	for(int i = 1 ; i <= n ; ++i){
		v[i].clear();
	}
	for(int i = 1 ; i <= q ; ++i){
		v[d[i] - 1].emplace_back(i);
	}
	for(int i = 1 ; i <= n ; ++i){
		update(col[i]);
		for(int idx : v[i]){
			cnt[idx] += c2(query(n) - query(r[idx]));
			cnt[idx] += c2(query(l[idx] - 1));
		}
	}
	for(int i = 1 ; i <= q ; ++i){
		long long ans = 0;
		ans += c2(l[i] - 1);
		ans += c2(n - r[i]);
		ans += c2(d[i] - 1);
		ans += c2(n - u[i]);
		ans -= cnt[i];
		ans = c2(n) - ans;
		printf("%lld\n" , ans);
	}
}