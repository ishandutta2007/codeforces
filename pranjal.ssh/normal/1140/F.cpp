#include <bits/stdc++.h>
using namespace std;

#define cerr cout
#define F first
#define S second
#define FOR(i,a,b) for (auto i = (a); i <= (b); ++i)
#define NFOR(i,a,b) for(auto i = (a); i >= (b); --i)
#define all(x) (x).begin(), (x).end()
#define sz(x) int(x.size())
typedef long long ll; typedef pair <int, int> ii; typedef vector <int> vi; const int inf = 1e9 + 7;
string to_string(string s) { return '"' + s + '"';}
string to_string(char s) { return string(1, s);}
string to_string(const char* s) { return to_string((string) s);}
string to_string(bool b) { return (b ? "true" : "false");}
template <typename A> string to_string(A);
template <typename A, typename B>string to_string(pair<A, B> p) {return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";}
template <typename A> string to_string(A v) {bool f = 1; string r = "{"; for (const auto &x : v) {if (!f)r += ", "; f = 0; r += to_string(x);} return r + "}";}
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) {cerr << " " << to_string(H); debug_out(T...);}
#define pr(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

struct DSU {
	vector<ll> p, r, x, y;
	ll sum;
	stack<tuple<ll, ll*,ll>> st;
	DSU(int n):p(n),r(n), x(n), y(n), sum(0) {
		FOR(i, 0, n - 1) {
			p[i] = i;
			if (i & 1) y[i]++;
			else x[i]++;
		}
	}

	int get(int i) {
		while (p[i] != i) i = p[i];
		return p[i];
	}

	int connect(int i, int j, int version) {
		
		int u = get(i), v = get(j);
		if (u == v) return 0;
		if (r[u] > r[v]) swap(u, v);

		st.emplace(make_tuple(version, &p[u], p[u]));

		st.emplace(make_tuple(version, &x[v], x[v]));
		st.emplace(make_tuple(version, &y[v], y[v]));

		st.emplace(make_tuple(version, &sum, sum));
		st.emplace(make_tuple(version, &r[v], r[v]));

		p[u] = v;
		sum -= x[u]*1LL*y[u];
		sum -= x[v]*1LL*y[v];

		x[v] += x[u], y[v] += y[u];
		sum += x[v]*1LL*y[v];

		if (r[u] == r[v]) ++r[v];
		return 1;
	}

	void rollback(int version) {
		while (!st.empty() and std::get<0>(st.top()) == version) {
			*std::get<1>(st.top()) = std::get<2>(st.top());
			st.pop();
		}
	}
};

const int N = 3e5 + 10;
vector<ii> s[4*N];
map<int, int> mp[N + 10];

void upd(int no, int l, int r, int u, int v, int x, int y) {
	if (r < u or l > v) return;
	if (l >= u and r <= v) {
		s[no].emplace_back(x, y);
		return;
	}
	int mid = (l+r)>>1;
	upd(no<<1, l, mid, u, v, x, y);
	upd(no<<1|1, mid+1, r, u, v, x, y);
}
DSU ds(2*N+10);

void dfs(int no, int l, int r) {
	for (auto it: s[no]) {
		ds.connect(it.F, it.S, no);
	}
	if (l == r) {
		cout << ds.sum << " ";
	} else {
		int mid = (l+r)>>1;
		dfs(no<<1, l, mid);
		dfs(no<<1|1, mid+1, r);
	}
	ds.rollback(no);
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int q; cin >> q;
	FOR (i, 1, q) {
		int x, y; cin >> x >> y;
		if (mp[x].count(y)) {
			upd(1, 1, q, mp[x][y], i-1, 2*x, 2*y+1);
			mp[x].erase(y);
		} else {
			mp[x][y] = i;
		}
	}
	FOR (i, 1, N) for (auto it: mp[i]) upd(1, 1, q, it.S, q, 2*i, 2*it.F+1);

	dfs(1, 1, q);

	
	return 0;
}