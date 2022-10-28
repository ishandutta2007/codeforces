#include "bits/stdc++.h"
using namespace std;
const int N = 2e5 + 5;
const int SN = 1 << 19;
int n , m;
int arr[N];
long long dp[N];
vector < pair < int , int > > v[N];
int l , r , x;
long long segtree[SN];
long long lazy[SN];
void push(int l , int r , int node){
	segtree[node] += lazy[node];
	if(l != r){
		lazy[node + node] += lazy[node];
		lazy[node + node + 1] += lazy[node];
	}
	lazy[node] = 0;
}
void update(int l , int r , int node , int ql , int qr , long long val){
	push(l , r , node);
	if(l > qr || r < ql){
		return;
	}
	if(l >= ql && r <= qr){
		lazy[node] = val;
		push(l , r , node);
		return;
	}
	int mid = l + r >> 1;
	update(l , mid , node + node , ql , qr , val);
	update(mid + 1 , r , node + node + 1 , ql , qr , val);
	segtree[node] = max(segtree[node + node] , segtree[node + node + 1]);
}
int main(){
	scanf("%d %d" , &n , &m);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d" , arr + i);
	}
	for(int i = 1 ; i <= m ; ++i){
		scanf("%d %d %d" , &l , &r , &x);
		v[l].emplace_back(make_pair(r , x));
	}
	dp[n + 1] = 0;
	for(int i = n ; i >= 1 ; --i){
		for(auto it : v[i]){
			update(1 , n , 1 , it.first , n , it.second);
		}
		update(1 , n , 1 , i , n , -arr[i]);
		update(1 , n , 1 , i , i , dp[i + 1]);
		dp[i] = max(dp[i + 1] , segtree[1]);
	}
	printf("%lld\n" , dp[1]);
}