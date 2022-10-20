#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;

int n,b[N];
vector<int>p[N];
void work() {
	cin>>n;
	for (int i=1;i<=n;i++) {
		cin>>b[i];
		p[b[i]].emplace_back(i);
	}
	for (int i=0;i<=n+1;i++) {
		sort(p[i].begin(),p[i].end(),[&](int x,int y) {
			return p[x].size()<p[y].size();
		});
	}
	int s=0;
	if (p[n+1].size()) {
		s=n+1;
	}
	vector<int>a;
	a.reserve(n+1);
	queue<pair<int,int>>q;
	q.push({s,1});
	int t=!s,k=t?n+1:0;
	while (!q.empty()) {
		auto [now,tmp]=q.front(); q.pop();
		a.emplace_back(now);
		for (int i:p[now]) {
			q.push({i,!tmp});
			if (!tmp) {
				continue;
			}
			if (t) {
				k=min(k,i-1);
			} else {
				k=max(k,i);
			}
		}
	}
	cout<<k<<"\n";
	for (int i=1;i<=n;i++) {
		cout<<a[i]<<" \n"[i==n];
	}
	for (int i=0;i<=n+1;i++) {
		p[i].clear();
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int T;
	cin>>T;
	while (T--) {
		work();
	}
	
	return 0;
}