#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define FOR(i,a,b) for (int i = (a); i <= (b); ++i)
#define NFOR(i,a,b) for(int i = (a); i >= (b); --i)
#define all(x) (x).begin(), (x).end()
#define sz(x) int(x.size())
typedef long long ll; typedef pair <int, int> ii; typedef vector <int> vi; const int inf = 1e9 + 7;
#define pr(...) dbs(#__VA_ARGS__, __VA_ARGS__)
template <class T> void dbs(string str, T t) {cout << str << " : " << t << endl;}
template <class T, class... S> void dbs(string str, T t, S... s) {int idx = str.find(','); cout << str.substr(0, idx) << " : " << t << ","; dbs(str.substr(idx + 1), s...);}
template <class S, class T>ostream& operator <<(ostream& os, const pair<S, T>& p) {return os << "(" << p.first << ", " << p.second << ")";}
template <class T>ostream& operator <<(ostream& os, const vector<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T>ostream& operator <<(ostream& os, const set<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class S, class T>ostream& operator <<(ostream& os, const map<S, T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T> void prc(T a, T b) {cout << "["; for (T i = a; i != b; ++i) {if (i != a) cout << ", "; cout << *i;} cout << "]" << endl;}

const int N = 1e5 + 10;
int vis[N];
ll d[N];
vector<pair<ii, int>> to[N];
struct ST {
#define mid ((l+r)>>1)
#define L(no) ((no) << 1)
#define R(no) ((no) << 1 | 1)

	struct node {
		ll val, lazy;
		vector<ii> to;
		node(): val(1e18), lazy(1e18) {}
	};

	int n;
	vector<node> T;

	ST(int n = 0): n(n), T(4 * n + 10) {}

	inline void LAZY(int no, int l, int r) {
		if (T[no].val == 2e18) return;
		T[no].val = min(T[no].val, T[no].lazy);
		if (l != r) {
			T[L(no)].lazy = min(T[no].lazy, T[L(no)].lazy);
			T[R(no)].lazy = min(T[no].lazy, T[R(no)].lazy);
		}
		T[no].lazy = 2e18;
	}

	void upd(int no, int l, int r, int pos, ll val) {  //point
		LAZY(no, l, r);
		if (pos > r or pos < l) return;
		if (l == r) {T[no].val = val; return;}
		upd(L(no), l, mid, pos, val);
		upd(R(no), mid + 1, r, pos, val);
		T[no].val = min(T[L(no)].val, T[R(no)].val);
	}

	pair<ll, int> qry(int no, int l, int r) {
		LAZY(no, l, r);
		if (l == r)return make_pair(T[no].val, l);
		LAZY(L(no),l,mid), LAZY(R(no),mid+1,r);
		if (T[L(no)].val <= T[R(no)].val)
			return qry(L(no), l, mid);
		return qry(R(no), mid + 1, r);
	}

	void updr(int no, int l, int r, int u, int v, ll val) {
		LAZY(no, l, r);

		if (l >= u and r <= v) {T[no].lazy = val ; LAZY(no, l, r); return;}
		if (r < u or l > v) return;

		updr(L(no), l, mid, u, v, val), updr(R(no), mid + 1, r, u, v, val);
		T[no].val = min(T[L(no)].val, T[R(no)].val);
	}

	void mark(int no, int l, int r, int u, int v, int w, int x) {
		if (l >= u and r <= v) {T[no].to.emplace_back(w, x); return;}
		if (r < u or l > v) return;
		mark(L(no), l, mid, u, v, w, x), mark(R(no), mid + 1, r, u, v, w, x);
	}

	void clear(int no, int l, int r, int pos) {
		for (ii& it : T[no].to) {
			updr(1, 1, n, it.F, it.F, d[pos] + it.S);
		}
		T[no].to.clear();
		if (l == r) return;
		if (pos <= mid) return clear(L(no), l, mid, pos);
		return clear(R(no), mid+1, r, pos);
	}

#undef mid
#undef L
#undef R
};


int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

	int n, q, s; cin >> n >> q >> s;
	ST tree(n);
	while (q--) {
		int t, l, r, u, v, w; cin >> t;
		if (t == 1) {
			cin >> v >> u >> w;
			to[v].emplace_back(ii(u, u), w);
		}
		else {
			cin >> v >> l >> r >> w;
			if (t == 2) {
				to[v].emplace_back(ii(l, r), w);
			}
			else {
				tree.mark(1, 1, n, l, r, v, w);
			}
		}
	}
	FOR (i, 1, n) d[i] = 2e18;
	d[s] = 0;
	tree.upd(1, 1, n, s, 0);

	FOR (i, 1, n) {
		auto now = tree.qry(1, 1, n);

		if (now.F >= 1e18)break;
		d[now.S] = now.F;
		for (auto& it: to[now.S]) {
			tree.updr(1, 1, n, it.F.F, it.F.S, it.S + now.F);
		}
		tree.clear(1, 1, n, now.S);
		tree.upd(1, 1, n, now.S, 2e18);
		vis[now.S] = 1;
	}
	FOR (i, 1, n) {
		if (d[i] >= 1e18) d[i] = -1;
		cout << d[i] << " \n"[i == n];
	}


	return 0;
}