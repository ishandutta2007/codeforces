#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=1e6;
int n, k, n2=1, c[30*mxN][2], cnt[30*mxN];
ll ans;

void ins(int x) {
	int u=0;
	for (int i=29; ~i; --i) {
		int b=x>>i&1;
		if (!c[u][b])
			c[u][b]=n2++;
		u=c[u][b];
		++cnt[u];
	}
}

void qry(int x) {
	int u=0;
	for (int i=29; ~i; --i) {
		int b=x>>i&1;
		if (k>>i&1) {
			if (c[u][b^1])
				u=c[u][b^1];
			else
				return;
		} else {
			if (c[u][b^1])
				ans+=cnt[c[u][b^1]];
			if (c[u][b])
				u=c[u][b];
			else
				return;
		}
	}
	ans+=cnt[u];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	ins(0);
	int x=0;
	for (int i=0; i<n; ++i) {
		int a;
		cin >> a, x^=a;
		qry(x);
		ins(x);
	}
	cout << ans;
	return 0;
}