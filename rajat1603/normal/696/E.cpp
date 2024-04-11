#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
const int SN = 1 << 18;
const long long inf = 1e16 + 16;
int n , m , q;
int a , b;
vector < int > v[N];
set < pair < pair < long long , int > , int > > s[N];
int tin[N];
int tout[N];
pair < long long , int > arr[N];
pair < long long , int > segtree[SN];
long long lazy[SN];
int subtree[N];
int chainhead[N];
int baap[N];
int depth[N];
int cur;
int type , k;
void dfs(int node , int parent){
	baap[node] = parent;
	depth[node] = depth[parent] + 1;
	subtree[node] = 1;
	for(int next : v[node]){
		if(next != parent){
			dfs(next , node);
			subtree[node] += subtree[next];
		}
	}
}
void dfs1(int node , int parent){
	++cur;
	tin[node] = cur;
	arr[cur] = s[node].begin() -> first;
	int who = -1;
	for(int next : v[node]){
		if(next != parent){
			if(who == -1 || subtree[next] > subtree[who]){
				who = next;
			}
		}
	}
	if(who != -1){
		chainhead[who] = chainhead[node];
		dfs1(who , node);
	}
	for(int next : v[node]){
		if(next != parent && next != who){
			chainhead[next] = next;
			dfs1(next , node);
		}
	}
	tout[node] = cur;
}
void build(int l , int r , int node){
	if(l == r){
		segtree[node] = arr[l];
	}
	else{
		int mid = l + r >> 1;
		build(l , mid , node + node);
		build(mid + 1 , r , node + node + 1);
		segtree[node] = min(segtree[node + node] , segtree[node + node + 1]);
	}
}
int answer[N];
int sz;
void push(int l , int r , int node){
	if(lazy[node]){
		segtree[node].first += lazy[node];
		if(l != r){
			lazy[node + node] += lazy[node];
			lazy[node + node + 1] += lazy[node];
		}
		lazy[node] = 0;
	}
}
pair < long long , int > query(int l , int r , int node , int ql , int qr){
	push(l , r , node);
	if(l > qr || r < ql){
		return {inf , n + 1};
	}
	if(l >= ql && r <= qr){
		return segtree[node];
	}
	int mid = l + r >> 1;
	return min(query(l , mid , node + node , ql , qr) , query(mid + 1 , r , node + node + 1 , ql , qr));
}
pair < long long , int > query(int a , int b){
	auto res = make_pair(inf , n + 1);
	while(chainhead[a] != chainhead[b]){
		if(depth[chainhead[a]] > depth[chainhead[b]]){
			swap(a , b);
		}
		res = min(res , query(1 , n , 1 , tin[chainhead[b]] , tin[b]));
		b = baap[chainhead[b]];
	}
	res = min(res , query(1 , n , 1 , min(tin[a] , tin[b]) , max(tin[a] , tin[b])));
	return res;
}
void update(int l , int r , int node , int ql , int qr , long long val){
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
	segtree[node] = min(segtree[node + node] , segtree[node + node + 1]);
}
int main(){
	scanf("%d %d %d" , &n , &m , &q);
	for(int i = 1 ; i < n ; ++i){
		scanf("%d %d" , &a , &b);
		v[a].emplace_back(b);
		v[b].emplace_back(a);
	}
	for(int i = 1 ; i <= m ; ++i){
		scanf("%d" , &a);
		s[a].insert({{i , a} , i});
	}
	for(int i = 1 ; i <= n ; ++i){
		s[i].insert({{inf , n + 1} , m + 1});
	}
	dfs(1 , 0);
	cur = 0;
	chainhead[1] = 1;
	dfs1(1 , 0);
	build(1 , n , 1);
	while(q--){
		scanf("%d" , &type);
		if(type == 1){
			scanf("%d %d %d" , &a , &b , &k);
			sz = 0;
			while(k--){
				auto tmp = query(a , b);
				if(tmp.first >= inf){
					break;
				}
				int node = tmp.second;
				int print = s[node].begin() -> second;
				long long oldw = s[node].begin() -> first.first;
				s[node].erase(s[node].begin());
				long long neww = s[node].begin() -> first.first;
				update(1 , n , 1 , tin[node] , tin[node] , neww - oldw);
				answer[++sz] = print;
			}
			printf("%d" , sz);
			for(int i = 1 ; i <= sz ; ++i){
				printf(" %d" , answer[i]);
			}
			printf("\n");
		}
		else{
			scanf("%d %d" , &a , &k);
			update(1 , n , 1 , tin[a] , tout[a] , k);
		}
	}
}