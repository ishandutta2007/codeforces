#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=300001;
int n, m, sz=1, b, a[mxN], p[mxN], c[mxN][26], d[mxN][26], sl[mxN], ol[mxN];
multiset<int> vals[mxN];

int add(string s) {
	int u=0;
	for (char a : s) {
		if (!c[u][a-'a'])
			c[u][a-'a']=sz++;
		u=c[u][a-'a'];
	}
	ol[u]=u;
	vals[u].insert(0);
	return u;
}

void ac() {
	for (queue<int> q({0}); !q.empty(); q.pop()) {
		int u=q.front();
		if (!ol[u])
			ol[u]=ol[sl[u]];
		for (int i=0; i<26; ++i) {
			int v=c[u][i];
			if (v) {
				sl[v]=d[sl[u]][i];
				q.push(v);
			}
			d[u][i]=v?v:d[sl[u]][i];
		}
	}
}

int feed(int u, char a) {
	u=d[u][a-'a'];
	for (int v=ol[u]; v; v=ol[sl[v]])
		b=max(b, *vals[v].rbegin());
	return u;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i=0; i<n; ++i) {
		string s;
		cin >> s;
		p[i]=add(s);
	}
	ac();
	while(m--) {
		int t;
		cin >> t;
		if (t==1) {
			int i, x;
			cin >> i >> x, --i;
			vals[p[i]].erase(vals[p[i]].find(a[i]));
			a[i]=x;
			vals[p[i]].insert(a[i]);
		} else {
			string s;
			cin >> s;
			b=-1;
			int u=0;
			for (char a : s)
				u=feed(u, a);
			cout << b << "\n";
		}
	}
	return 0;
}