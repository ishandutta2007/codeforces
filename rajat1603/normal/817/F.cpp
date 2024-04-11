#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
const int SN = 1 << 22;
int n;
int t[N];
long long a[N] , b[N];
vector < long long > v;
int na[N];
int nb[N];
int segtree[SN];
int lazy[SN];
bool flip[SN];
inline void push(int l , int r , int node){
	if(lazy[node] != -1){
		segtree[node] = (r - l + 1) * lazy[node];
		if(l != r){
			lazy[node + node] = lazy[node];
			lazy[node + node + 1] = lazy[node];
			flip[node + node] = 0;
			flip[node + node + 1] = 0;
		}
		lazy[node] = -1;
	}
	if(flip[node]){
		segtree[node] = r - l + 1 - segtree[node];
		if(l != r){
			flip[node + node] ^= 1;
			flip[node + node + 1] ^= 1;
		}
		flip[node] = 0;
	}
}
void update(int l , int r , int node , int ql , int qr , int val){
	push(l , r , node);
	if(l > qr || r < ql){
		return;
	}
	if(l >= ql && r <= qr){
		lazy[node] = val;
		push(l , r , node);
		return;
	}
	int mid = l + r >> 1;
	update(l , mid , node + node , ql , qr , val);
	update(mid + 1 , r , node + node + 1 , ql , qr , val);
	segtree[node] = segtree[node + node] + segtree[node + node + 1];
}
void update2(int l , int r , int node , int ql , int qr){
	push(l , r , node);
	if(l > qr || r < ql){
		return;
	}
	if(l >= ql && r <= qr){
		flip[node] ^= 1;
		push(l , r , node);
		return;
	}
	int mid = l + r >> 1;
	update2(l , mid , node + node , ql , qr);
	update2(mid + 1 , r , node + node + 1 , ql , qr);
	segtree[node] = segtree[node + node] + segtree[node + node + 1];
}
int query(int l , int r , int node){
	push(l , r , node);
	if(segtree[node] == r - l + 1){
		return -1;
	}
	if(l == r){
		return l;
	}
	int mid = l + r >> 1;
	int res = query(l , mid , node + node);
	if(res == -1){
		res = query(mid + 1 , r , node + node + 1);
	}
	return res;
}
int main(){
	scanf("%d" , &n);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d %lld %lld" , t + i , a + i , b + i);
		v.emplace_back(a[i]);
		v.emplace_back(b[i] + 1LL);
	}
	v.emplace_back(1);
	sort(v.begin() , v.end());
	v.resize(unique(v.begin() , v.end()) - v.begin());
	for(int i = 1 ; i <= n ; ++i){
		na[i] = lower_bound(v.begin() , v.end() , a[i]) - v.begin() + 1;
		nb[i] = lower_bound(v.begin() , v.end() , b[i] + 1) - v.begin();
	}
	for(int i = 1 ; i <= n ; ++i){
		if(t[i] == 1){
			update(1 , v.size() , 1 , na[i] , nb[i] , 1);
		}
		else if(t[i] == 2){
			update(1 , v.size() , 1 , na[i] , nb[i] , 0);
		}
		else{
			update2(1 , v.size() , 1 , na[i] , nb[i]);
		}
		printf("%lld\n" , v[query(1 , v.size() , 1) - 1]);
	}
}