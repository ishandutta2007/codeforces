#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
const int SN = 1 << 18;
struct data{
	int pre;
	int idp;
	int suf;
	int ids;
	int ans;
	int idl;
	int idr;
	int sum;
};
inline data combine(const data &lft , const data &rgt){
	data res;
	res.sum = lft.sum + rgt.sum;
	res.pre = max(lft.pre , lft.sum + rgt.pre);
	res.suf = max(rgt.suf , rgt.sum + lft.suf);
	res.ans = max(max(lft.ans , rgt.ans) , lft.suf + rgt.pre);
	if(res.pre == lft.pre){
		res.idp = lft.idp;
	}
	else{
		res.idp = rgt.idp;
	}
	if(res.suf == rgt.suf){
		res.ids = rgt.ids;
	}
	else{
		res.ids = lft.ids;
	}
	if(res.ans == lft.ans){
		res.idl = lft.idl;
		res.idr = lft.idr;
	}
	else if(res.ans == rgt.ans){
		res.idl = rgt.idl;
		res.idr = rgt.idr;
	}
	else{
		res.idl = lft.ids;
		res.idr = rgt.idp;
	}
	return res;
}
int n;
int arr[N];
int q;
int type , l , r , val;
pair < data , data > segtree[SN];
bool lazy[SN];
void build(int l , int r , int node){
	if(l == r){
		segtree[node].first.pre = arr[l];
		segtree[node].first.suf = arr[r];
		segtree[node].first.ans = arr[l];
		segtree[node].first.sum = arr[r];
		segtree[node].first.idp = l;
		segtree[node].first.ids = r;
		segtree[node].first.idl = l;
		segtree[node].first.idr = r;
		segtree[node].second.pre = -arr[l];
		segtree[node].second.suf = -arr[r];
		segtree[node].second.ans = -arr[l];
		segtree[node].second.sum = -arr[r];
		segtree[node].second.idp = l;
		segtree[node].second.ids = r;
		segtree[node].second.idl = l;
		segtree[node].second.idr = r;
	}
	else{
		int mid = l + r >> 1;
		build(l , mid , node + node);
		build(mid + 1 , r , node + node + 1);
		segtree[node].first = combine(segtree[node + node].first , segtree[node + node + 1].first);
		segtree[node].second = combine(segtree[node + node].second , segtree[node + node + 1].second);
	}
}
inline void push(int l , int r , int node){
	if(lazy[node]){
		swap(segtree[node].first , segtree[node].second);
		if(l != r){
			lazy[node + node] ^= 1;
			lazy[node + node + 1] ^= 1;
		}
		lazy[node] = 0;
	}
}
void update(int l , int r , int node , int idx){
	push(l , r , node);
	if(l == r){
		segtree[node].first.pre = arr[l];
		segtree[node].first.suf = arr[r];
		segtree[node].first.ans = arr[l];
		segtree[node].first.sum = arr[r];
		segtree[node].second.pre = -arr[l];
		segtree[node].second.suf = -arr[r];
		segtree[node].second.ans = -arr[l];
		segtree[node].second.sum = -arr[r];
	}
	else{
		int mid = l + r >> 1;
		if(idx <= mid){
			update(l , mid , node + node , idx);
			push(mid + 1 , r , node + node + 1);
		}
		else{
			update(mid + 1 , r , node + node + 1 , idx);
			push(l , mid , node + node);
		}
		segtree[node].first = combine(segtree[node + node].first , segtree[node + node + 1].first);
		segtree[node].second = combine(segtree[node + node].second , segtree[node + node + 1].second);
	}
}
data query(int l , int r , int node , int ql , int qr){
	push(l , r , node);
	if(l >= ql && r <= qr){
		return segtree[node].first;
	}
	int mid = l + r >> 1;
	if(qr <= mid){
		return query(l , mid , node + node , ql , qr);
	}
	if(ql > mid){
		return query(mid + 1 , r , node + node + 1 , ql , qr);
	}
	return combine(query(l , mid , node + node , ql , qr) , query(mid + 1 , r , node + node + 1 , ql , qr));
}
void update(int l , int r , int node , int ql , int qr){
	push(l , r , node);
	if(l > qr || r < ql){
		return;
	}
	if(l >= ql && r <= qr){
		lazy[node] = 1;
		push(l , r , node);
		return;
	}
	int mid = l + r >> 1;
	update(l , mid , node + node , ql , qr);
	update(mid + 1 , r , node + node + 1 , ql , qr);
	segtree[node].first = combine(segtree[node + node].first , segtree[node + node + 1].first);
	segtree[node].second = combine(segtree[node + node].second , segtree[node + node + 1].second);
}
int dump[20][2];
int siz;
void query(int l , int r , int k){
	int res = 0;
	siz = 0;
	while(k--){
		data tmp = query(1 , n , 1 , l , r);
		if(tmp.ans < 0){
			break;
		}
		res += tmp.ans;
		dump[siz][0] = tmp.idl;
		dump[siz][1] = tmp.idr;
		++siz;
		update(1 , n , 1 , tmp.idl , tmp.idr);
	}
	printf("%d\n" , res);
	for(int i = 0 ; i < siz ; ++i){
		update(1 , n , 1 , dump[i][0] , dump[i][1]);
	}
}
int main(){
	scanf("%d" , &n);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d" , arr + i);
	}
	build(1 , n , 1);
	scanf("%d" , &q);
	while(q--){
		scanf("%d" , &type);
		if(type){
			scanf("%d %d %d" , &l , &r , &val);
			query(l , r , val);
		}
		else{
			scanf("%d %d" , &l , &val);
			arr[l] = val;
			update(1 , n , 1 , l);
		}
	}
}