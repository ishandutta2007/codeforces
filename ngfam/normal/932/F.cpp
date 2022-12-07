#include <bits/stdc++.h>

using namespace std;


template < class T > 
struct LineIT{
	/// Lim 
	static const T inf = 1e5 + 10;
	static const T Worst = 1e18 + 1;
 
	struct Line{
		T a;
		T b;
 
		T get(T x){
			if(a > inf) return Worst; 
			return a * x + b;
		}
	};
 
	static const int N = 400 + 10;
 
	T low, high;
 
	int root, cnt;
	vector < int > L;
	vector < int > R;	
	vector < Line > it;
 
	Line Create(T u, T v){
		Line ret;
		ret.a = u;
		ret.b = v;
		return ret;
	}
 	
 	LineIT(){};
	LineIT(T from, T to){
		low = from;
		high = to;
		L.resize(N * 18 + 10, 0);
		R.resize(N * 18 + 10, 0);
		it.resize(N * 18 + 10, Create(inf + 1, inf + 1));
		root = cnt = 1;
	}

	T lef, rig;
 
 
	void upd(int &x, T l, T r, Line val){
		if(l > rig || r < lef) return;

		if(x == 0) x = ++cnt;
 
		T mid  = ((l + r) >> 1);


 		if(l >= lef && r <= rig){
			if(it[x].get(l) <= val.get(l) && it[x].get(r) <= val.get(r)){
				return;
			}
			
			if(it[x].get(l) >= val.get(l) && it[x].get(r) >= val.get(r)){
				it[x] = val;
				return;
			}
	 
			if(it[x].get(l) >= val.get(l) && it[x].get(mid) >= val.get(mid)){
				upd(R[x], mid + 1, r, it[x]);
				it[x] = val;
				return;
			}
	 
			if(it[x].get(l) <= val.get(l) && it[x].get(mid) <= val.get(mid)){
				upd(R[x], mid + 1, r, val);
				return;
			}
	 
			if(it[x].get(mid + 1) >= val.get(mid + 1) && it[x].get(r) >= val.get(r)){
				upd(L[x], l, mid, it[x]);
				it[x] = val;
				return;
			}
	 
			if(it[x].get(mid + 1) <= val.get(mid + 1) && it[x].get(r) <= val.get(r)){
				upd(L[x], l, mid, val);
				return;
			}
		}
		upd(L[x], l, mid, val);
		upd(R[x], mid + 1, r, val);
	}
 
	T query(int x, int l, int r, T val){
		if(l > val || r < val || x == 0) return Worst;
 
		if(l == r) return it[x].get(val);
		T mid  = ((l + r) >> 1);
 
		T ans = it[x].get(val);


 
		ans = min(ans, query(L[x], l, mid, val));
		ans = min(ans, query(R[x], mid + 1, r, val));
 
		return ans;
	}
 
	void update(T a, T b, pair < T, T > seg = make_pair(-inf - 1, -inf - 1)){
		if(seg.first != -inf - 1){
			lef = seg.first;
			rig = seg.second;
		}
		else{
			lef = low;
			rig = high;
		}
		upd(root, low, high, Create(a, b));
	}
 
	T ask(T x){
		return query(root, low, high, x);
	}
};

const int N = 100010;

int n, TIME;
int a[N];
int b[N];
int L[N];
int R[N];
int perm[N];
int leaves[N];
long long f[N];
vector < int > g[N];
vector < LineIT < long long > > buffer;


void preDFS(int u, int p = -1){
	perm[++TIME] = u;
	L[u] = TIME;
	for(int v : g[u]){
		if(v == p) continue;
		preDFS(v, u);
		leaves[u] = 1;
	}
	R[u] = TIME;
}

int main(){

	scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		scanf("%d", a + i);
	}

	for(int i = 1; i <= n; ++i){
		scanf("%d", b + i);
	}
	
	for(int i = 1; i < n; ++i){
		int u, v;
		scanf("%d%d", &u, &v);
		g[u].push_back(v);
		g[v].push_back(u);
	}

	preDFS(1);

	int sz = 320;

	buffer.resize(325, LineIT < long long > (-1e5, 1e5));


	for(int i = n; i >= 1; --i){
		int x = perm[i];
		if(!leaves[x]) {
			buffer[i / sz].update(b[x], 0);
			continue;
		}

		int fr = L[x] + 1, to = R[x];


		long long ans = 1e18;



		while(fr <= to && fr % sz != 0){
			int y = perm[fr++];
			ans = min(ans, f[y] + 1LL * a[x] * b[y]);
		}

		while(fr + sz - 1 <= to){
			ans = min(ans, buffer[fr / sz].ask(a[x]));
			fr += sz;
		}


		while(fr <= to){
			int y = perm[fr++];
			ans = min(ans, f[y] + 1LL * a[x] * b[y]);
		}
		f[x] = ans;

		buffer[i / sz].update(b[x], f[x]);
	}

	for(int i = 1; i <= n; ++i){
		printf("%lld ", f[i]);
	}

	return 0;
}