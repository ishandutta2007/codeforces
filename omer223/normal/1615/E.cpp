
#define fast ios::sync_with_stdio(false); cin.tie(0);
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define ff first
#define ss second

#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<ll> vi;


typedef pll T;
struct seglazy {
	vector<pii> lohi;
	vector<T> values, delta, initArr;
	int n;
	ll INF_VALUE = -1e9;
private:
	void pushDown(int i) {
		delta[2 * i].ff += delta[i].ff; //CHECK
		delta[2 * i + 1].ff += delta[i].ff;
		delta[i].ff = 0;
	}
	void update(int i) {
		ll v0 = values[2 * i].ff + delta[2 * i].ff, v1 = values[2 * i + 1].ff + delta[2 * i + 1].ff;
		if (v0 > v1) {
			values[i] = { v0,values[2 * i].ss };
		}
		else {
			values[i] = { v1,values[2 * i + 1].ss };
		}
	}
	void init(int i, int a, int b) {
		lohi[i].first = a;
		lohi[i].second = b;
		if (a == b) values[i] = initArr[a];
		if (a >= b)return;
		int m = (a + b) / 2;
		init(2 * i, a, m);
		init(2 * i + 1, m + 1, b);
		if (values[2 * i].ff > values[2 * i + 1].ff)values[i] = values[2 * i];
		else values[i] = values[2 * i + 1];
	}
	T rangeQueryUtil(int i, int a, int b) {
		if (a > b || lohi[i].first > b || lohi[i].second < a)return { INF_VALUE, -1 }; //CHECK
		else if (lohi[i].first >= a && lohi[i].second <= b) return { values[i].ff + delta[i].ff, values[i].ss };
		else {
			pushDown(i);
			T left = rangeQueryUtil(2 * i, a, b);
			T right = rangeQueryUtil(2 * i + 1, a, b);
			update(i);
			if (left.ff > right.ff)return left;
			else return right;
		}
	}
	void rangeUpdateUtil(int i, int a, int b, T val) {
		if (a > b || lohi[i].first > b || lohi[i].second < a)return;
		else if (lohi[i].first >= a && lohi[i].second <= b)delta[i].ff += val.ff, delta[i].ss += val.ss;
		else {
			pushDown(i);
			rangeUpdateUtil(2 * i, a, b, val);
			rangeUpdateUtil(2 * i + 1, a, b, val);
			update(i);
		}
	}
public:
	seglazy(vector<T> arr) {
		this->n = arr.size();
		this->initArr = arr;
		lohi.resize(4 * n + 1);
		delta.resize(4 * n + 1);
		values.resize(4 * n + 1);
		fill(delta.begin(), delta.end(), pll{ 0LL,0LL });
		init(1, 0, n - 1);
	}
	void rangeUpdate(int from, int to, T val) {
		rangeUpdateUtil(1, from, to, val);
	}
	T rangeQuery(int from, int to) {
		return rangeQueryUtil(1, from, to);
	}
};

const int sz = 5e5;
vector<int> adj[sz];
ll n, k;
ll L = 0;
int dep[sz];
int tin[sz], tout[sz], p[sz], t = 0;
vector<pll> trav;
bitset<sz> bad;

void dfs(int src, int prv) {
	p[src] = prv;
	tin[src] = t++;
	trav.push_back({ dep[src],src });
	bool leaf = 1;
	for (int x : adj[src]) {
		if (x == prv)continue;
		leaf = 0;
		dep[x] = dep[src]+1;
		dfs(x, src);
	}
	if (leaf)L++;
	trav.push_back({ dep[src],src });
	tout[src] = t++;
}

ll cur = 0;
seglazy* sg;

void up(int src) {
	while (src != -1 && !bad[src]) {
		bad[src] = 1;
		cur++;
		sg->rangeUpdate(tin[src], tout[src], { -1,0 });
		src = p[src];
	}
}

int main() {
    fast;
	cin >> n >> k;
	foru(i, 0, n - 1) {
		int x, y;
		cin >> x >> y;
		adj[--x].push_back(--y);
		adj[y].push_back(x);
	}
	dep[0] = 1;
	dfs(0, -1);
	if (L <= k) {
		ll bst = -1e18;
		for (ll x = L; x <= k; x++) {
			bst = max(bst, (n - x) * x);
		}
		cout << bst << '\n';
	}
	else {
		sg = new seglazy(trav);
		ll col = 0;
		foru(_, 0, k) {
			pll ii = sg->rangeQuery(0, 2 * n - 1);
			if (ii.ff <= 0)break;
			col++;
			up(ii.ss);
		}
		ll rem = n - cur;
		ll bst = 1e18;
		for (ll x = 0; x <= rem; x++) {
			bst = min(bst, (n - x - col) * (col - x));
		}
		cout << bst << '\n';
	}
    return 0;
}