#define _CRT_SECURE_NO_WARNINGS
#define fast ios::sync_with_stdio(false); cin.tie(0) 
#define foru(i, k, n) for (int i = k; i < n; i++) 
#define ford(i, k, n) for (int i = k; i >= n; i--) 
#define pb push_back
#define ff first 
#define ss second 

#include <iostream> 
#include <vector> 
#include <algorithm> 
#include <string> 
#include <list> 
#include <queue> 
#include <numeric> 

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<pii, int> dat;
dat foo(const dat& lhs, const dat& rhs) {
	return { {min(lhs.ff.ff,rhs.ff.ff), max(lhs.ff.ss,rhs.ff.ss)}, min(lhs.ss,rhs.ss) };
}
template<class T>
struct rmq {
	vector<vector<T>> a;
	vector<int> logs;
	int dep, len;
	rmq(vector<T> arr) {
		len = arr.size();
		dep = 0;
		int tmp = len;
		while (tmp) {
			tmp >>= 1;
			dep++;
		}
		a.resize(dep);
		foru(i, 0, dep) {
			a[i].resize(len);
			for (int j = 0; j + (1 << i) <= len; j++) {
				if (!i)a[i][j] = arr[j];
				else a[i][j] = foo(a[i - 1][j], a[i - 1][j + (1 << (i - 1))]);
			}
		}
		initLogs();
	}
	void initLogs() {
		logs.resize(len + 1);
		logs[1] = 0;
		foru(i, 2, len + 1)logs[i] = logs[i >> 1] + 1;
	}
	T query(int l, int r) {
		int mylen = logs[r - l + 1];
		return foo(a[mylen][l], a[mylen][r - (1 << mylen) + 1]);
	}
};

const int sz = 1e5 + 5, LOG = 20;
int n, a[sz], rt, dep[sz], pos[sz];
vector<int> adj[sz];
vector<int> ord;
vector<dat> fl[LOG];
rmq<dat>* arr[LOG];

void input() {
	scanf("%d %d", &n, &rt); rt--;
	foru(i, 0, n)scanf("%d", &a[i]);
	foru(i, 0, n - 1) {
		int x, y;
		scanf("%d %d", &x, &y);
		adj[--x].pb(--y);
		adj[y].pb(x);
	}
}

void bfs() {
	queue<int> q;
	vector<bool> vis(n);
	q.push(rt);
	int tmp;
	fl[0].resize(n);
	while (!q.empty()) {
		int src = q.front(); q.pop();
		vis[src] = 1;
		tmp = ord.size();
		pos[src] = tmp;
		ord.pb(src);
		if (adj[src].size() == 1 && src != rt)
			fl[0][tmp] = { { n,-1 },a[src] };
		else {
			fl[0][tmp] = { {tmp + q.size() + 1,tmp + q.size() + 1},a[src] };
			for (int x : adj[src]) {
				if (vis[x])continue;
				q.push(x);
				dep[x] = dep[src] + 1;
			}
			fl[0][tmp].ff.ss = tmp + q.size();
		}
	}
}

void initrmq() {
	int il, ir;
	arr[0] = new rmq<dat>(fl[0]);
	for (int i = 1; i < LOG; i++) {
		fl[i].resize(n);
		for (int j = 0; j < n; j++) {
			fl[i][j] = arr[i - 1]->a[0][j];
			il = fl[i - 1][j].ff.ff, ir = fl[i - 1][j].ff.ss;
			if (il >= 0 && il < n&&
				ir >= 0 && ir < n) {
				fl[i][j].ff = arr[i - 1]->query(il, ir).ff;
				fl[i][j].ss = min(fl[i][j].ss, arr[i - 1]->query(il, ir).ss);
			}
			else 
				fl[i][j].ff = { n,-1 };
		}
		arr[i] = new rmq<dat>(fl[i]);
	}
}

int ask(int x, int k) {
	dat cur = { {pos[x],pos[x]},a[x] };
	for (int i = 0; i < LOG; i++) {
		if ((k >> i) & 1) {
			dat tmp = arr[i]->query(cur.ff.ff, cur.ff.ss);
			cur.ss = min(cur.ss, tmp.ss);
			cur.ff = tmp.ff;
			if (cur.ff.ff < 0 || cur.ff.ff >= n || cur.ff.ss < 0 || cur.ff.ss >= n)break;
		}
	}
	return cur.ss;
}

int main() {
	fast;
	input();
	bfs();
	initrmq();
	int m, last = 0, p, q, xi, ki;
	scanf("%d", &m);
	while (m--) {
		scanf("%d %d", &p, &q);
		xi = (p + last) % n + 1;
		ki = (q + last) % n;
		last = ask(--xi, ++ki);
		printf("%d\n", last);
	}
	return 0;
}