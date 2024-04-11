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
#include <stack>
#include <deque>
#include <queue>
#include <bitset>
using namespace std;
const int INF = 1 << 29;
typedef long long ll;
typedef unsigned long long ull;
inline int two(int n) { return 1 << n; }
ll extgcd(ll a, ll b, ll& x, ll& y) { if (b == 0) { x = 1; y = 0; return a; } else { int g = extgcd(b, a%b, y, x); y -= a / b * x; return g; } }
ll modpow(ll a, ll b) { ll res = 1; a %= MOD; for (; b; b >>= 1) { if (b & 1)res = res * a%MOD; a = a * a%MOD; }return res; }

ll n, k;
const int sz = 5e3 + 5, hsz=11;
ll c[sz], f[sz], h[hsz];
map<ll, ll> mem;
vector<ll> favs, favamt, favcards;
ll calc(int i) {
	ll people = favamt[i], stock = favcards[i];
	if (people * k <= stock)return h[k] * people;
	vector<vector<ll>> dp(people + 1, vector<ll>(stock + 1, 0));
	for (int pep = 0; pep <= people; pep++) {
		for (int st = 0; st <= stock; st++) {
			if (!pep || !st)dp[pep][st] = 0;
			else {
				for (int take = 0; take <= k && st >= take; take++) {
					dp[pep][st] = max(dp[pep][st], dp[pep - 1][st - take] + h[take]);
				}
			}
		}
	}
	return dp[people][stock];
}
int main() {
	fast;
	ifstream in("input.txt");
	ofstream out("output.txt");
	cin >> n >> k;
	foru(i, 0, n*k)cin >> c[i];
	foru(i, 0, n)cin >> f[i];
	foru(i, 0, k)cin >> h[i+1];
	foru(i, 0, n) {
		if (mem.find(f[i]) == mem.end()) {
			mem[f[i]] = favs.size();
			favs.pb(f[i]);
			favamt.pb(1);
		}
		else favamt[mem[f[i]]]++;
	}
	favcards.resize(favs.size());
	foru(i, 0, favs.size())favcards[i] = 0;
	foru(i, 0, k*n) {
		if (mem.find(c[i]) == mem.end())continue;
		favcards[mem[c[i]]]++;
	}
	ll ans = 0;
	foru(i, 0, favs.size()) ans += calc(i);
	cout << ans << endl;
	return 0;
}