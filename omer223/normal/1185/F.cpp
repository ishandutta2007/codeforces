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

set<pll> cheapest[520];
ll n, m, r, p, actual, satisfy[520];

int toNum(vector<int> s) {
	int res = 0;
	for (int k : s) {
		res |= (1 << (k - 1));
	}
	return res;
}

void fill(int player) {
	bool f = 1;
	foru(i, 0, 512) {
		f = 1;
		foru(j, 0, 9) {
			if ((player >> j) & 1 && !((i >> j) & 1)) {
				f = 0;
				break;
			}
		}
		if (f) {
			satisfy[i]++;
		}
	}
}

inline ll calc(int p1, int p2) {
	return satisfy[p1] + satisfy[p2] - satisfy[p1 ^ p2];
}

int main() {
	fast;
	ifstream in("input.txt");
	ofstream out("output.txt");
	cin >> n >> m;
	foru(i, 0, n) {
		int s;
		cin >> s;
		vector<int> ttt(s);
		foru(j, 0, s)cin >> ttt[j];
		int bigpp = toNum(ttt);
		fill(bigpp);
	}
	foru(i, 0, m) {
		cin >> p >> r;
		vector<int> b(r);
		foru(j, 0, r) {
			cin >> b[j];
		}
		actual = toNum(b);
		cheapest[actual].insert(mp(p, i + 1));
	}
	ll maxPeople = -1, minPrice = 1e11, tmpPeople, tmpPrice;
	pii best;
	foru(i, 0, 512) {
		if (cheapest[i].empty()) continue;
		foru(j, i, 512) {
			if (cheapest[j].empty()||j==i&&cheapest[j].size()<2)continue;
			tmpPeople = satisfy[i | j];
			if(i!=j)tmpPrice = cheapest[i].begin()->first + cheapest[j].begin()->first;
			else {
				auto x = cheapest[i].begin(), y = x;
				x++;
				tmpPrice = x->first + y->first;
			}
			if (tmpPeople > maxPeople || tmpPeople == maxPeople && tmpPrice < minPrice) {
				maxPeople = tmpPeople;
				minPrice = tmpPrice;
				best = mp(i, j);
			}
		}
	}
	if (best.first != best.second) {
		cout << cheapest[best.first].begin()->second << " " << cheapest[best.second].begin()->second << endl;
	}
	else {
		auto x = cheapest[best.first].begin(), y = x;
		x++;
		cout << x->second << " " << y->second << endl;
	}
	return 0;
}