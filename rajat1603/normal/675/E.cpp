#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
const int SN = 1 << 18;
int n;
int arr[N];
long long segtree[SN];
long long ans = 0;
void build(int l , int r , int node){
	segtree[node] = 1LL << 60;
	if(l < r){
		int mid = l + r >> 1;
		build(l , mid , node + node);
		build(mid + 1 , r , node + node + 1);
	}
}
long long query(int l , int r , int node , int ql , int qr){
	if(l > qr || r < ql){
		return 1LL << 60;
	}
	if(l >= ql && r <= qr){
		return segtree[node];
	}
	int mid = l + r >> 1;
	return min(query(l , mid , node + node , ql , qr) , query(mid + 1 , r , node + node + 1 , ql , qr));
}
void update(int l , int r , int node , int idx , long long val){
	if(l == r){
		segtree[node] = val;
	}
	else{
		int mid = l + r >> 1;
		if(idx <= mid){
			update(l , mid , node + node , idx , val);
		}
		else{
			update(mid + 1 , r , node + node + 1 , idx , val);
		}
		segtree[node] = min(segtree[node + node] , segtree[node + node + 1]);
	}
}
int main(){
	scanf("%d" , &n);
	for(int i = 1 ; i < n ; ++i){
		scanf("%d" , arr + i);
	}
	arr[n] = n;
	build(1 , n , 1);
	for(int i = n ; i >= 1 ; --i){
		long long val;
		if(arr[i] == n){
			val = n - i;
		}
		else{
			val = query(1 , n , 1 , i + 1 , arr[i]) + n - arr[i] - i;
		}
		ans += val;
		update(1 , n , 1 , i , val + i);
	}
	printf("%lld\n" , ans);
}