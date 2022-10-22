#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

template<class T> struct RMQ { //min range query (default)
	vector<vector<T>> st;
	vector<int> log;
	T combine(T a, T b) {return min(a, b);}
	void init(vector<T> a) {
		int n = a.size();
		log = vector<int>(n + 1);
		for (int i = 2; i <= n; ++i) log[i] = log[i >> 1] + 1;
		int k = log[n];
		st = vector<vector<T>>(n, vector<T>(k + 1));
		for (int i = 0; i < n; ++i) st[i][0] = a[i];
		for (int j = 1; j <= k; ++j) for (int i = 0; i + (1 << j) - 1 < n; ++i)
			st[i][j] = combine(st[i][j - 1], st[i + (1 << (j - 1))][j-1]);
	}
	T qry(int l, int r) {
		int k = log[r - l + 1];
		return combine(st[l][k], st[r - (1 << k) + 1][k]);
	}
};

const int mxN=200000;
int n, m, q, p[mxN], a[mxN], nxt[mxN], oc[mxN], dp[mxN][18];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> q;
	for (int i=0; i<n; ++i)
		cin >> p[i], --p[i];
	for (int i=0; i<m; ++i)
		cin >> a[i], --a[i];
	for (int i=0; i<n; ++i)
		nxt[p[i]]=p[(i+1)%n];
	memset(oc, -1, sizeof(oc));
	for (int i=m-1; ~i; --i) {
		dp[i][0]=oc[nxt[a[i]]];
		for (int j=1; j<18; ++j)
			dp[i][j]=dp[i][j-1]^-1?dp[dp[i][j-1]][j-1]:-1;
		oc[a[i]]=i;
	}
	vector<int> v(m);
	for (int i=0; i<m; ++i) {
		int c=i;
		for (int j=17; ~j; --j)
			if (n-1>>j&1)
				c=c^-1?dp[c][j]:-1;
		v[i]=c^-1?c:69696969;
	}
	RMQ<int> rmq;
	rmq.init(v);
	while(q--) {
		int l, r;
		cin >> l >> r, --l, --r;
		cout << (rmq.qry(l, r)<=r);
	}
	return 0;
}