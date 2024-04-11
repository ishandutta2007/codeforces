#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

template<class T>
using indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

struct FT {
	vector<ll> s;
	FT(int n) : s(n) {}
	void update(int pos, ll dif) {
		for (; pos < sz(s); pos |= pos + 1) s[pos] += dif;
	}
	ll query(int pos) {
		ll res = 0;
		for (; pos > 0; pos &= pos - 1) res += s[pos-1];
		return res;
	}
} tr(0);

#define int long long

int preprocess(string &s) {
	int cur = 0, mn = 0;
	for (char c: s) {
		if (c == '(') cur++;
		else cur--;

		mn = min(mn, cur);
	}
	while (cur > 0) {
		cur--; s.push_back(')');
	}

	mn *= -1;
	string t(mn, '(');

	s = t + s;
	return mn;
}

const int MAXN = 600005;
indexed_set<int> adj[MAXN];
int in[MAXN], out[MAXN], parent[MAXN], id[MAXN], val[MAXN], sum[MAXN];

void make_tree(string s) {
	int petr = 0;
	
	stack<int> dfs;
	dfs.push(0);

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == ')') {
			int now = dfs.top();
			out[i] = now;

			dfs.pop();
			if (dfs.top() > 0) {
				sum[id[dfs.top()]] += val[id[dfs.top()]];
				val[id[dfs.top()]]++;
			}
		} else {
			int now = dfs.top();

			petr++;
			id[petr] = i;
			in[i] = petr;

			parent[petr] = now;
			adj[now].insert(petr);
			dfs.push(petr);
			sum[id[petr]]++;
		}
	}

	tr = FT(s.size() + 2);
	for (int i = 0; i < s.size(); i++) {
		tr.update(i, sum[i]);
	}
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int n, q; cin >> n >> q;
	string s; cin >> s;
	int offset = preprocess(s);	

	make_tree(s);
	while (q--) {
		int t, l, r; cin >> t >> l >> r; l--; r--;
		l += offset; r += offset;

		if (t == 2) {
			int ans = tr.query(r+1) - tr.query(l);

			int valL = in[l], valR = out[r], par = parent[valL];
			int cnt = adj[par].order_of_key(valR);
			cnt -= adj[par].order_of_key(valL);
			ans += cnt*(cnt+1)/2;

			cout << ans << '\n';
		} else {
			int node = in[l], par = parent[node];
			adj[par].erase(adj[par].find(node));
			tr.update(id[node], -sum[id[node]]);

			if (par > 0) {
				tr.update(id[par], -sum[id[par]]);

				val[id[par]]--;
				sum[id[par]] -= val[id[par]];

				tr.update(id[par], sum[id[par]]);
			}
		}
	}

	return 0;
}