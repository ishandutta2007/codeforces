#include "bits/stdc++.h"
using namespace std;
const int N = 4e5 + 5;
const int SN = 1 << 20;
int n;
char str[N];
int arr[N];
int mod;
pair < int , int > segtree[SN];
inline pair < int , int > combine(const pair < int , int > lft , const pair < int , int > rgt){
	return make_pair((1LL * lft.first * rgt.second + rgt.first) % mod , (1LL * lft.second * rgt.second) % mod);
}
void build(int l , int r , int node){
	if(l == r){
		segtree[node] = make_pair(arr[l] % mod , 10 % mod);
	}
	else{
		int mid = l + r >> 1;
		build(l , mid , node + node);
		build(mid + 1 , r , node + node + 1);
		segtree[node] = combine(segtree[node + node] , segtree[node + node + 1]);
	}
}
pair < int , int > query(int l , int r , int node , int ql , int qr){
	if(l > qr || r < ql){
		return make_pair(0 , 1);
	}
	if(l >= ql && r <= qr){
		return segtree[node];
	}
	int mid = l + r >> 1;
	return combine(query(l , mid , node + node , ql , qr) , query(mid + 1 , r , node + node + 1 , ql , qr));
}
int main(){
	scanf("%s" , str);
	n = strlen(str);
	for(int i = 1 ; i <= n ; ++i){
		arr[i] = str[i - 1] - '0';
	}
	for(int i = n + 1 ; i <= n + n ; ++i){
		arr[i] = arr[i - n];
	}
	scanf("%d" , &mod);
	build(1 , n + n , 1);
	int ans = mod;
	for(int i = 1 ; i <= n ; ++i){
		if(arr[i] != 0){
			ans = min(ans , query(1 , n + n , 1 , i , i + n - 1).first);
		}
	}
	printf("%d\n" , ans);
}