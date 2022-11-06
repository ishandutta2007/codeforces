#include <iostream>
#include <utility>
using namespace std;
using ll=long long;
const int M = 131072;
const int maxn = int(1e5) + 10;

int n;

ll a[maxn];

struct Node {
	ll bal;
	ll pmax;
	ll pmin;
	Node& operator=(int x) {
		bal = x;
		pmin = x;
		pmax = x;
		return *this;
	}
};

Node operator+(Node a, Node b) {
	Node ret;
	ret.bal = a.bal + b.bal;
	ret.pmax = max(a.pmax, a.bal + b.pmax);
	ret.pmin = min(a.pmin, a.bal + b.pmin);
	return ret;
}

struct {
	Node t[M<<1];

	void init(int p=1, int l=1, int r=n) {
		if (l == r) { t[p]=a[l]; return; }
		int md = (l+r)/2;
		init(p*2, l, md);
		init(p*2+1, md+1, r);
		t[p] = t[p*2]+t[p*2+1];
	}

	Node rng(int ql, int qr, int p=1, int l=1, int r=n) {
		if (ql <= l && r <= qr) return t[p];
		int md = (l+r)/2;
		if (qr <= md) return rng(ql, qr, p*2, l, md);
		else if (md < ql) return rng(ql, qr, p*2+1, md+1, r);
		return rng(ql, qr, p*2, l, md)+rng(ql, qr, p*2+1, md+1, r);
	}
} T;

int main()
{
	cin.tie(0)->sync_with_stdio(0);

	int q; cin >> n >> q;
	for (int i=1; i<=n; ++i) cin >> a[i];

	static int b[maxn];
	for (int i=1; i<=n; ++i) cin >> b[i];
	for (int i=1; i<=n; ++i) { a[i] = a[i]-b[i]; }

	T.init();
for(;q--;) {
	int l, r; cin >> l >> r;
	Node nd = T.rng(l, r);

	if (nd.bal) { cout << "-1\n"; continue; }
	if (nd.pmax > 0) { cout << "-1\n"; continue; }

	cout << (-nd.pmin) << '\n';
}

    return 0;
}