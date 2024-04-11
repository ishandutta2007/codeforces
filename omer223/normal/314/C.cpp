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

struct fen {
	vector<ll> fenwick;
	int size;
	fen(int sz) {
		size = sz;
		fenwick.resize(size);
		foru(i, 0, size)fenwick[i] = 0;
	}
	fen(vector<ll> arr) {
		size = arr.size();
		fenwick.resize(size);
		foru(i, 0, size)fenwick[i] = 0;
		foru(i, 0, size)update(i, arr[i]);
	}
	void update(int index, ll add) {
		for (int k = index; k < size; k |= (~k & -~k)) {
			fenwick[k] = fenwick[k] + add;
		}
	}
	ll query(int to) {
		if (to < 0)return 0;
		ll sum = 0;
		for (int curr = to + 1; curr > 0; curr ^= (curr & -curr)) {
			sum = sum + fenwick[curr - 1];
		}
		return sum;
	}
	ll rangeQuery(int from, int to) {
		if (!from)return query(to);
		return query(to) - query(from - 1);
	}
	ll get(int index) {
		if (index < 0)return 0;
		else if (!index) return query(0);
		else return query(index) - query(index - 1);
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
	int n,a;
	cin >> n;
	vector<pii> v;
	vector<ll> os(n), arr(n);
	foru(i, 0, n) {
		cin >> a;
		arr[i] = a;
		v.pb(mp(a, i));
	}
	sort(v.begin(), v.end());
	foru(i, 0, n)os[v[i].second] = i;
	um<ll, ll> cnt;
	fen fenwick(n);
	ll sum = 0, curr;
	foru(i, 0, n) {
		int orderindex = os[i];
		curr = 0;
		if (cnt.find(arr[i]) == cnt.end()) {
			curr = arr[i] * ((1 + fenwick.query(orderindex - 1)%MOD));
			cnt[arr[i]] = curr % MOD;
		}
		else {
			ll totsum = cnt[arr[i]], mysum = arr[i] * ((1 + fenwick.query(orderindex - 1) % MOD));
			curr = (mysum - totsum + MOD) % MOD;
			cnt[arr[i]] = mysum % MOD;
		}
		curr %= MOD;
		fenwick.update(orderindex, curr);
		sum += curr;
		sum %= MOD;
	}
	cout << sum << endl;
	return 0;
}