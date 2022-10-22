#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=1e5;
const ll INF=1e18;
int n, a[mxN], b[mxN];
vector<int> adj[mxN];
ll dp[mxN];

struct Line {
	ll m, b;
	mutable ll x;
	bool operator<(const Line& o) const {
		return m>o.m;
	}
	bool operator<(ll x2) const {
		return x<x2;
	}
};

struct CHT {
	set<Line, less<>> st; // less<>
	ll ix(set<Line>::iterator it1, set<Line>::iterator it2) {
		assert(it1->m>it2->m);
		ll x=it1->m-it2->m, y=it2->b-it1->b;
		return y>=0?(y+x-1)/x:y/x;
	}
	bool bad(set<Line>::iterator it) {
		if (it==st.begin()||next(it)==st.end())
			return 0;
		return ix(it, next(it))<=ix(prev(it), it); // next line overtakes faster than current line can overtake last
	}
	void ins(ll m, ll b) {
		Line cur={m, b};
		auto it=st.lower_bound(cur);
		if (it!=st.end()&&it->m==m) {
			if (it->b<=b)
				return;
			it=st.erase(it);
		}
		it=st.insert(it, cur);
		while(next(it)!=st.end()&&bad(next(it)))
			st.erase(next(it));
		while(it!=st.begin()&&bad(prev(it)))
			st.erase(prev(it));
		if (bad(it)) {
			it=st.erase(it);
			assert(it!=st.end()&&it!=st.begin());
			it->x=ix(prev(it), it);
			return;
		}
		it->x=it==st.begin()?-INF:ix(prev(it), it);
		if (next(it)!=st.end())
			next(it)->x=ix(it, next(it));
	}
	ll qry(ll x) {
		assert(st.size());
		auto it=st.lower_bound(x);
		if (it==st.end()||it->x>x) {
			assert(it!=st.begin());
			--it;
		}
		return it->m*x+it->b;
	}
} lines[mxN];

void dfs(int u=0, int p=-1) {
	if (u&&adj[u].size()==1) {
		lines[u].ins(b[u], 0);
		return;
	}
	for (int v : adj[u])
		if (v!=p) {
			dfs(v, u);
			if (lines[v].st.size()>lines[u].st.size())
				swap(lines[u].st, lines[v].st);
			for (Line l : lines[v].st)
				lines[u].ins(l.m, l.b);
			set<Line, less<>>().swap(lines[v].st);
		}
	dp[u]=lines[u].qry(a[u]);
	lines[u].ins(b[u], dp[u]);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> a[i];
	for (int i=0; i<n; ++i)
		cin >> b[i];
	for (int i=1; i<n; ++i) {
		int u, v;
		cin >> u >> v, --u, --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs();
	for (int i=0; i<n; ++i)
		cout << dp[i] << " ";
	return 0;
}