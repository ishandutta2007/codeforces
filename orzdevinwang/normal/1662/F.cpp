#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
#define me(f, x) memset(f, x, sizeof(f))
#define uint unsigned int
using namespace std;

const int N = 1e6 + 7; 

int n, a, b, dis[N];
bool vis[N];
queue < int > q;

int curv;
struct seg {
	int mx[N], w[N];
	void build(int x, int L, int R) {
		if(L == R) return mx[x] = w[L], void ();
		int mid = (L + R) >> 1;
		build(x << 1, L, mid);
		build(x << 1 | 1, mid + 1, R);
		mx[x] = max(mx[x << 1], mx[x << 1 | 1]); 
	}
	void add(int x, int L, int R, int l, int r, int w) { // at least w
		if(mx[x] < w) return ;
		if(L == R) {
			if(!vis[L]) dis[L] = curv, q.push(L);
			vis[L] = true, mx[x] = -1e9;
			return ; 
		}
		int mid = (L + R) >> 1;
		if(l <= mid) add(x << 1, L, mid, l, r, w);
		if(r > mid) add(x << 1 | 1, mid + 1, R, l, r, w);
		mx[x] = max(mx[x << 1], mx[x << 1 | 1]);
	}
} A, B;

int p[N];

void Main() {
	cin >> n >> a >> b;
	L(i, 1, n) dis[i] = 1e9;
	L(i, 1, n) cin >> p[i], A.w[i] = p[i] + i, B.w[i] = p[i] - i;
	A.build(1, 1, n);
	B.build(1, 1, n);
	q.push(a), dis[a] = 0, vis[a] = true;
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		curv = dis[u] + 1;
		A.add(1, 1, n, max(u - p[u], 1), u, u);
		B.add(1, 1, n, u, min(u + p[u], n), -u);
	}
	cout << dis[b] << '\n';
	L(i, 1, n) vis[i] = false;
}
int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t--) Main();
	return 0; 
}