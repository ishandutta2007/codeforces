#define MOD 1000000007
#define fast ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define FOR(i, n) for (int i = 0; i < n; i++)
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
using namespace std;
const int INF = 1 << 29;
typedef long long ll;
typedef unsigned long long ull;
inline int two(int n) { return 1 << n; }
ll extgcd(ll a, ll b, ll& x, ll& y) { if (b == 0) { x = 1; y = 0; return a; } else { int g = extgcd(b, a%b, y, x); y -= a / b * x; return g; } }
ll modpow(ll a, ll b) { ll res = 1; a %= MOD; for (; b; b >>= 1) { if (b & 1)res = res * a%MOD; a = a * a%MOD; }return res; }

int arr[9][9];

int main() {
	fast;
	ifstream in("input.txt");
	ofstream out("output.txt");
	ll t;
	us<int> nonVisited;
	cin >> t;
	while (t--) {
		nonVisited.clear();
		string s;
		FOR(i, 9) nonVisited.insert(i + 1);
		FOR(i, 9) {
			cin >> s;
			FOR(j, 9) {
				arr[i][j] = s[j] - '0';
				if (i < 3) {
					if (j == 3 * i) nonVisited.erase(arr[i][j]);
				}
				else if (i < 6) {
					if (j == 3 * (i - 3) + 1) nonVisited.erase(arr[i][j]);
				}
				else {
					if (j == 3 * (i - 6) + 2) nonVisited.erase(arr[i][j]);
				}
			}
		}
		auto x = nonVisited.begin();
		if (x != nonVisited.end()) {
			for (int i = 0; i < 3; i++) {
				arr[i][3 * i] = *x;
			}
			for (int i = 0; i < 3; i++) {
				arr[3 + i][3 * i + 1] = *x;
			}
			for (int i = 0; i < 3; i++) {
				arr[6 + i][3 * i + 2] = *x;
			}
		}
		else {
			int t = 1;
			for (int i = 0; i < 3; i++) {
				if (arr[i][3 * i] != t) arr[i][3 * i] = t;
				else arr[i][3 * i] = 2;
			}
			for (int i = 0; i < 3; i++) {
				if (arr[3 + i][3 * i + 1] != t)arr[3 + i][3 * i + 1] = t;
				else arr[3 + i][3 * i + 1] = 2;
			}
			for (int i = 0; i < 3; i++) {
				if (arr[6 + i][3 * i + 2] != t) arr[6 + i][3 * i + 2] = t;
				else arr[6 + i][3 * i + 2] = 2;
			}
		}
		FOR(i, 9) {
			FOR(j, 9) printf("%d", arr[i][j]);
			printf("\n");
		}
	}

	return 0;
}