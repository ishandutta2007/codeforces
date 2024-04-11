#include "bits/stdc++.h"
using namespace std;
const int N = 2e5 + 5;
const int SN = 1 << 19;
int n;
int arr[N];
vector < int > v[N];
long long ans , cur;
struct data{
	long long sum;
	int lazy;
	int mnval;
};
data segtree[SN];
void push(int l , int r , int node){
	if(segtree[node].lazy != -1){
		segtree[node].sum = 1LL * (r - l + 1LL) * segtree[node].lazy;
		segtree[node].mnval = segtree[node].lazy;
		if(l != r){
			segtree[node + node].lazy = segtree[node].lazy;
			segtree[node + node + 1].lazy = segtree[node].lazy;
		}
		segtree[node].lazy = -1;
	}
}
void build(int l , int r , int node){
	segtree[node].lazy = -1;
	segtree[node].mnval = l;
	if(l == r){
		segtree[node].sum = r;
	}
	else{
		int mid = l + r >> 1;
		build(l , mid , node + node);
		build(mid + 1 , r , node + node + 1);
		segtree[node].sum = segtree[node + node].sum + segtree[node + node + 1].sum;
	}
}
int query(int l , int r , int node , int ql , int qr , int val){
	push(l , r , node);
	if(l > qr || r < ql || segtree[node].mnval >= val){
		return -1;
	}
	if(l == r){
		return l;
	}
	int mid = l + r >> 1;
	int res = query(mid + 1 , r , node + node + 1 , ql , qr , val);
	if(res == -1){
		res = query(l , mid , node + node , ql , qr , val);
	}
	return res;
}
void update(int l , int r , int node , int ql , int qr , int val){
	push(l , r , node);
	if(l > qr || r < ql){
		return;
	}
	if(l >= ql && r <= qr){
		segtree[node].lazy = val;
		push(l , r , node);
		return;
	}
	int mid = l + r >> 1;
	update(l , mid , node + node , ql , qr , val);
	update(mid + 1 , r , node + node + 1 , ql , qr , val);
	segtree[node].sum = segtree[node + node].sum + segtree[node + node + 1].sum;
	segtree[node].mnval = segtree[node + node].mnval;
}
void update(int l , int r , int val){
	cur += segtree[1].sum;
	int idx = query(1 , n , 1 , l , r , val);
	if(idx != -1){
		update(1 , n , 1 , l , idx , val);
	}
	cur -= segtree[1].sum;
}
int main(){
	scanf("%d" , &n);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d" , &arr[i]);
		for(int j = 1 ; j * j <= arr[i] ; ++j){
			if(arr[i] % j == 0){
				v[j].emplace_back(i);
				if(j * j != arr[i]){
					v[arr[i] / j].emplace_back(i);
				}
			}
		}
	}
	cur = (1LL * n * (n + 1LL)) / 2LL;
	build(1 , n , 1);
	for(int i = N - 1 ; i >= 1 ; --i){
		long long old = cur;
		if(v[i].size() > 1){
			update(v[i][1] + 1 , n , n + 1);
			update(v[i][0] + 1 , v[i][1] , v[i].back());
			update(1 , v[i][0] , v[i][v[i].size() - 2]);
		}
		ans += (old - cur) * i;
	}
	printf("%lld\n" , ans);
}