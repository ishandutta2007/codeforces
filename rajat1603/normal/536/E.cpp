#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
const int SN = 1 << 18;
int n , q;
int f[N];
pair < int , pair < int , int > > edge[N];
vector < int > v[N];
int depth[N];
int subtree[N];
int tin[N];
int rev[N];
int head[N];
pair < pair < int , int > , pair < int , int > > queries[N];
int ans[N];
int timer;
int parent[N];
void dfs1(int node , int parent){
	subtree[node] = 1;
	depth[node] = depth[parent] + 1;
	::parent[node] = parent;
	for(int next : v[node]){
		if(next != parent){
			dfs1(next , node);
			subtree[node] += subtree[next];
		}
	}
}
void dfs2(int node , int parent){
	++timer;
	tin[node] = timer;
	rev[timer] = node;
	int big = 0;
	for(int next : v[node]){
		if(next != parent){
			if((!big) || (subtree[next] > subtree[big])){
				big = next;
			}
		}
	}
	if(big){
		head[big] = head[node];
		dfs2(big , node);
	}
	for(int next : v[node]){
		if(next != parent && next != big){
			head[next] = next;
			dfs2(next , node);
		}
	}
}
struct data{
	int ans;
	int top;
	int bot;
	bool full;
	data(int x = 0){
		ans = f[x];
		top = x;
		bot = x;
		full = x;
	}
};
inline data combine(const data &up , const data &down){
	data res;
	res.ans = up.ans + down.ans + (f[up.bot + down.top] - f[up.bot] - f[down.top]) * (up.bot && down.top);
	res.full = up.full && down.full;
	res.top = up.top + down.top * up.full;
	res.bot = down.bot + up.bot * down.full;
	return res;
}
data segtree[SN];
void pre(){
	for(int i = 1 ; i < n ; ++i){
		v[edge[i].second.first].emplace_back(edge[i].second.second);
		v[edge[i].second.second].emplace_back(edge[i].second.first);
	}
	depth[0] = 0;
	dfs1(1 , 0);
	timer = 0;
	head[1] = 1;
	dfs2(1 , 0);
}
void update(int l , int r , int node , int idx){
	if(l == r){
		segtree[node] = data(1);
	}
	else{
		int mid = l + r >> 1;
		if(idx <= mid){
			update(l , mid , node + node , idx);
		}
		else{
			update(mid + 1 , r , node + node + 1 , idx);
		}
		segtree[node] = combine(segtree[node + node] , segtree[node + node + 1]);
	}
}
void update(pair < int , int > edge){
	int a = edge.first;
	int b = edge.second;
	if(depth[b] < depth[a]){
		swap(a , b);
	}
	update(1 , n , 1 , tin[b]);
}
data query(int l , int r , int node , int ql , int qr){
	if(l >= ql && r <= qr){
		return segtree[node];
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
int query(int a , int b){
	data res1(0);
	data res2(0);
	while(head[a] != head[b]){
		if(depth[head[a]] > depth[head[b]]){
			res1 = combine(query(1 , n , 1 , tin[head[a]] , tin[a]) , res1);
			a = parent[head[a]];
		}
		else{
			res2 = combine(query(1 , n , 1 , tin[head[b]] , tin[b]) , res2);
			b = parent[head[b]];
		}
	}
	if(tin[a] < tin[b]){
		res2 = combine(query(1 , n , 1 , tin[a] + 1 , tin[b]) , res2);
	}
	if(tin[b] < tin[a]){
		res1 = combine(query(1 , n , 1 , tin[b] + 1 , tin[a]) , res1);
	}
	swap(res1.top , res1.bot);
	return combine(res1 , res2).ans;
}
int main(){
	scanf("%d %d" , &n , &q);
	for(int i = 1 ; i < n ; ++i){
		scanf("%d" , f + i);
	}
	f[0] = 0;
	for(int i = 1 ; i < n ; ++i){
		scanf("%d %d %d" , &edge[i].second.first , &edge[i].second.second , &edge[i].first);
	}
	edge[0].first = 0;
	sort(edge + 1 , edge + n);
	for(int i = 1 ; i <= q ; ++i){
		scanf("%d %d %d" , &queries[i].second.first , &queries[i].second.second , &queries[i].first.first);
		queries[i].first.second = i;
	}
	int ptr = n;
	sort(queries + 1 , queries + 1 + q);
	pre();
	for(int i = q ; i >= 1 ; --i){
		while(edge[ptr - 1].first >= queries[i].first.first){
			update(edge[--ptr].second);
		}
		ans[queries[i].first.second] = query(queries[i].second.first , queries[i].second.second);
	}
	for(int i = 1 ; i <= q ; ++i){
		printf("%d\n" , ans[i]);
	}
}