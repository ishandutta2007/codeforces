#include "bits/stdc++.h"
using namespace std;
const int N = 5e5 + 5;
const int SN = 1 << 20;
int n;
int p , q , r;
int a[N] , b[N] , c[N];
vector < int > v[N];
int mx1[N];
int mx2[N];
long long ans;
int lazy[SN];
long long segsum[SN];
int segmin[SN];
inline void push(int l , int r , int node){
	if(lazy[node]){
		segsum[node] = 1LL * (r - l + 1LL) * lazy[node];
		segmin[node] = lazy[node];
		if(l != r){
			lazy[node + node] = lazy[node];
			lazy[node + node + 1] = lazy[node];
		}
		lazy[node] = 0;
	}
}
int find(int l , int r , int node , int val){
	push(l , r , node);
	if(segmin[node] >= val){
		return -1;
	}
	if(l == r){
		return l;
	}
	int mid = l + r >> 1;
	int res = find(l , mid , node + node , val);
	if(res == -1){
		res = find(mid + 1 , r , node + node + 1 , val);
	}
	return res;
}
void update(int l , int r , int node , int ql , int qr , int value){
	push(l , r , node);
	if(l > qr || r < ql){
		return;
	}
	if(l >= ql && r <= qr){
		lazy[node] = value;
		push(l , r , node);
		return;
	}
	int mid = l + r >> 1;
	update(l , mid , node + node , ql , qr , value);
	update(mid + 1 , r , node + node + 1 , ql , qr , value);
	segsum[node] = segsum[node + node] + segsum[node + node + 1];
	segmin[node] = min(segmin[node + node] , segmin[node + node + 1]);
}
void update(int idx , int value){
	int l = find(1 , q , 1 , value);
	if(l != -1 && l <= idx){
		update(1 , q , 1 , l , idx , value);
	}
}
long long query(int l , int r , int node , int ql , int qr){
	push(l , r , node);
	if(l > qr || r < ql){
		return 0;
	}
	if(l >= ql && r <= qr){
		return segsum[node];
	}
	int mid = l + r >> 1;
	return query(l , mid , node + node , ql , qr) + query(mid + 1 , r , node + node + 1 , ql , qr);
}
void solve(int idx){
	int x = mx1[idx];
	int y = mx2[idx];
	int tmp = find(1 , q , 1 , y);
	if(tmp == -1){
		tmp = q + 1;
	}
	if(tmp <= x){
		tmp = x + 1;
	}
	ans += 1LL * r * (q - x);
	ans -= 1LL * y * (q - tmp + 1LL);
	if(x + 1 < tmp){
		ans -= query(1 , q , 1 , x + 1 , tmp - 1);
	}
	for(int i : v[idx]){
		update(b[i] , c[i]);
	}
}
int main(){
	scanf("%d" , &n);
	scanf("%d %d %d" , &p , &q , &r);
		for(int i = 1 ; i <= n ; ++i){
		scanf("%d %d %d" , a + i , b + i , c + i);
		v[a[i]].emplace_back(i);
	}
	mx1[p + 1] = 0;
	mx2[p + 1] = 0;
	for(int i = p ; i >= 1 ; --i){
		mx1[i] = mx1[i + 1];
		mx2[i] = mx2[i + 1];
		for(int idx : v[i]){
			mx1[i] = max(mx1[i] , b[idx]);
			mx2[i] = max(mx2[i] , c[idx]);
		}
	}
	ans = 0;
	for(int i = 1 ; i <= p ; ++i){
		solve(i);
	}
	printf("%lld\n" , ans);
}