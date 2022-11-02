#define MOD 11
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
#include <numeric>
using namespace std;
const int INF = 1 << 29;
typedef long long ll;
typedef unsigned long long ull;
inline int two(int n) { return 1 << n; }
ll extgcd(ll a, ll b, ll& x, ll& y) { if (b == 0) { x = 1; y = 0; return a; } else { int g = extgcd(b, a%b, y, x); y -= a / b * x; return g; } }
ll modpow(ll a, ll b) { ll res = 1; a %= MOD; for (; b; b >>= 1) { if (b & 1)res = res * a%MOD; a = a * a%MOD; }return res; }

const int sz = 3e2 + 5;
bool ans[sz][sz];

void solve() {
	ll n, k, n2, dv;
	cin >> n >> k;
	n2 = n * n;
	if (!k) {
		cout << 0 << endl;
		foru(i, 0, n) {
			foru(j, 0, n)cout << 0;
			cout << endl;
		}
		return;
	}
	else if (k % n == 0) {
		dv = k / n;
		cout << 0 << endl;
		foru(i, 0, n) {
			foru(j, 0, n) {
				if (i + dv < n) {
					if (j >= i && j < i + dv)cout << 1;
					else cout << 0;
				}
				else {
					if (j >= i || j < ((i + dv) % n))cout << 1;
					else cout << 0;
				}
			}
			cout << endl;
		}
	}
	else {
		cout << 2 << endl;
		dv = k / n;
		ll tdv, bigv = dv + 1, smallv = dv, biga = k % n, smalla = n - biga;
		foru(i, 0, n) {
			if (i < biga)tdv = bigv;
			else tdv = smallv;
			foru(j, 0, n) {
				if (i + tdv < n) {
					if (j >= i && j < i + tdv)cout << 1;
					else cout << 0;
				}
				else {
					if (j >= i || j < ((i + tdv) % n))cout << 1;
					else cout << 0;
				}
			}
			cout << endl;
		}
	}
}

int main() {
	fast;
	ifstream in("input.txt");
	ofstream out("output.txt");
	int t;
	cin >> t;
	while (t--)solve();
	return 0;
}