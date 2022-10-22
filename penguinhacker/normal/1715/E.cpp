#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=1e5;
int n, m, k;
ll d[mxN], d2[mxN];
vector<ar<int, 2>> adj[mxN];

ll ix(ar<ll, 2> a, ar<ll, 2> b) {
	assert(a[0]>b[0]);
	ll x=a[0]-b[0], y=b[1]-a[1];
	return y>=0?(y+x-1)/x:y/x;
}

void dijk() {
	priority_queue<ar<ll, 2>, vector<ar<ll, 2>>, greater<ar<ll, 2>>> pq;
	for (int i=0; i<n; ++i)
		pq.push({d[i], i});
	while(pq.size()) {
		int u=pq.top()[1];
		ll cd=pq.top()[0];
		pq.pop();
		if (d[u]!=cd)
			continue;
		for (auto [v, w] : adj[u])
			if (cd+w<d[v])
				pq.push({d[v]=d[u]+w, v});
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> k;
	for (int i=0; i<m; ++i) {
		int u, v, w;
		cin >> u >> v >> w, --u, --v;
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
	}
	memset(d, 0x3f, sizeof(d));
	d[0]=0;
	dijk();
	while(k--) {
		memcpy(d2, d, sizeof(d));
		for (int rep=0; rep<2; ++rep) {
			deque<ar<ll, 2>> dq;
			for (int i=0; i<n; ++i) {
				while(dq.size()>=2&&ix(dq[0], dq[1])<=i)
					dq.pop_front();
				if (dq.size())
					d2[i]=min(d2[i], (ll)i*i+dq[0][0]*i+dq[0][1]);
				ar<ll, 2> cur={-2*i, d[i]+(ll)i*i};
				while(dq.size()>=2&&ix(dq.back(), cur)<=ix(dq.end()[-2], dq.back()))
					dq.pop_back();
				dq.push_back(cur);
			}
			reverse(d, d+n);
			reverse(d2, d2+n);
		}
		memcpy(d, d2, sizeof(d));
		dijk();
	}
	for (int i=0; i<n; ++i)
		cout << d[i] << " ";
	return 0;
}