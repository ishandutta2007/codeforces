#define MOD 1000000000000000005
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
bool of = false;
ll pw(ll a, ll b) {
	if (!b)return 1;
	ll tmp = pw(a, b / 2);
	if (tmp > 1e9) of = 1;
	tmp *= tmp;
	if (b & 1)tmp *= a;
	return tmp;
}
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

vector<ll> divs, col;
ll mn = 1e18, dvsz;
ll primes[] = { 2,3,5,7,11,13,17,19,23 };

void foo(int pos) {
	if (pos == dvsz) {
		vector<ll> nums(dvsz, 1);
		foru(i, 0, dvsz)nums[col[i]] *= divs[i];
		ll num = 1, t2=1;
		sort(nums.rbegin(), nums.rend());
		foru(i, 0, dvsz) {
			t2 = pw(primes[i], nums[i] - 1);
			if (of || 1e18/t2<num) {
				of = 0;
				return;
			}
			num *= t2;
		}
		mn = min(mn, num);
		return;
	}
	foru(i, 0, dvsz) {
		col[pos] = i;
		foo(pos + 1);
	}
}

ll test(int n) {
	mn = 1e18;
	col.clear();
	divs.clear();
	if (n == 1) {
		mn = 1;
		return 0;
	}
	ll tmp = n;
	for (ll i = 2; i * i <= tmp; i++) {
		if (tmp%i == 0) {
			int cnt = 0;
			while (tmp%i == 0) {
				tmp /= i;
				divs.pb(i);
			}
		}
	}
	if (tmp != 1)divs.pb(tmp);
	dvsz = divs.size();
	col.resize(dvsz);
	foo(0);
}

int main() {
	fast;
	ifstream in("input.txt");
	ofstream out("output.txt");
	int n;
	cin >> n;
	test(n);
	cout << mn << endl;
	return 0;
}