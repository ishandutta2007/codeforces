#include "bits/stdc++.h"
using namespace std;
const int N = 3e4 + 4;
const int SQN = 200;
int n , mod;
pair < int , int > inp[N];
int arr[N];
int rev[N];
int cur;
inline int add(int a , int b){
	return ((a + b) >= mod) ? (a + b - mod) : (a + b);
}
struct mat{
	unsigned b;
	unsigned a;
	mat(unsigned _b , unsigned _a){
		a = _a;
		b = _b;
	}
	mat(){

	}
	inline mat operator * (const mat &o) const {
		return mat((b * (o.a + o.b) + a * o.b) % mod , (b * o.b + a * o.a) % mod);
	}
	inline mat operator * (const int o) const {
		return mat((b * o) % mod , (a * o) % mod);
	}
	inline mat operator + (const mat &o) const {
		return mat(add(b , o.b) , add(a , o.a));
	}
};
mat fib[N];
mat ifib[N];
void pre(){
	fib[0] = mat(0 , 1);
	ifib[0] = mat(0 , 1);
	fib[1] = mat(1 , 0);
	ifib[1] = mat(1 , mod - 1);
	for(int i = 2 ; i <= n ; ++i){
		fib[i] = fib[i - 1] * fib[1];
		ifib[i] = ifib[i - 1] * ifib[1];
	}
}
struct query{
	int l;
	int r;
	int idx;
	query(){
		
	}
	bool operator < (const query &o) const {
		if(int(l / SQN) == int(o.l / SQN)){
			return r < o.r;
		}
		return l < o.l;
	}
};
const int SN = 1 << 16;
int q;
query que[N];
int curl;
int curr;
int ans[N];
mat segtree[SN];
int lazy[SN];
int freq[N];
int bit[N];
void build(int l , int r , int node){
	lazy[node] = 0;
	segtree[node] = mat(0 , 0);
	freq[l] = 0;
	bit[r] = 0;
	if(l < r){
		int mid = l + r >> 1;
		build(l , mid , node + node);
		build(mid + 1 , r , node + node + 1);
	}
}
void update(int idx , int val){
	while(idx <= cur){
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
inline void push(int l , int r , int node){
	if(lazy[node]){
		segtree[node] = segtree[node] * ((lazy[node] >= 0) ? fib[lazy[node]] : ifib[-lazy[node]]);
		if(l != r){
			lazy[node + node] += lazy[node];
			lazy[node + node + 1] += lazy[node];
		}
		lazy[node] = 0;
	}
}
void update(int l , int r , int node , int idx , const mat &val){
	push(l , r , node);
	if(l == r){
		segtree[node] = val;
	}
	else{
		int mid = l + r >> 1;
		if(idx <= mid){
			update(l , mid , node + node , idx , val);
			push(mid + 1 , r , node + node + 1);
		}
		else{
			update(mid + 1 , r , node + node + 1 , idx , val);
			push(l , mid , node + node);
		}
		segtree[node] = segtree[node + node] + segtree[node + node + 1];
	}
}
void update(int l , int r , int node , int ql , int qr , int val){
	push(l , r , node);
	if(l > qr || r < ql || ql > qr){
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
/*
void print(int l , int r , int node){
	cout << l << " " << r << " " << segtree[node].a[0][1] << " " << segtree[node].a[0][0] << " " << lazy[node] << endl;
	if(l < r){
		int mid = l + r >> 1;
		print(l , mid , node + node);
		print(mid + 1 , r , node + node + 1);
	}
}*/
inline void add(int idx){
	int val = arr[idx];
	++freq[val];
	if(freq[val] == 1){
		int tmp = query(val);
		update(1 , cur , 1 , val , fib[tmp] * (rev[val] % mod));
		update(val , 1);
		update(1 , cur , 1 , val , cur , 1);
	}
	//cout << val << " Added\n";
	//print(1 , cur , 1);
}
inline void remove(int idx){
	int val = arr[idx];
	--freq[val];
	if(freq[val] == 0){
		update(val , -1);
		update(1 , cur , 1 , val , mat(0 , 0));
		update(1 , cur , 1 , val , cur , -1);
	}
	//cout << val << " Removed\n";
	//print(1 , cur , 1);
}
/*int brute(int l , int r){
	set < int > s;
	for(int i = l ; i <= r ; ++i){
		s.insert(arr[i]);
	}
	int a = 0;
	int b = 1;
	int ans = 0;
	for(int x : s){
		ans = add(ans , mult(b , rev[x]));
		int tmp = a;
		a = b;
		b = add(tmp , b);
	}
	return ans;
}
*/
void solve(){
	curl = 1;
	curr = 0;
	build(1 , cur , 1);
	//print(1 , cur , 1);
	for(int i = 1 ; i <= q ; ++i){
		int l = que[i].l;
		int r = que[i].r;
		while(curr < r){
			add(++curr);
		}
		while(curl > l){
			add(--curl);
		}
		while(curr > r){
			remove(curr--);
		}
		while(curl < l){
			remove(curl++);
		}
		/*if(brute(l , r) != segtree[1].a[0][1]){
			cout << l << " " << r << " " << brute(l , r) << " " << segtree[1].a[0][1] << endl;
		}*/
		ans[que[i].idx] = segtree[1].b;
	}
}
int main(){
	scanf("%d %d" , &n , &mod);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d",  &inp[i].first);
		inp[i].second = i;
	}
	sort(inp + 1 , inp + 1 + n);
	cur = 0;
	inp[0].first = INT_MIN;
	for(int i = 1 ; i <= n ; ++i){
		cur += (inp[i - 1].first != inp[i].first);
		arr[inp[i].second] = cur;
		rev[cur] = inp[i].first % mod;
	}
	pre();
	scanf("%d" , &q);
	for(int i = 1 ; i <= q ; ++i){
		scanf("%d %d" , &que[i].l , &que[i].r);
		que[i].idx = i;
	}
	sort(que + 1 , que + 1 + q);
	solve();
	for(int i = 1 ; i <= q ; ++i){
		printf("%d\n" , ans[i]);
	}
}