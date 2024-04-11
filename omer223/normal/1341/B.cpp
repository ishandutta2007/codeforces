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
ll n;
ll arr[200000];
ll prefix[200000];
void ms() { foru(i, 0, n)prefix[i] = 0; }
ll sum(int from, int to) {
	if (from == 0)return prefix[to];
	return prefix[to] - prefix[from - 1];
}

int main() {
	fast;
	ifstream in("input.txt");
	ofstream out("output.txt");
	ll t, bst;
	ll k;
	cin >> t;
	while (t--) {
		cin >> n >> k;
		ms();
		foru(i, 0, n) {
			cin >> arr[i];
		}
		foru(i, 1, n - 1) {
			if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) prefix[i] = prefix[i - 1] + 1;
			else prefix[i] = prefix[i - 1];
		}
		bst = -1;
		ll bstIndex = -1, tmp;
		foru(i, 0, n - k + 1) {
			tmp = sum(i + 1, i + k - 2);
			if (tmp > bst) {
				bst = tmp;
				bstIndex = i + 1;
			}
		}
		cout << bst + 1 << " " << bstIndex << endl;
	}
	return 0;
}