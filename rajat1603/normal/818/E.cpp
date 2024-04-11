#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
const int SN = 1 << 18;
int n , k;
int arr[N];
int segtree[SN];
long long ans;
void build(int l , int r , int node){
	if(l == r){
		segtree[node] = __gcd(arr[l] , k);
	}
	else{
		int mid = l + r >> 1;
		build(l , mid , node + node);
		build(mid + 1 , r , node + node + 1);
		segtree[node] = __gcd(1LL * segtree[node + node] * segtree[node + node + 1] , 1LL * k);
	}
}
int query(int l , int r , int node , int ql , int qr){
	if(l > qr || r < ql){
		return 1;
	}
	if(l >= ql && r <= qr){
		return segtree[node];
	}
	int mid = l + r >> 1;
	return __gcd(1LL * query(l , mid , node + node , ql , qr) * query(mid + 1 , r , node + node + 1 , ql , qr) , 1LL * k);
}
int main(){
	scanf("%d %d" , &n , &k);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d" , arr + i);
	}
	++n;
	arr[n] = k;
	build(1 , n , 1);
	int ptr = 1;
	for(int i = 1 ; i <= n ; ++i){
		ptr = max(ptr , i);
		while(query(1 , n , 1 , i , ptr) != k){
			++ptr;
		}
		ans += n - ptr;
	}
	printf("%lld\n" , ans);
}