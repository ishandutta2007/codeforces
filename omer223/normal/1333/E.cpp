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

int res[500][500];

void print(int n) {
	FOR(i, n) {
		FOR(j, n) {
			cout << res[i][j] << " ";
		}
		cout << endl;
	}
}

int main() {
	fast;
	ifstream in("input.txt");
	ofstream out("output.txt");
	int n, add;
	bool bottomLeft = false;
	cin >> n;
	if (n < 3) cout << -1 << endl;
	else {
		add = n * n - 9;
		res[0][0] = 2 + add;
		res[0][1] = 5 + add;
		res[0][2] = 9 + add;
		res[1][0] = 3 + add;
		res[1][1] = 4 + add;
		res[1][2] = 6 + add;
		res[2][0] = 1 + add;
		res[2][1] = 8 + add;
		res[2][2] = 7 + add;
		int adder = 1;
		for (int i = 3; i < n; i++) {
			add -= (2 * i + 1);
			adder = 1;
			if (bottomLeft) { //begins from
				for (int j = 0; j <= i; j++) {
					res[i][j] = adder + add;
					adder++;
				}
				for (int j = i - 1; j >= 0; j--) {
					res[j][i] = adder + add;
					adder++;
				}
			}
			else {
				for (int j = 0; j < i; j++) {
					res[j][i] = adder + add;
					adder++;
				}
				for (int j = i; j >= 0; j--) {
					res[i][j] = adder + add;
					adder++;
				}
			}
			bottomLeft = !bottomLeft;
		}
		print(n);
	}
	
	return 0;
}