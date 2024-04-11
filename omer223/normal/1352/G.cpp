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

bool isValid(vi vec) {
	int n = vec.size();
	foru(i, 0, n - 1) {
		if (abs(vec[i] - vec[i + 1]) < 2 || abs(vec[i] - vec[i + 1]) > 4)return false;
	}
	return true;
}

int main() {
	fast;
	ifstream in("input.txt");
	ofstream out("output.txt");
	int t;
	cin >> t;
	while (t--) {
		int n, last5;
		cin >> n;
		if (n < 4) {
			cout << -1 << endl; continue;
		}
		vi perm;
		int div = n / 5;
		last5 = div * 5;
		foru(i, 0, div) {
			foru(j, 0, 5) {
				switch (j) {
				case 0:
					perm.pb(5 * i + 1);
					break;
				case 1:
					perm.pb(5 * i + 3);
					break;
				case 2:
					perm.pb(5 * i + 5);
					break;
				case 3:
					perm.pb(5 * i + 2);
					break;
				case 4:
					perm.pb(5 * i + 4);
					break;
				}
			}
		}
		switch (n % 5) {
		case 1:
			perm.pb(n);
			break;
		case 2:
			perm.pb(last5+1);
			perm.pb(last5+2);
			swap(perm[perm.size() - 2], perm[perm.size() - 3]);
			break;
		case 3:
			perm.pop_back();
			perm.pb(last5 + 1);
			perm.pb(n);
			perm.pb(last5 - 1);
			perm.pb(last5 + 2);
			break;
		case 4:
			perm.pb(last5 + 2);
			perm.pb(last5 + 4);
			perm.pb(last5 + 1);
			perm.pb(last5 + 3);
			break;
		}
		for (int k : perm) cout << k << " ";
		cout << endl;
	}
	return 0;
}
/*
YES 5
1 3 5 2 4
6
YES 6
1 3 5 2 4 6
7
YES 7
1 3 5 2 6 4 7
8
YES 8
1 3 5 2 6 8 4 7
9
YES 9
1 3 5 2 4 7 9 6 8
10
YES 10
1 3 5 2 4 6 8 10 7 9
11
YES 11
1 3 5 2 4 6 8 10 7 9 11*/