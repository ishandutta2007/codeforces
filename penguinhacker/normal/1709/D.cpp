#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

template<class T> struct RMQ { //min range query (default)
	vector<vector<T>> st;
	vector<int> log;
	T combine(T a, T b) {return max(a, b);}
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

const int mxM=2e5;
int n, m, q, a[mxM];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i=0; i<m; ++i)
		cin >> a[i];
	RMQ<int> rmq;
	rmq.init(vector<int>(a, a+m));
	cin >> q;
	while(q--) {
		int x1, y1, x2, y2, k;
		cin >> x1 >> y1 >> x2 >> y2 >> k, --y1, --y2;
		if (y1%k!=y2%k||x1%k!=x2%k) {
			cout << "NO\n";
			continue;
		}
		x1+=(n-x1)/k*k;
		//cout << x1 << "\n";
		cout << (rmq.qry(min(y1, y2), max(y1, y2))<x1?"YES":"NO") << "\n";
	}
	return 0;
}