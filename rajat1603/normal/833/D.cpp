#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
const int mod = 1e9 + 7;
int n;
int a[N] , b[N] , c[N] , d[N];
vector < int > v[N];
int power(int a , int b){
	int res = 1;
	while(b){
		if(b & 1){
			res = (1LL * res * a) % mod;
		}
		a = (1LL * a * a) % mod;
		b >>= 1;
	}
	return res;
}
int ans;
int den;
int subtree[N];
bool done[N];
void dfs1(int node , int parent){
	subtree[node] = 1;
	for(int edge : v[node]){
		int next = a[edge] ^ b[edge] ^ node;
		if(next != parent && !done[next]){
			dfs1(next , node);
			subtree[node] += subtree[next];
		}
	}
}
int find(int node , int parent , int val){
	for(int edge : v[node]){
		int next = a[edge] ^ b[edge] ^ node;
		if(next != parent && !done[next] && subtree[next] > val){
			return find(next , node , val);
		}
	}
	return node;
}
int tot;
int prod;
int bit1[N * 4];
int bit2[N * 4];
int bit3[N * 4];
int bit4[N * 4];
int offset;
int limit;
void update1(int bit[] , int idx){
	idx += offset;
	while(idx){
		++bit[idx];
		idx -= idx & -idx;
	}
}
int query1(int bit[] , int idx){
	idx += offset;
	int res = 0;
	while(idx <= limit){
		res += bit[idx];
		idx += idx & -idx;
	}
	return res;
}
void update2(int bit[] , int idx , int val){
	idx += offset;
	while(idx){
		bit[idx] = (1LL * bit[idx] * val) % mod;
		idx -= idx & -idx;
	}
}
int query2(int bit[] , int idx){
	idx += offset;
	int res = 1;
	while(idx <= limit){
		res = (1LL * res * bit[idx]) % mod;
		idx += idx & -idx;
	}
	return res;
}
int dfs1point5(int node , int parent){
	int res = 0;
	for(int edge : v[node]){
		int next = a[edge] ^ b[edge] ^ node;
		if(next != parent && !done[next]){
			res = max(res , 1 + dfs1point5(next , node));
		}
	}
	return res;
}
int tmp;
void dfs2(int node , int parent , int cur , int x , int y){
	den = (1LL * den * prod) % mod;
	tmp = (1LL * tmp * cur) % mod;
	ans = (1LL * ans * query2(bit4 , x - 2 * y)) % mod;
	ans = (1LL * ans * power(cur , query1(bit3 , x - 2 * y))) % mod;
	ans = (1LL * ans * query2(bit2 , y - 2 * x)) % mod;
	ans = (1LL * ans * power(cur , query1(bit1 , y - 2 * x))) % mod;
	for(int edge : v[node]){
		int next = a[edge] ^ b[edge] ^ node;
		if(next != parent && !done[next]){
			dfs2(next , node , (1LL * cur * c[edge]) % mod , x + (d[edge] == 0) , y + (d[edge] == 1));
		}
	}
}
void dfs3(int node , int parent , int cur , int x , int y){
	prod = (1LL * prod * cur) % mod;
	++tot;
	update1(bit1 , 2 * x - y);
	update1(bit3 , 2 * y - x);
	update2(bit2 , 2 * x - y , cur);
	update2(bit4 , 2 * y - x , cur);
	for(int edge : v[node]){
		int next = a[edge] ^ b[edge] ^ node;
		if(next != parent && !done[next]){
			dfs3(next , node , (1LL * cur * c[edge]) % mod , x + (d[edge] == 0) , y + (d[edge] == 1));
		}
	}
}
void getans(int node){
	tot = 1;
	prod = 1;
	int mxdepth = dfs1point5(node , 0);
	offset = mxdepth * 2 + 1;
	limit = mxdepth * 4 + 1;
	for(int i = 0 ; i <= limit ; ++i){
		bit1[i] = 0;
		bit2[i] = 1;
		bit3[i] = 0;
		bit4[i] = 1;
	}
	update1(bit1 , 0);
	update1(bit3 , 0);
	for(int edge : v[node]){
		int next = a[edge] ^ b[edge] ^ node;
		if(done[next]){
			continue;
		}
		tmp = 1;
		dfs2(next , node , c[edge] , d[edge] == 0 , d[edge] == 1);
		den = (1LL * den * power(tmp , tot)) % mod;
		dfs3(next , node , c[edge] , d[edge] == 0 , d[edge] == 1);
	}
}
void solve(int node){
	dfs1(node , 0);
	int cent = find(node , 0 , subtree[node] >> 1);
	getans(cent);
	done[cent] = 1;
	for(int edge : v[cent]){
		int next = a[edge] ^ b[edge] ^ cent;
		if(!done[next]){
			solve(next);
		}
	}
}
int main(){
	scanf("%d" , &n);
	for(int i = 1 ; i < n ; ++i){
		scanf("%d %d %d %d" , a + i , b + i , c + i , d + i);
		v[a[i]].emplace_back(i);
		v[b[i]].emplace_back(i);
	}
	ans = 1;
	den = 1;
	for(int i = 0 ; i < N ; ++i){
		bit2[i] = 1;
		bit4[i] = 1;
	}
	solve(1);
	ans = (1LL * ans * power(den , mod - 2)) % mod;
	printf("%d\n" , ans);
}