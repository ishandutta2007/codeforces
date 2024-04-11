#include "bits/stdc++.h"
using namespace std;
const int N = 3e5 + 5;
const int SN = N * 20;
struct data{
	int cnt;
	int lft;
	int rgt;
};
int n , q;
int arr[N];
int l , r , k;
int root[N];
data segtree[SN];
int cur;
void insert(int l , int r , int &node , int old , int idx){
	node = ++cur;
	segtree[node].cnt = segtree[old].cnt + 1;
	if(l == r){
		return;
	}
	int mid = l + r >> 1;
	if(idx <= mid){
		segtree[node].rgt = segtree[old].rgt;
		insert(l , mid , segtree[node].lft , segtree[old].lft , idx);
	}
	else{
		segtree[node].lft = segtree[old].lft;
		insert(mid + 1 , r , segtree[node].rgt , segtree[old].rgt , idx);
	}
}
int query(int l , int r , int noder , int nodel , int val){
	if(segtree[noder].cnt - segtree[nodel].cnt <= val){
		return -1;
	}
	if(l == r){
		return l;
	}
	int mid = l + r >> 1;
	int res = query(l , mid , segtree[noder].lft , segtree[nodel].lft , val);
	if(res == -1){
		res = query(mid + 1 , r , segtree[noder].rgt , segtree[nodel].rgt , val);
	}
	return res;
}
int main(){
	scanf("%d %d" , &n , &q);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d" , arr + i);
		insert(1 , n , root[i] , root[i - 1] , arr[i]);
	}
	while(q--){
		scanf("%d %d %d" , &l , &r , &k);
		printf("%d\n" , query(1 , n , root[r] , root[l - 1] , (r - l + 1) / k));
	}
}