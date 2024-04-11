#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int> 
#define sz(a) ((int) (a).size())
#define me(f, x) memset(f, x, sizeof(f))
using namespace std;

const int N = 5e5 + 7; 

int n, k, q, T;

int ehd[N], ev[N], ew[N], enx[N], eid;
void eadd (int u, int v, int w) {
	++eid, ev[eid] = v, enx[eid] = ehd[u], ew[eid] = w, ehd[u] = eid;
}

int a[N], b[N], z[N];
char s[N];

int fa[N]; 
ll dis[N];

const int M = N * 25; 
int hd[N], ch[M][2], tot;
int merge(int x, int y) {
	if(!x || !y) return x | y;
	int nw = ++tot;
	ch[nw][0] = merge(ch[x][0], ch[y][0]);
	ch[nw][1] = merge(ch[x][1], ch[y][1]);
	return nw;	
}  
bool query(int x, int L, int R, int l, int r) {
	if(!x) return false;
	if(l <= L && R <= r) return true;
	int mid = (L + R) >> 1;
	if(l <= mid && query(ch[x][0], L, mid, l, r)) return true;
	if(r > mid && query(ch[x][1], mid + 1, R, l, r)) return true; 
	return false;
}
void add(int &x, int L, int R, int p) {
	x = ++tot;
	if(L == R) return ;
	int mid = (L + R) >> 1;
	p <= mid ? add(ch[x][0], L, mid, p) : add(ch[x][1], mid + 1, R, p);
} 

int tp[N];
ll tc[N][28];
int col[N][28];
void dfs(int x) {
//	cout << x << " : " << dis[x] % T << '\n';
	add(hd[x], 0, T - 1, dis[x] % T);
	for(int i = ehd[x]; i; i = enx[i]) if(ev[i] != fa[x]) {
		fa[ev[i]] = x, dis[ev[i]] = dis[x] + ew[i];
		
		tp[ev[i]] = tp[x];
		L(j, 1, tp[x]) tc[ev[i]][j] = tc[x][j], col[ev[i]][j] = col[x][j];
		if(z[ev[i]] != z[x]) {
			++tp[ev[i]];
			tc[ev[i]][tp[ev[i]]] = dis[x];
			col[ev[i]][tp[ev[i]]] = z[x];
		}
		
		dfs(ev[i]);
		
		if(z[x] == z[ev[i]]) 
			hd[x] = merge(hd[x], hd[ev[i]]);
	}
}

int main () {
	ios :: sync_with_stdio(false);
	cin.tie (0); cout.tie (0);
	cin >> n ;
	
	L(i, 1, n - 1) {
		int u, v, w;
		cin >> u >> v >> w;
		eadd (u, v, w);
		eadd (v, u, w); 
	}
	
	cin >> k;
	cin >> (s + 1);
	L(i, 1, n) z[i] = s[i] - 'A';
	
	L(i, 0, k - 1) cin >> a[i];
	L(i, 0, k - 1) cin >> b[i];
	
	cin >> T;
	
	dfs(1);
	
	cin >> q;
	while(q--) {
		int op;
		char s[5];
		cin >> op;
		if(op == 1) {
			cin >> (s + 1);
			cin >> a[s[1] - 'A'];
		} else if(op == 2) {
			cin >> (s + 1);
			cin >> b[s[1] - 'A'];
		} else {
			int x;
			cin >> x;
			
			ll all = 0;
			vector < pair < int, ll > > V;
		
//			cout << "LG zhe me you shi li de ma \n";
			L(i, 1, tp[x]) {
				ll l = tc[x][i] + 1, r = tc[x][i - 1] + 1;	
				
//				cout << l << " to " << r << '\n';	
				
				vector < pair < int, ll > > vc;
				vc.emplace_back(make_pair(l % T, -1));
				vc.emplace_back(make_pair(r % T, 1));
				sort(vc.begin(), vc.end());
				
				ll sum = l / T - r / T;
				
				ll lst = sum > a[col[x][i]] / b[col[x][i]] ? a[col[x][i]] : 
					sum * b[col[x][i]]; 
				
				all += lst;
				
				for(auto u : vc) {
					sum += u.second;
					ll v = sum > a[col[x][i]] / b[col[x][i]] ? a[col[x][i]] : 
						sum * b[col[x][i]]; 
					V.emplace_back(make_pair(u.first, v - lst));
					lst = v;
				}
			}
			
			V.emplace_back(make_pair(0, all));
			sort(V.begin(), V.end());
			
			V.emplace_back(make_pair(T, -1));
			
			all = 0;
			ll ns = 2e18;
			L(i, 0, sz(V) - 2) {
				all += V[i].second;
				
				if(V[i].first < V[i + 1].first && 
					query(hd[x], 0, T - 1, V[i].first, V[i + 1].first - 1)) ns = min(ns, all);
			}
			
			cout << ns << '\n'; 
		}
	}
	return 0;
}