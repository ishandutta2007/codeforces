#include "bits/stdc++.h"
using namespace std;
const int N = 5e5 + 5;
const int SN = 1 << 21;
int n;
int arr[N];
int q;
int segtree[SN];
void build(int l , int r , int node){
	if(l == r){
		segtree[node] = arr[l];
	}
	else{
		int mid = l + r >> 1;
		build(l , mid , node + node);
		build(mid + 1 , r , node + node + 1);
		segtree[node] = __gcd(segtree[node + node] , segtree[node + node + 1]);
	}
}
void update(int l , int r , int node , int idx){
	if(l == r){
		segtree[node] = arr[l];
	}
	else{
		int mid = l + r >> 1;
		if(idx <= mid){
			update(l , mid , node + node , idx);
		}
		else{
			update(mid + 1 , r , node + node + 1 , idx);
		}
		segtree[node] = __gcd(segtree[node + node] , segtree[node + node + 1]);
	}
}
pair < int , int > find(int l , int r , int node , int ql , int qr , int x){
	if(l > qr || r < ql || ql > qr){
		return make_pair(x , n + 1);
	}
	if(segtree[node] % x == 0){
		return make_pair(x , n + 1);
	}
	if(l == r){
		return make_pair(arr[l] , r);
	}
	int mid = l + r >> 1;
	if(l >= ql && r <= qr){
		auto it = find(l , mid , node + node , ql , qr , x);
		if(it.second != n + 1){
			return it;
		}
		return find(mid + 1 , r , node + node + 1 , ql , qr , x);
	}
	auto it = find(l , mid , node + node , ql , qr , x);
	if(it.second != n + 1){
		return it;
	}
	return find(mid + 1 , r , node + node + 1 , ql , qr , x);
}
int main(){
	scanf("%d" , &n);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d" , arr + i);
	}
	build(1 , n , 1);
	scanf("%d" , &q);
	while(q--){
		int type;
		scanf("%d" , &type);
		if(type == 1){
			int l , r , x;
			scanf("%d %d %d" , &l , &r , &x);
			auto it = find(1 , n , 1 , l , r , x);
			if(it.first % x == 0){
				printf("YES\n");
				continue;
			}
			it = find(1 , n , 1 , it.second + 1 , r , x);
			if(it.first % x == 0){
				printf("YES\n");
			}
			else{
				printf("NO\n");
			}
		}
		else{
			int idx , val;
			scanf("%d %d" , &idx , &val);
			arr[idx] = val;
			update(1 , n , 1 , idx);
		}
	}
}