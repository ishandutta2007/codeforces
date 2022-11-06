#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pp;
typedef pair<ll,ll> pll;
void cppio(){ ios_base::sync_with_stdio(0); cin.tie(0); }
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define eb emplace_back
#define x first
#define y second
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define sz(x) (int)(x).size()

const int maxn = 524288 + 10;
bitset<maxn> ex;

int n, k;
int rev[maxn];

int root;
int nn;
struct Node {
	int c[2];
	int bl, br;
	int md;
	void pull();
} node[2000'0000];

int X;

const int inf = int(1e9);

void Node::pull() {
	bl = (node[c[0]].bl == inf) ? (node[c[1]].bl) : (node[c[0]].bl);
	br = (node[c[1]].br == inf) ? (node[c[0]].br) : (node[c[1]].br);
	md = min(node[c[0]].md, node[c[1]].md);
	if (node[c[1]].bl != inf && node[c[0]].br != inf) {
		md = min(md, (X^node[c[1]].bl) - (X^node[c[0]].br));
	}
}

int Build(int l=0, int r=(1<<k)-1) {
	int me = ++nn;
	auto &v = node[me];

	if (l == r) {
		v.md = inf;
		if (ex.test(l)) {
			v.bl = v.br = l;
		} else {
			v.bl = inf;
			v.br = inf;
		}
		return me;
	}

	int mid = (l+r)/2;
	node[me].c[0] = Build(l, mid);
	node[me].c[1] = Build(mid+1, r);
	node[me].pull();
	return me;
}

void Change(int lev, int cl, int v) {
	if (lev == cl) {
		swap(node[v].c[0], node[v].c[1]);
		node[v].pull();
		return;
	}
	Change(lev, cl+1, node[v].c[0]);
	Change(lev, cl+1, node[v].c[1]);
	node[v].pull();
}

int main()
{
	cppio();
	cin >> n >> k;

	for (int i=1, j=0; i<(1<<k); ++i) {
		int t = 1<<(k-1);
		while (t && (j&t)) j^=t, t>>=1;
		j ^= t;
		rev[i] = j;
	}

	rrep(i, n) { int x; cin >> x; ex.set(x); }
	root = Build();

	static int ans[maxn];

	for (int m=0; m<(1<<k); ++m) {
		X = rev[m];
		ans[rev[m]] = node[root].md;
		if (m+1 == (1<<k)) break;
		int df = (rev[m]^rev[m+1]);
		for (int i=0; i<k; ++i) if (1&(df>>i)) {
			X ^= (1<<i);
			Change(k-1-i, 0, root);
		}
	}

	rep(m, (1<<k)) cout << ans[m] << ' ';
	cout << '\n';

	return 0;
}