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
#include <cmath>
#include <math.h>
#include <unordered_map>
#include <iomanip>
#include <set>
#include <unordered_set>
#include <fstream>
#include <algorithm>
#include <chrono>
#include <stack>
#include <numeric>
#include <queue>
#include <bitset>
using namespace std;
const int INF = 1 << 29;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
inline int two(int n) { return 1 << n; }
ll extgcd(ll a, ll b, ll& x, ll& y) { if (b == 0) { x = 1; y = 0; return a; } else { int g = extgcd(b, a%b, y, x); y -= a / b * x; return g; } }
ll modpow(ll a, ll b) { ll res = 1; a %= MOD; for (; b; b >>= 1) { if (b & 1)res = res * a%MOD; a = a * a%MOD; }return res; }
ll a[8][3];
ld d[8], pp[3];
map<ll, int> cnt;
ll b[8][3] = { {-13, -10, -6},
{-13 ,2  ,-15 },
{2 ,-10 ,-6},
{2, 2, -15},
{-13, -1, 6},
{2, -1, 6},
{-13, 11, -3},
{2, 11, -3 } };
inline ll dist(int i, int j) {
	ll ans = 0;
	foru(k, 0, 3)ans += (a[i][k] - a[j][k]) * (a[i][k] - a[j][k]);
	return ans;
}

bool foo(int i) {
	if (i == 8) {
		if (cnt.size() != 3)return false;
		auto x = cnt.begin();
		int ind = 0;
		while (ind < 3 && x != cnt.end()) {
			pp[ind] = x->first;
			x++;
			ind++;
		}
		return (pp[0] * 2 == pp[1] && pp[0] * 3 == pp[2] && cnt[pp[0]] == 12 && cnt[pp[1]] == 12 && cnt[pp[2]] == 4);
	}
	else {
		do {
			foru(j, 0, i) cnt[dist(i,j)]++;
			if (cnt.size() <= 3) {
				bool ans = foo(i + 1);
				if (ans)return true;
			}
			foru(j, 0, i) {
				ll tt = dist(i, j);
				if (cnt[tt] == 1)cnt.erase(tt);
				else cnt[tt]--;
			}
		} while (next_permutation(a[i], a[i] + 3));
	}
	return false;
}

int main() {
	fast;
	ifstream in("input.txt");
	ofstream out("output.txt");
	ll b;
	foru(i, 0, 8) {
		foru(j, 0, 3) cin >> a[i][j];
		sort(a[i], a[i] + 3);
	}
	bool res = foo(0);
	if (res) {
		cout << "YES" << endl;
		foru(i, 0, 8) {
			foru(j, 0, 3)cout << a[i][j] << " ";
			cout << endl;
		}
	}
	else cout << "NO" << endl;
	return 0;
}