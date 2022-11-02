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

string str;
int n;

bool dfs(int src, int k) {
	if (src + k >= n - 1) return true;
	for (int i = src + k; i > src; i--) {
		if (str[i] == 'R') return dfs(i, k);
	}
	return false;
}

int main() {
	fast;
	ifstream in("input.txt");
	ofstream out("output.txt");
	int t, k, currCount = 0;
	string str;
	cin >> t;
	set<char> res;
	while (t--) {
		res.clear();
		cin >> str;
		FOR(i, str.length()) {
			if (i == 0 || str[i] != str[i - 1]) {
				if (i != 0 && (currCount & 1)) res.insert(str[i - 1]);
				currCount = 1;
			}
			else currCount++;
		}
		if (currCount & 1) res.insert(str[str.length() - 1]);
		for (char c : res) cout << c;
		cout << endl;
	}
	return 0;
}