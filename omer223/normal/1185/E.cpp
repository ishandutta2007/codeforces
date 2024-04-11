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

struct pt {
	ll x, y;
	pt(ll x__, ll y__): x(x__), y(y__) {}
	pt(): x(0), y(0) {}
};

char a[2005][2005], b[2005][2005];
int horizontal[30];
void ms(int n, int m) { foru(i, 0, n) { foru(j, 0, m)b[i][j] = '.'; } }
void msh(int amt) { foru(i, 0, amt)horizontal[i] = 0; }

void solve() {
	int n, m, amt = 0, tmp;
	cin >> n >> m;
	set<pii> s[26];
	ms(n, m);
	//ms(n, m);
	foru(i, 0, n) {
		foru(j, 0, m) {
			cin >> a[i][j];
			if (a[i][j] != '.') {
				tmp = a[i][j] - 'a' + 1;
				amt = max(amt, tmp);
				s[tmp-1].insert(mp(i, j));
			}
		}
	}
	msh(amt);
	bool first = 1;
	pii tmpPair;
	foru(i, 0, amt) {
		first = 1;
		for (auto x : s[i]) {
			if (first) {
				first = 0;
				tmpPair = x;
			}
			else {
				if (x.first == tmpPair.first) {
					if (horizontal[i] == 2) {
						cout << "NO" << endl;
						return;
					}
					horizontal[i] = 1;
				}
				else if (x.second == tmpPair.second) {
					if (horizontal[i] == 1) {
						cout << "NO" << endl;
						return;
					}
					horizontal[i] = 2;
				}
			}
		}
		if (!horizontal[i]) horizontal[i] = 1;
	}
	foru(i, 0, amt) {
		if (s[i].empty()) {
			s[i].insert(mp(s[amt - 1].begin()->first, s[amt - 1].begin()->second));
			continue;
		}
		pii start = *s[i].begin(), end = *s[i].rbegin();
		if (horizontal[i] == 1) {
			foru(q, start.second, end.second + 1) {
				b[start.first][q] = i + 'a';
			}
		}
		else {
			foru(q, start.first, end.first + 1) {
				b[q][start.second] = i + 'a';
			}
		}
	}
	foru(i, 0, n) {
		foru(j, 0, m) {
			if (a[i][j] != b[i][j]) {
				cout << "NO" << endl;
				return;
			}
		}
	}
	cout << "YES" << endl;
	cout << amt << endl;
	foru(i, 0, amt) {
		pii x = *s[i].begin(), y = *s[i].rbegin();
		cout << x.first +1 << " " << x.second +1<< " " << y.first +1<< " " << y.second +1<< endl;
	}
	return;
}

int main() {
	fast;
	ifstream in("input.txt");
	ofstream out("output.txt");
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
/*
10
-1 6
0 9
-3 8
0 3
-3 7
3 7
1 7
-1 7
1 4
3 8
(11 wanted, got 17)
*/