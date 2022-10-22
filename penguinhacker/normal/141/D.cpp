#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, L, m, t[100000], nxt[200002], last[100000], di[200002], id[100000];
vector<ar<int, 2>> p;
bool vis[200002];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> L;
	p.push_back({0, -1});
	p.push_back({L, 69696969});
	for (int i=0; i<n; ++i) {
		int a, b, c, d;
		cin >> a >> b >> c >> d, c+=d;
		int l=a-d, r=a+b;
		if (l<0||c>=r-l)
			continue;
		p.push_back({l, m});
		p.push_back({r, m});
		t[m]=c, id[m]=i+1, ++m;
	}
	sort(p.begin(), p.end());
	memset(nxt, -1, sizeof(nxt));
	for (int i=p.size()-1; ~i; --i) {
		int x=p[i][1];
		if (x==-1||x==69696969)
			continue;
		if (!last[x])
			last[x]=i;
		else
			nxt[i]=last[x];
	}
	memset(di, 0x3f, sizeof(di));
	priority_queue<ar<int, 2>, vector<ar<int, 2>>, greater<ar<int, 2>>> pq;
	pq.push({di[0]=0, 0});
	while(!pq.empty()) {
		int u=pq.top()[1];
		pq.pop();
		if (vis[u])
			continue;
		vis[u]=1;
		if (nxt[u]!=-1&&di[u]+t[p[u][1]]<di[nxt[u]]) {
			pq.push({di[nxt[u]]=di[u]+t[p[u][1]], nxt[u]});
			last[nxt[u]]=u;
		}
		if (u&&di[u]+p[u][0]-p[u-1][0]<di[u-1]) {
			pq.push({di[u-1]=di[u]+p[u][0]-p[u-1][0], u-1});
			last[u-1]=u;
		}
		if (u+1<p.size()&&di[u]+p[u+1][0]-p[u][0]<di[u+1]) {
			pq.push({di[u+1]=di[u]+p[u+1][0]-p[u][0], u+1});
			last[u+1]=u;
		}
	}
	cout << di[p.size()-1] << "\n";
	int cur=p.size()-1;
	vector<int> path;
	while(cur) {
		if (p[last[cur]][1]==p[cur][1]&&p[last[cur]][0]<p[cur][0])
			path.push_back(id[p[cur][1]]);
		cur=last[cur];
	}
	cout << path.size() << "\n";
	while(!path.empty()) {
		cout << path.back() << " ";
		path.pop_back();
	}
	return 0;
}