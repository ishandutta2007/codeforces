#include "bits/stdc++.h"
using namespace std;
const int N = 1e9 + 9;
const int SN = 5e7 + 7;
struct data{
	long long sum;
	int lft;
	int rgt;
};
data segtree[SN];
int root1[1000000] , root2[1000000];
int cur;
void update(int l , int r , int &node , int old , int idx , int val){
	node = ++cur;
	segtree[node].sum = segtree[old].sum + val;
	if(l < r){
		int mid = l + r >> 1;
		if(idx <= mid){
			segtree[node].rgt = segtree[old].rgt;
			update(l , mid , segtree[node].lft , segtree[old].lft , idx , val);
		}
		else{
			segtree[node].lft = segtree[old].lft;
			update(mid + 1 , r , segtree[node].rgt , segtree[old].rgt , idx , val);
		}
	}
}
long long query(int l , int r , int node , int ql , int qr){
	if(l > qr || r < ql || !node){
		return 0;
	}
	if(l >= ql && r <= qr){
		return segtree[node].sum;
	}
	int mid = l + r >> 1;
	return query(l , mid , segtree[node].lft , ql , qr) + query(mid + 1 , r , segtree[node].rgt , ql , qr);
}
long long get(int idx , int x){
	long long res = 0;
	res += query(0 , N , root1[idx] , 0 , x);
	res += query(0 , N , root2[idx] , 0 , x) * x;
	return res;
}
int main(){
	int n;
	int x1 , x2 , y1 , a , b , y2;
	cur = 1;
	scanf("%d" , &n);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d %d %d %d %d %d" , &x1 , &x2 , &y1 , &a , &b , &y2);
		root1[i] = root1[i - 1];
		root2[i] = root2[i - 1];
		update(0 , N , root1[i] , root1[i] ,  0 , y1);
		update(0 , N , root1[i] , root1[i] , x1 + 1 , b - y1);
		update(0 , N , root1[i] , root1[i] , x2 + 1 , y2 - b);
		update(0 , N , root2[i] , root2[i] , x1 + 1 , a);
		update(0 , N , root2[i] , root2[i] , x2 + 1 , -a);
	}
	int q;
	long long last = 0;
	scanf("%d" , &q);
	while(q--){
		int l , r , x;
		scanf("%d %d %d" , &l , &r , &x);
		x = (last + x) % 1000000000;
		last = get(r , x) - get(l - 1 , x);
		printf("%lld\n" , last);
	}
}
/*
y1, if xx1.
ax+b, if x1<xx2.
y2, if x>x2.
*/