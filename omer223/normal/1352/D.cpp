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
ll n, a[1005], pref[1005];

ll q(int i, int j) {
	if (!i)return pref[j];
	return pref[j] - pref[i - 1];
}
int main() {
	fast;
	ifstream in("input.txt");
	ofstream out("output.txt");
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		foru(i, 1, n+1) {
			cin >> a[i];
			if (i==1)pref[i] = a[i];
			else pref[i] = pref[i - 1] + a[i];
		}
		bool alice = true;
		ll a = 0, b = 0, mv = 0,firstLeft=1,firstRight=n;
		int l = firstLeft, r = firstRight, mid, bst, prev = 0;
		while (firstLeft <= firstRight) {
			if (alice) {
				l = firstLeft, r = firstRight, bst = firstRight;
				while (l <= r) {
					mid = (l + r + 1) / 2;
					if (q(firstLeft, mid) > prev) {
						bst = min(bst, mid);
						r = mid - 1;
					}
					else {
						l = mid + 1;
					}
				}
				a += q(firstLeft, bst);
				prev = q(firstLeft, bst);
				firstLeft = bst + 1;
			}
			else {
				l = firstLeft, r = firstRight, bst = firstLeft;
				while (l <= r) {
					mid = (l + r + 1) / 2;
					if (q(mid, firstRight) > prev) {
						bst = max(bst, mid);
						l = mid + 1;
					}
					else {
						r = mid - 1;
					}
				}
				prev = q(bst, firstRight);
				b += q(bst, firstRight);
				firstRight = bst - 1;
			}
			mv++;
			alice = !alice;
		}
		cout << mv << " " << a << " " << b << endl;
	}
	return 0;
}