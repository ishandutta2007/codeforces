#include <bits/stdc++.h>

using namespace std;

const int N = 100010;
const int M = 230;

int n, m;
int a[N];
int b[N];
int nxt[N];
int child[N];
int parent[N];
vector < int > g[N]; 

void preDfs(int u){
	child[u] = 1;
	for(int &v : g[u]){
		preDfs(v);
		child[u] += child[v];
		if(child[v] > child[g[u][0]]) swap(g[u][0], v);
	}
}

int cnt;
int idx[N];
int rev[N];

int ans;
int add[M + M];
int rest[N];
vector < pair < int, int > > vals[M + M];

void update(int l, int r, int d){
	int pre = l, ok = 0, t;
	while(pre <= r && pre % M != 1) {
		++pre;
		ok = 1;
		t = (l - 1) / M;
	}
	while(pre + M - 1 <= r) {
		int t = pre / M;
		ans -= lower_bound(vals[t].begin(), vals[t].end(), make_pair(0, -add[t])) - vals[t].begin();
		add[t] += d;
		ans += lower_bound(vals[t].begin(), vals[t].end(), make_pair(0, -add[t])) - vals[t].begin();
		pre += M;
	}
	
	if(pre <= r) {
		int t = (pre - 1) / M;
		ans -= lower_bound(vals[t].begin(), vals[t].end(), make_pair(0, -add[t])) - vals[t].begin();
		vals[t].clear();
		for(int i = pre; (i - 1) / M == t && i <= n; ++i){
			b[i] += add[t] + (i <= r) * d;
			//cout << i << " " << b[i] << " " << add[t] << " " << d << endl;
			vals[t].emplace_back(rest[rev[i]], b[i]);
			ans += (b[i] < 0 && !rest[rev[i]]);
		}
		sort(vals[t].begin(), vals[t].end());
		add[t] = 0;
	}
	if(ok){
		ans -= lower_bound(vals[t].begin(), vals[t].end(), make_pair(0, -add[t])) - vals[t].begin();
		vals[t].clear();
		for(int i = t * M + 1; i <= (t + 1) * M && i <= n; ++i){
			b[i] += add[t] + d * (i >= l && i <= r);
			ans += (!rest[rev[i]] && b[i] < 0);
			vals[t].emplace_back(rest[rev[i]], b[i]);
		}
		sort(vals[t].begin(), vals[t].end());
		add[t] = 0;
	}
	//if(l == 1) exit(0);
}

void hld(int u){
	idx[u] = ++cnt;
	rev[cnt] = u;
	if(g[u].empty()) return;
	
	nxt[g[u][0]] = nxt[u];
	hld(g[u][0]);
	
	for(int i = 1; i < g[u].size(); ++i){
		nxt[g[u][i]] = g[u][i];
		hld(g[u][i]);
	}
}

void go(int u, int val){
	if(u == 0) return;
	update(idx[nxt[u]], idx[u], val);
	go(parent[nxt[u]], val);
}

int main(){

	scanf("%d%d", &n, &m);
	for(int i = 2; i <= n; ++i){
		int p;
		scanf("%d", &p);
		parent[i] = p;
		g[p].push_back(i);
	}
	
	for(int i = 1; i <= n; ++i){
		scanf("%d", a + i);
	}

	preDfs(1);
	nxt[1] = 1;
	hld(1);
	
	for(int i = 1; i <= n; ++i){
		b[i] = a[rev[i]];
		vals[(i - 1) / M].emplace_back(0, b[i]);
	}
	
	for(int i = 0; i < M + M; ++i) sort(vals[i].begin(), vals[i].end());
		
	while(m--){
		int k;
		scanf("%d", &k);
		
		int t = (idx[abs(k)] - 1) / M;
		
		ans -= lower_bound(vals[t].begin(), vals[t].end(), make_pair(0, -add[t])) - vals[t].begin();
		vals[t].clear();

		
		if(k > 0) {
			rest[k] = 1;
	//		ans -= ((b[idx[k]] + add[(idx[k] - 1) / M]) < 0);
		}
		else{
			rest[-k] = 0;
		//	ans += ((b[idx[-k]] + add[(idx[-k] - 1) / M]) < 0);
		}
		

		
		for(int i = t * M + 1; i <= (t + 1) * M && i <= n; ++i){
//			b[i] += add[t] + d * (i >= l && i <= r);
			b[i] += add[t];
			ans += (!rest[rev[i]] && b[i] < 0);
			vals[t].emplace_back(rest[rev[i]], b[i]);
		}
		
		sort(vals[t].begin(), vals[t].end());
		add[t] = 0;
		
		if(k > 0) go(parent[k], -1);
		else go(parent[-k], 1);
		printf("%d ", ans);
	}
		
	return 0;
}

/* 
cd C:\Users\fakes\OneDrive\My tnh\newStart\
g++ -std=c++11 5.cpp -o r.exe
*/