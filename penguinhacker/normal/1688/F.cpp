#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=2e5;
int n, m, a[mxN];
ll p[mxN+1];
ar<int, 2> seg[mxN];
set<int> s;
vector<int> todo[mxN+1];
queue<int> q;

void ck(int i) {
	s.erase(i);
	for (int j : todo[i])
		if (p[seg[j][0]]==0&&p[seg[j][1]+1]==0)
			q.push(j);
}

void solve() {
	cin >> n >> m;
	for (int i=0; i<n; ++i)
		cin >> a[i], a[i]*=-1;
	for (int i=0; i<n; ++i) {
		int x;
		cin >> x;
		a[i]+=x;
		p[i+1]=p[i]+a[i];
	}
	for (int i=0; i<=n; ++i)
		todo[i].clear();
	for (int i=0; i<m; ++i) {
		cin >> seg[i][0] >> seg[i][1], --seg[i][0], --seg[i][1];
		todo[seg[i][0]].push_back(i);
		todo[seg[i][1]+1].push_back(i);
	}
	s.clear();
	queue<int> ().swap(q);
	for (int i=0; i<=n; ++i) {
		s.insert(i);
		if (p[i]==0)
			ck(i); //, cout << i << " ";
	}
	//cout << "REACHED" << endl;
	while(q.size()) {
		int i=q.front();
		q.pop();
		auto it=s.lower_bound(seg[i][0]);
		while(it!=s.end()&&*it<=seg[i][1]) {
			p[*it]=0;
			ck(*it);
			it=s.lower_bound(seg[i][0]);
		}
	}
	for (int i=1; i<=n; ++i)
		if (p[i]) {
			cout << "NO\n";
			return;
		}
	cout << "YES\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}