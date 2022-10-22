#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define arr array

const int mxN = 1<<17;

int n, q, t[2*mxN];

void build() {
	int x = n;
	int depth = 1;
	for (int i=n-1; i>=1; --i) {
		if (depth&1)
			t[i] = t[i<<1]|t[(i<<1)+1];
		else
			t[i] = t[i<<1]^t[(i<<1)+1];
		if (i == x/2) {
			x /= 2;
			depth++;
		}
	}
}

void update(int pos, int value) {
	int depth = 1;
	for (t[pos] = value; pos>1; pos>>=1, depth++) {
		if (depth&1)
			t[pos>>1] = t[pos]|t[pos^1];
		else
			t[pos>>1] = t[pos]^t[pos^1];
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> q;
	n = 1<<n;
	for (int i=0; i<n; ++i)
		cin >> t[i+n];
	build();

	while(q--) {
		int p, v;
		cin >> p >> v;
		update(p-1+n, v);
		cout << t[1] << '\n';
	}

	return 0;
}