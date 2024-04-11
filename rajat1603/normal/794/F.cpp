#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
const int SN = 1 << 18;
int n , q;
int arr[N];
struct data{
	long long sum;
	long long val[10];
	int who[10];
	bool iden;
};
data segtree[SN];
void build(int l , int r , int node){
	for(int i = 0 ; i < 10 ; ++i){
		segtree[node].who[i] = i;
	}
	segtree[node].iden = 1;
	if(l == r){
		int tmp = arr[l];
		int cur = 1;
		segtree[node].sum = tmp;
		while(tmp){
			segtree[node].val[tmp % 10] += cur;
			tmp /= 10;
			cur *= 10;
		}
	}
	else{
		int mid = l + r >> 1;
		build(l , mid , node + node);
		build(mid + 1 , r , node + node + 1);
		segtree[node].sum = segtree[node + node].sum + segtree[node + node + 1].sum;
		for(int i = 0 ; i < 10 ; ++i){
			segtree[node].val[i] = segtree[node + node].val[i] + segtree[node + node + 1].val[i];
		}
	}
}
long long tmp[10];
void push(int l , int r , int node){
	if(!segtree[node].iden){
		segtree[node].sum = 0;
		for(int i = 0 ; i < 10 ; ++i){
			segtree[node].sum += segtree[node].val[i] * segtree[node].who[i];
		}
		memcpy(tmp , segtree[node].val , sizeof(tmp));
		memset(segtree[node].val , 0 , sizeof(segtree[node].val));
		for(int i = 0 ; i < 10 ; ++i){
			segtree[node].val[segtree[node].who[i]] += tmp[i];
		}
		if(l != r){
			for(int i = 0 ; i < 10 ; ++i){
				segtree[node + node].who[i] = segtree[node].who[segtree[node + node].who[i]];
				segtree[node + node + 1].who[i] = segtree[node].who[segtree[node + node + 1].who[i]];
			}
			segtree[node + node].iden = segtree[node + node + 1].iden = 0;
		}
		for(int i = 0 ; i < 10 ; ++i){
			segtree[node].who[i] = i;
		}
		segtree[node].iden = 1;
	}
}
int type , l , r , x , y;
void update(int l , int r , int node , int ql , int qr){
	push(l , r , node);
	if(l > qr || r < ql){
		return;
	}
	if(l >= ql && r <= qr){
		segtree[node].iden = 0;
		segtree[node].who[x] = y;
		push(l , r , node);
		return;
	}
	int mid = l + r >> 1;
	update(l , mid , node + node , ql , qr);
	update(mid + 1 , r , node + node + 1 , ql , qr);
	segtree[node].sum = segtree[node + node].sum + segtree[node + node + 1].sum;
	for(int i = 0 ; i < 10 ; ++i){
		segtree[node].val[i] = segtree[node + node].val[i] + segtree[node + node + 1].val[i];
	}
}
long long query(int l , int r , int node , int ql , int qr){
	push(l , r , node);
	if(l > qr || r < ql){
		return 0;
	}
	if(l >= ql && r <= qr){
		return segtree[node].sum;
	}
	int mid = l + r >> 1;
	return query(l , mid , node + node , ql , qr) + query(mid + 1 , r , node + node + 1 , ql , qr);
}
int main(){
	scanf("%d %d" , &n , &q);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d" , arr + i);
	}
	build(1 , n , 1);
	while(q--){
		scanf("%d %d %d" , &type , &l , &r);
		if(type == 1){
			scanf("%d %d" , &x , &y);;
			update(1 , n , 1 , l , r);
		}
		else{
			printf("%lld\n" , query(1 , n , 1 , l , r));
		}
	}
}