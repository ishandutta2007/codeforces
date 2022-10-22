#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=1e5;
int n, q, s[mxN], cur;
pair<int, bool> p[mxN];
map<ar<int, 2>, int> mp;
vector<ar<int, 2>> edges[1<<18];
stack<ar<int, 3>> st;
bool bad[mxN];

void upd(int ql, int qr, ar<int, 2> e, int u=1, int l=0, int r=q-1) {
	//if (l==0&&r==q-1)
	//	cout << e[0] << "-" << e[1] << " [" << ql << ", " << qr << "]\n";
	if (ql<=l&&r<=qr) {
		edges[u].push_back(e);
		return;
	}
	int mid=(l+r)/2;
	if (ql<=mid)
		upd(ql, qr, e, 2*u, l, mid);
	if (qr>mid)
		upd(ql, qr, e, 2*u+1, mid+1, r);
}

pair<int, bool> find(int i) {
	bool par=0;
	for (; i^p[i].first; par^=p[i].second, i=p[i].first);
	return {i, par};
}

void mrg(int u, int v) {
	bool par1, par2;
	tie(u, par1)=find(u);
	tie(v, par2)=find(v);
	bool d=par1^par2^1;
	if (u==v) {
		if (!bad[u]&&d) {
			bad[u]=1, ++cur;
			st.push({u, u});
		}
		return;
	}
	if (s[u]<s[v])
		swap(u, v);
	st.push({u, v, bad[u]});
	cur-=bad[u], cur-=bad[v];
	p[v]={u, d}, s[u]+=s[v];
	bad[u]|=bad[v], cur+=bad[u];
}

void solve(int u=1, int l=0, int r=q-1) {
	//cout << l << " " << r << endl;
	int k=st.size();
	for (ar<int, 2> e : edges[u])
		mrg(e[0], e[1]);
	if (l==r) {
		cout << (cur?"NO":"YES") << "\n";
	} else {
		int mid=(l+r)/2;
		solve(2*u, l, mid);
		solve(2*u+1, mid+1, r);
	}
	for (; st.size()>k; st.pop()) {
		int a=st.top()[0], b=st.top()[1];
		if (a==b) {
			--cur, bad[a]=0;
		} else {
			cur-=bad[a];
			bad[a]=st.top()[2];
			p[b]={b, 0}, s[a]-=s[b];
			cur+=bad[a], cur+=bad[b];
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> q;
	for (int i=0; i<q; ++i) {
		int u, v;
		cin >> u >> v, --u, --v;
		ar<int, 2> uv={min(u, v), max(u, v)};
		auto it=mp.lower_bound(uv);
		if (it==mp.end()||it->first!=uv) { // add
			mp.insert(it, {uv, i});
		} else {
			upd(it->second, i-1, uv);
			mp.erase(it);
		}
	}
	for (auto& x : mp)
		upd(x.second, q-1, x.first);
	for (int i=0; i<n; ++i) {
		p[i]={i, 0};
		s[i]=1;
	}
	solve();
	return 0;
}