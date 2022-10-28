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
template <class T> void prc(T a, T b) {cout << "["; for (T i = a; i != b; ++i) {if (i != a) cout << ", "; cout << *i;} cout << "]"; cout << endl;}


template<class node>
struct ST {
#define mid ((l+r)>>1)
	int n;
	vector<node> T;
	ST(int n): n(n), T(4 * n + 10) {}

	inline void resolve(int no, int l, int r) {
		T[no].sum += T[no].lazy;
		T[no].mx.F += T[no].lazy;
		if (l != r) {
			T[no << 1].lazy += T[no].lazy ;
			T[no << 1 | 1].lazy += T[no].lazy ;
		}
		T[no].lazy = 0;
	}

	void build(int no, int l, int r) {
		if (l == r) {
			T[no].mx.S = l;
			return;
		}
		build(no << 1, l, mid), build(no << 1 | 1, mid + 1, r);
		T[no] = T[no << 1] + T[no << 1 | 1];
	}

	node qry(int no, int l, int r, int u, int v) {
		resolve(no, l, r);

		if (l >= u and r <= v)return T[no];
		if (v <= mid) {if (l != r)resolve(no << 1 | 1, mid + 1, r); return qry(no << 1, l, mid, u, v);}
		else if (u >= mid + 1) {if (l != r)resolve(no << 1, l, mid); return qry(no << 1 | 1, mid + 1, r, u, v);}

		return qry(no << 1, l, mid, u, v) + qry(no << 1 | 1, mid + 1, r, u, v);
	}

	void updr(int no, int l, int r, int u, int v, int val) {
		resolve(no, l, r);

		if (l >= u and r <= v) {T[no].lazy = val ; resolve(no, l, r); return;}
		if (r < u or l > v) return;

		updr(no << 1, l, mid, u, v, val), updr(no << 1 | 1, mid + 1, r, u, v, val);
		T[no] = T[no << 1] + T[no << 1 | 1];
	}
#undef mid
};


struct node {
	/*FUCK*/
	int sum, lazy;
	ii mx;
	node(int sum = 0, int lazy = 0, ii mx = {0, 0}): sum(sum), lazy(lazy), mx(mx) {}
	node operator +(const node&rhs) {
		return node(sum + rhs.sum, 0, max(mx, rhs.mx));
	}
};



struct worker {
	int l, v, r, id;
};

struct event {
	int x;
	int l, r;
	int val;
	event(int x = 0, int l = 0, int r = 0, int val = 0) : x(x), l(l), r(r), val(val) {}
};
const int N = 3e5;
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

	int n; cin >> n;

	vector<worker> a(n);
	vector<event> e;
	FOR (i, 0, n - 1) {
		cin >> a[i].l >> a[i].v >> a[i].r;
		a[i].id = i;
		e.emplace_back(a[i].l, a[i].v, a[i].r, 1);
		e.emplace_back(a[i].v, a[i].v, a[i].r, -1);
	}

	sort(all(e), [](const event & x, const event & y) {
		return x.x == y.x ? x.val > y.val : x.x < y.x;
	});

	ST<node> T(N);
	T.build(1, 1, N);

	pair<int, ii> ans;
	for (auto it : e) {
		T.updr(1, 1, N, it.l, it.r, it.val);
		ii val = T.qry(1, 1, N, 1, N).mx;
		ans = max(ans, make_pair(val.F, ii(it.x, val.S)));
	}
	cout << ans.F << "\n";
	
	for (auto it : a) {
		if (it.v >= ans.S.F and it.v <= ans.S.S and it.l <= ans.S.F and it.r >= ans.S.S) {
			cout << it.id + 1 << " ";
		}
	}

	return 0;
}