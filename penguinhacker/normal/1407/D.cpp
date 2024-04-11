#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=3e5;
int n, a[mxN], d[mxN];
vector<int> adj[mxN];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> a[i];
	for (int k=0; k<2; ++k) {
		stack<int> st;
		for (int i=0; i<n; ++i) {
			while(st.size()&&a[i]>a[st.top()]) {
				adj[st.top()].push_back(i);
				st.pop();
			}
			if (st.size()) {
				adj[st.top()].push_back(i);
				if (a[i]==a[st.top()])
					st.pop();
			}
			st.push(i);
		}
		for (int i=0; i<n; ++i)
			a[i]*=-1;
	}
	memset(d, -1, 4*n);
	d[0]=0;
	for (queue<int> q({0}); q.size(); q.pop()) {
		int u=q.front();
		for (int v : adj[u]) {
			if (d[v]==-1) {
				d[v]=d[u]+1;
				q.push(v);
			}
		}
	}
	cout << d[n-1];
	return 0;
}