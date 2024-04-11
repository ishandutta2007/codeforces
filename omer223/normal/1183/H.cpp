#define MOD 1000000000000000000
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
#include <queue>
#include <bitset>
using namespace std;
const int INF = 1 << 29;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
inline int two(int n) { return 1 << n; }
ll extgcd(ll a, ll b, ll& x, ll& y) { if (b == 0) { x = 1; y = 0; return a; } else { int g = extgcd(b, a%b, y, x); y -= a / b * x; return g; } }

const int sz = 1e2 + 5;
ll dp[sz][sz][26]; //to, size, startswith
ll dpall[sz][sz]; //to, size
ll table[sz][26];
ll n, k;
string str;

void initTable() {
	for (int i = 2; i <= n; i++) {
		for (int let = 0; let < 26; let++) {
			if (str[i - 2] == 'a' + let)table[i][let] = i - 1;
			else table[i][let] = table[i - 1][let];
		}
	}
}

void initDp() {
	for (int e = 1; e <= n; e++) {
		for (int size = 1; size <= e; size++) {
			ll tot = 0;
			for (int let = 0; let < 26; let++) {
				if (e < size) dp[e][size][let] = 0;
				else if (size == 1)dp[e][size][let] = (str[e - 1] == 'a' + let || dp[e - 1][size][let]);
				else {
					if (let + 'a' != str[e - 1]) dp[e][size][let] = dp[e - 1][size][let];
					else dp[e][size][let] = dp[table[e][let]][size][let] + dpall[e - 1][size - 1] - dpall[table[e][let] - 1][size - 1];
				}
				tot += dp[e][size][let];
			}
			dpall[e][size] = tot;
		}
	}
	dpall[n][0] = 1;
}

void init() {
	initTable();
	initDp();
}

int main() {
	fast;
	ifstream in("input.txt");
	ofstream out("output.txt");
	cin >> n >> k >> str;
	init();
	ll amt = 0, price = 0, currprice, curramt;
	for (int len = n; len >= 0; len--) {
		currprice = n - len;
		curramt = dpall[n][len];
		if (amt + curramt >= k) {
			ll remain = k - amt;
			amt = k;
			price += remain * currprice;
			break;
		}
		else {
			price += curramt * currprice;
			amt += curramt;
		}
	}
	if (amt < k) cout << -1 << endl;
	else cout << price << endl;
	return 0;
}