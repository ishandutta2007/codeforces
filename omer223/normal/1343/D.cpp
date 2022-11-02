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

void solve() {
	ll a, b, c, d, n, x, y, z;


}
ll fenwick[400001];

void updateFenwick(int size, int index, ll add) {
	for (int k = index; k < size; k |= (~k & -~k)) {
		fenwick[k] += add;
	}
}

ll returnSubArray(int size, int untilNotIncludes) {
	int sum = 0;
	for (int curr = untilNotIncludes; curr > 0; curr ^= (curr & -curr)) {
		sum += fenwick[curr - 1];
	}
	return sum;
}

void rangeQuery(int size, int from, int toExcluded, ll add) {
	if (from >= toExcluded) return;
	updateFenwick(size, from, add);
	if (toExcluded < size) updateFenwick(size, toExcluded, -add);
}

ll sol[200000];
ll howMuchEqual[400001];

void ms(int sz) {
	foru(i, 0, sz + 1) {
		howMuchEqual[i] = 0; fenwick[i] = 0;
	}
}

void printFenwick(int size) {
	foru(i, 0, size) cout << fenwick[i] << " ";
	cout << endl;
}

void printArr(int size) {
	foru(i, 0, size) cout << returnSubArray(size, i + 1) << " ";
	cout << endl;
}

int main() {
	fast;
	ifstream in("input.txt");
	ofstream out("output.txt");
	int t;
	ll n, k, mn, mx, from, to, sm;
	cin >> t;
	while (t--) {
		cin >> n >> k;
		ms(2 * k);
		foru(i, 0, n) cin >> sol[i];
		foru(i, 0, n / 2) {
			sm = sol[i] + sol[n - i - 1];
			howMuchEqual[sm - 1]++;
			mn = min(sol[i], sol[n - i - 1]);
			mx = max(sol[i], sol[n - i - 1]);
			from = mn + 1;
			to = mx + k;
			rangeQuery(2 * k, from - 1, to, 1);
			rangeQuery(2 * k, sm - 1, sm, -1);
		}
		ll currBest = 1000000, tmp, ths;
		foru(j, 1, 2 * k) {
			ths = returnSubArray(2 * k,j + 1);
			tmp = 1 * ths + 2 * (n / 2 - ths - howMuchEqual[j]);
			currBest = min(currBest, tmp);
		}
		cout << currBest << endl;
	}
	return 0;
}