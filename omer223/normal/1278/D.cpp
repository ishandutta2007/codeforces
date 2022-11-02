#define MOD 1000000007
#define fast ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back
#define mp make_pair
#define has(set, x) set.find(x) != set.end()
#define nohas(set, x) set.find(x) == set.end()
#define inc(mpp, x) {if(has(mpp, x)) mpp[x]++; else mpp.insert(mp(x,1));}
#define decc(mpp, x) {if(has(mpp, x)) {if(mpp[x] > 1) mpp[x]--; else mpp.erase(x);}}
#define F first
#define S second
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vvi vector<vi>
#define um unordered_map
#define us unordered_set
#include <iostream>
#include <list>
#include <queue>
#include <vector>
#include <map>
#include <string>
#include <unordered_map>
#include <iomanip>
#include <set>
#include <unordered_set>
#include <fstream>
#include <algorithm>
#include <chrono>
#include <bitset>
using namespace std;
const int INF = 1 << 29;
typedef long long ll;
typedef unsigned long long ull;
inline int two(int n) { return 1 << n; }
ll extgcd(ll a, ll b, ll& x, ll& y) { if (b == 0) { x = 1; y = 0; return a; } else { int g = extgcd(b, a%b, y, x); y -= a / b * x; return g; } }
ll modpow(ll a, ll b) { ll res = 1; a %= MOD; for (; b; b >>= 1) { if (b & 1)res = res * a%MOD; a = a * a%MOD; }return res; }
struct custom_hash {
	static uint64_t splitmix64(uint64_t x) {
		x += 0x9e3779b97f4a7c15;
		x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
		x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
		return x ^ (x >> 31);
	}

	size_t operator()(uint64_t x) const {
		static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
		return splitmix64(x + FIXED_RANDOM);
	}
};
template<class T>
struct fen {
	vector<T> fenwick;
	int size;
	fen(int sz) {
		size = sz;
		fenwick.resize(size);
		foru(i, 0, size)fenwick[i]=0;
	}
	fen(vector<T> arr) {
		size = arr.size();
		fenwick.resize(size);
		foru(i, 0, size)fenwick[i](0);
		foru(i, 0, size)update(i, arr[i]);
	}
	void update(int index, T add) {
		for (int k = index; k < size; k |= (~k & -~k)) {
			fenwick[k] = fenwick[k] + add;
		}
	}
	T query(int to) {
		if (to < 0)return T(0);
		T sum = 0;
		for (int curr = to + 1; curr > 0; curr ^= (curr & -curr)) {
			sum = sum + fenwick[curr - 1];
		}
		return sum;
	}
	T rangeQuery(int from, int to) {
		if (!from)return query(to);
		return query(to) - query(from - 1);
	}
	void print() {
		foru(i, 0, size) cout << query(i) << " ";
		cout << endl;
	}
};
const int sz = 5e5 + 3;
int a[2 * sz],order[sz],n;
list<int> adj[sz];
bitset<sz> vis;
void dfs(int src) {
	vis[src] = 1;
	for (auto x : adj[src]) {
		if (!vis[x])dfs(x);
	}
}
ll cntEdges() {
	ll cnt = 0;
	foru(i, 1, n + 1)order[i] = -1;
	int currorder = n - 1;
	fen<ll> cntarr(n);
	foru(i, 0, 2 * n) {
		if (a[i] > 0) {
			order[a[i]] = currorder;
			cntarr.update(currorder, 1);
			currorder--;
		}
		else {
			int o = order[-a[i]];
			cnt += cntarr.query(o - 1);
			cntarr.update(o, -1);
		}
	}
	return cnt;
}
void initTree() {
	map<int, int> ordervis;
	int currorder = n - 1;
	foru(i, 0, 2 * n) {
		if (a[i] > 0) {
			ordervis.insert(mp(currorder,a[i]));
			currorder--;
		}
		else {
			int o = order[-a[i]];
			ordervis.erase(o);
			auto x = ordervis.begin();
			while (x != ordervis.end() && (x->first < o)) {
				int other = x->second;
				adj[other].pb(-a[i]);
				adj[-a[i]].pb(other);
				x++;
			}
		}
	}
}

int main() {
	fast;
	ifstream in("input.txt");
	ofstream out("output.txt");
	int x,y;
	cin >> n;
	foru(i, 0, n) {
		cin >> x >> y;
		a[x - 1] = (i+1);
		a[y - 1] = -(i+1);
	}
	ll cnt = cntEdges();
	if (cnt != n - 1) {
		cout << "NO" << endl;
		return 0;
	}
	initTree();
	dfs(1);
	bool f = 1;
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			f = 0;
			break;
		}
	}
	if (f)cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}