#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=3e5;
int n, q, p[mxN], s[mxN], c[mxN][2];
ar<int, 2> a[mxN];
set<ar<int, 2>> xs[mxN], ys[mxN];
ll ans[mxN], cur_ans;
map<ar<int, 3>, int> mp;
vector<ar<int, 3>> edges[1<<20];
stack<ar<int, 2>> st;

int nxt(set<ar<int, 2>>::iterator it) {
	return (*next(it))[1];
}
int prv(set<ar<int, 2>>::iterator it) {
	return (*prev(it))[1];
}

void upd(int ql, int qr, ar<int, 3> e, int u=1, int l=0, int r=q-1) {
	//if (l==0&&r==q-1)
	//	cout << "edge " << e[0] << " " << e[1] << " " << e[2] << " " << ql << " " << qr << "\n";
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

int find(int i) {
	for (; i^p[i]; i=p[i]);
	return i;
}

void calc(int u, ll inc) {
	cur_ans+=inc*c[u][0]*c[u][1];
}

bool mrg(ar<int, 3> e) {
	int u=find(e[0]), v=find(e[1]), t=e[2];
	if (u==v) {
		calc(u, -1);
		--c[u][t];
		calc(u, 1);
		return 0;
	}
	if (s[u]<s[v])
		swap(u, v);
	calc(v, -1);
	calc(u, -1);
	p[v]=u;
	s[u]+=s[v];
	c[u][0]+=c[v][0];
	c[u][1]+=c[v][1];
	--c[u][t];
	calc(u, 1);
	st.push({u, v});
	return 1;
}

void solve(int u=1, int l=0, int r=q-1) {
	vector<bool> merged;
	merged.reserve(edges[u].size());
	for (ar<int, 3> e : edges[u])
		merged.push_back(mrg(e));
	if (l==r) {
		ans[l]+=cur_ans;
	} else {
		int mid=(l+r)/2;
		solve(2*u, l, mid);
		solve(2*u+1, mid+1, r);
	}
	for (int i=(int)edges[u].size()-1; ~i; --i) {
		int a=edges[u][i][0], b=edges[u][i][1], t=edges[u][i][2];
		if (merged[i]) {
			a=st.top()[0], b=st.top()[1];
			calc(a, -1);
			++c[a][t];
			p[b]=b;
			s[a]-=s[b];
			c[a][0]-=c[b][0];
			c[a][1]-=c[b][1];
			calc(a, 1);
			calc(b, 1);
			st.pop();
		} else {
			a=find(a);
			calc(a, -1);
			++c[a][t];
			calc(a, 1);
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> q;
	for (int i=0; i<q; ++i)
		cin >> a[i][0] >> a[i][1], --a[i][0], --a[i][1];
	vector<ar<int, 2>> all(a, a+q);
	sort(all.begin(), all.end());
	all.resize(unique(all.begin(), all.end())-all.begin());
	n=all.size();
	for (int i=0, cnt=0; i<q; ++i) {
		//cout << "on " << i << endl;
		auto Add=[&](int u, int v, int type) {
			ar<int, 3> cur={min(u, v), max(u, v), type};
			//cout << "add " << cur[0] << " " << cur[1] << " " << cur[2] << endl;
			mp[cur]=i;
		};
		auto Rem=[&](int u, int v, int type) {
			ar<int, 3> cur={min(u, v), max(u, v), type};
			//cout << "rem " << cur[0] << " " << cur[1] << " " << cur[2] << endl;
			auto it=mp.find(cur);
			upd(it->second, i-1, cur);
			mp.erase(it);
		};
		int x=a[i][0], y=a[i][1];
		int u=lower_bound(all.begin(), all.end(), a[i])-all.begin();
		auto it=xs[x].lower_bound({y});
		if (it!=xs[x].end()&&(*it)[0]==y) { // remove point
			--cnt;

			if (next(it)!=xs[x].end())
				Rem(u, nxt(it), 0);
			if (it!=xs[x].begin())
				Rem(u, prv(it), 0);
			if (next(it)!=xs[x].end()&&it!=xs[x].begin())
				Add(prv(it), nxt(it), 0);
			xs[x].erase(it);

			it=ys[y].lower_bound({x});
			if (next(it)!=ys[y].end())
				Rem(u, nxt(it), 1);
			if (it!=ys[y].begin())
				Rem(u, prv(it), 1);
			if (next(it)!=ys[y].end()&&it!=ys[y].begin())
				Add(prv(it), nxt(it), 1);
			ys[y].erase(it);
		} else {
			++cnt;

			if (it!=xs[x].end())
				Add(u, (*it)[1], 0);
			if (it!=xs[x].begin())
				Add(u, prv(it), 0);
			if (it!=xs[x].end()&&it!=xs[x].begin())
				Rem(prv(it), (*it)[1], 0);
			xs[x].insert({y, u});

			it=ys[y].lower_bound({x});
			if (it!=ys[y].end())
				Add(u, (*it)[1], 1);
			if (it!=ys[y].begin())
				Add(u, prv(it), 1);
			if (it!=ys[y].end()&&it!=ys[y].begin())
				Rem(prv(it), (*it)[1], 1);
			ys[y].insert({x, u});
		}
		ans[i]=cnt-n;
		//cout << "finished " << i << endl;
	}
	for (auto& x : mp)
		upd(x.second, q-1, x.first);
	cur_ans=n;
	for (int i=0; i<n; ++i) {
		p[i]=i;
		s[i]=1;
		c[i][0]=c[i][1]=1;
	}
	solve();
	for (int i=0; i<q; ++i)
		cout << ans[i] << " ";
	return 0;
}