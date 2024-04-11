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
#include <stack>
#include <deque>
#include <queue>
#include <bitset>
using namespace std;
const int INF = 1 << 29;
typedef long long ll;
typedef unsigned long long ull;
inline int two(int n) { return 1 << n; }
ll extgcd(ll a, ll b, ll& x, ll& y) { if (b == 0) { x = 1; y = 0; return a; } else { int g = extgcd(b, a%b, y, x); y -= a / b * x; return g; } }
ll modpow(ll a, ll b) { ll res = 1; a %= MOD; for (; b; b >>= 1) { if (b & 1)res = res * a%MOD; a = a * a%MOD; }return res; }
template<class T>
struct fen {
	vector<T> fenwick;
	int size;
	fen(int sz) {
		size = sz;
		fenwick.resize(size);
		foru(i, 0, size)fenwick[i] = 0;
	}
	fen(vector<T> arr) {
		size = arr.size();
		fenwick.resize(size);
		foru(i, 0, size)fenwick[i] = 0;
		foru(i, 0, size)update(i, arr[i]);
	}
	void update(int index, T add) {
		for (int k = index; k < size; k |= (~k & -~k)) {
			fenwick[k] = fenwick[k] + add;
		}
	}
	T query(int to) {
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
int main() {
	fast;
	ifstream in("input.txt");
	ofstream out("output.txt");
	ll n, k;
	cin >> n >> k;
	k = min(k, n - k);
	fen<ll> fenwick(n);
	int curr = 0, prev = -1;
	ll tot = 1;
	while (curr || prev == -1) {
		prev = curr;
		curr = (curr + k) % n;
		if (curr > prev) {
			tot += fenwick.rangeQuery(prev + 1, curr - 1);
		}
		else {
			tot += fenwick.rangeQuery(prev + 1, n - 1) + fenwick.rangeQuery(0, curr - 1);
		}
		tot++;
		cout << tot << " ";
		fenwick.update(curr, 1);
		fenwick.update(prev, 1);
	}
	return 0;
}