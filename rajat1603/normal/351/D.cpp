#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
const int SN = 1 << 18;
int n;
int arr[N];
int rgt[N];
int lst[N];
int dif[N];
int q;
int l[N] , r[N];
vector < int > v[N];
int bit[N];
int ans[N];
void update(int idx , int val){
	while(idx <= n){
		bit[idx] += val;
		idx += idx & -idx;
	}
}
int query(int idx){
	int res = 0;
	while(idx){
		res += bit[idx];
		idx -= idx & -idx;
	}
	return res;
}
int segtree[SN];
void update(int l , int r , int node , int idx , int val){
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
		segtree[node] = max(segtree[node + node] , segtree[node + node + 1]);
	}
}

void update2(int idx , int val){
	update(1 , n , 1 , idx , val);
}

int query(int l , int r , int node , int ql , int qr){
	if(l > qr || r < ql){
		return 0;
	}
	if(l >= ql && r <= qr){
		return segtree[node];
	}
	int mid = l + r >> 1;
	return max(query(l , mid , node + node , ql , qr) , query(mid + 1 , r , node + node + 1 , ql , qr));
}

int query2(int idx){
	return query(1 , n , 1 , 1 , idx);
}
int main(){
	scanf("%d" , &n);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d" , arr + i);
	}
	for(int i = n ; i >= 1 ; --i){
		if(lst[arr[i]]){
			if(dif[arr[i]]){
				if(lst[arr[i]] - i != dif[arr[i]]){
					rgt[i] = lst[arr[i]] + dif[arr[i]] - 1;
				}
				else{
					rgt[i] = rgt[lst[arr[i]]];
				}
			}
			else{
				rgt[i] = n;
			}
			dif[arr[i]] = lst[arr[i]] - i;
		}
		else{
			rgt[i] = n;
		}
		lst[arr[i]] = i;
	}
	scanf("%d" , &q);
	for(int i = 1 ; i <= q ; ++i){
		scanf("%d %d" , l + i , r + i);
		v[l[i]].emplace_back(i);
	}
	memset(lst , 0 , sizeof(lst));
	for(int i = n ; i >= 1 ; --i){
		update(i , 1);
		update2(i , rgt[i]);
		if(lst[arr[i]]){
			update(lst[arr[i]] , -1);
			update2(lst[arr[i]] , -1);
		}
		for(int que : v[i]){
			int val = query2(r[que]);
			int ans = query(r[que]);
			if(val < r[que]){
				++ans;
			}
			::ans[que] = ans;
		}
		lst[arr[i]] = i;
	}
	for(int i = 1 ; i <= q ; ++i){
		printf("%d\n" , ans[i]);
	}
}