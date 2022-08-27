#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
#define me(f, x) memset(f, x, sizeof(f))
#define uint unsigned int
using namespace std;
const int N = 1e6 + 7, M = 2e5 + 7;
ll ns[N];
struct fenwt {
	int n;
	vector < pair < int, ll > > qwq[M];
	vector < pair < int, pair < int, ll > > > qry[M];
	ll sum[N];
	void add(int x, int y, ll w) {
		qwq[x].emplace_back(make_pair(y, w));
	}
	void query(int x, int y, int id, ll buf) {
		qry[x].emplace_back(make_pair(y, make_pair(id, buf)));
	}
	void ADD(int x, ll w) {
		for(; x <= n; x += x & -x) 
			sum[x] += w;
	}
	ll QRY(int x) {
		ll ret = 0;
		for (; x; x -= x & -x) 
			ret += sum[x];
		return ret;
	}
	void slv() {
		L(i, 1, n) {
			for(auto v : qwq[i]) 
				ADD(v.first, v.second);
			for(auto v : qry[i]) 
				ns[v.second.first] += v.second.second * QRY(v.first);
		} 
	}
} h[2][2];
void ADD (int x, int y, ll w) {
	L(a, 0, 1) L(b, 0, 1) 
		h[a][b].add (x, y, (ll) w * (a == 0 ? 1 : x) * (b == 0 ? 1 : y));
}
void Get (int x, int y, int id) {
	L(a, 0, 1) L(b, 0, 1) 
		h[a][b].query(x, y, id, (ll) (a == 0 ? x + 1 : -1) * (b == 0 ? y + 1 : -1));
}

int n, m, p[N], mp[N], tol[N], tor[N], stk[N], tp;
vi qwq[N]; 
vector < pair < int, int > > vc[N];
int main () {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);	
	cin >> n >> m;
	L(i, 1, n) cin >> p[i], mp[p[i]] = i;
	L(i, 1, n) tor[i] = n + 1;
	tp = 0;
	L(i, 1, n) {
		while(tp > 0 && p[i] > p[stk[tp]]) tor[stk[tp]] = i, --tp;
		tol[i] = stk[tp], stk[++tp] = i;
	}
	L(i, 0, 1) 
		L(j, 0, 1) 
			h[i][j].n = n;
	L(i, 1, n) 
		L(j, 1, n / i) if(i < j) {
			int L = min(min(mp[i], mp[j]), mp[i * j]);
			int R = max(max(mp[i], mp[j]), mp[i * j]);
			int gl = tol[mp[i * j]], gr = tor[mp[i * j]];
			++gl, --gr;
			if(gl <= L && R <= gr) {
				L = n - L + 1, gl = n - gl + 1;
				vc[i * j].emplace_back(make_pair(L, R));
//				int a = L, b = R, c = gl, d = gr;
//				ADD (c + 1, d + 1, 1);
//				ADD (a, d + 1, -1);
//				ADD (c + 1, b, -1);
//				ADD (a, b, 1);
//				cout << a << ' ' << b << " to " << c << ' ' << d << endl;
			}
//			 
		}
	L(i, 1, n) if(sz(vc[i])) {
		int gl = tol[mp[i]], gr = tor[mp[i]];
		++gl, --gr, gl = n - gl + 1;
		
		vi pos, tk;
		for(auto u : vc[i]) pos.emplace_back(u.first), tk.emplace_back(gr);
		sort(pos.begin(), pos.end()), reverse(pos.begin(), pos.end());
		for(auto u : vc[i]) 
			L(j, 0, sz(pos) - 1) if(pos[j] >= u.first) 
				tk[j] = min(tk[j], u.second);
		int lst = gl;
		L(i, 0, sz(pos) - 1) {
			int a = pos[i], b = tk[i], c = lst, d = gr;
			ADD (c + 1, d + 1, 1);
			ADD (a, d + 1, -1);
			ADD (c + 1, b, -1);
			ADD (a, b, 1);
			lst = pos[i] - 1;
		}
	}
	L(i, 1, m) {
		int l, r;
		cin >> l >> r;
		Get(n - l + 1, r, i);
	}
	L(i, 0, 1) L(j, 0, 1) h[i][j].slv();
	L(i, 1, m) 
		cout << ns[i] << '\n';
	return 0;
}