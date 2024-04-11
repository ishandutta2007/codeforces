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
#include <stack>
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
const int sz = 1e5 + 5;
int n, m, k,st=-1,en=-1,odd=0,even=0,depth[sz];
list<int> adj[sz];
stack<int> stk;
bitset<sz> vis;

void dfstree(int src, int prev, int dep) {
	if (dep & 1)odd++;
	else even++;
	depth[src] = dep & 1;
	for (auto x : adj[src]) {
		if (x == prev)continue;
		dfstree(x, src, dep + 1);
	}
}

bool dfs(int src, int prev) {
	stk.push(src);
	vis[src] = 1;
	for (auto x : adj[src]) {
		if (x == prev)continue;
		else if (vis[x]) {
			st = x;
			en= src;
			return true;
		}
		else {
			bool tmp = dfs(x, src);
			if (tmp)return true;
		}
	}
	stk.pop();
	return false;
}

int main() {
	fast;
	ifstream in("input.txt");
	ofstream out("output.txt");
	cin >> n >> m >> k;
	int a, b;
	foru(i, 1, m + 1) {
		cin >> a >> b;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	bool res = dfs(1,-1);
	if (!res) {
		dfstree(1, -1,0);
		cout << 1 << endl;
		int cnt = 0, k2 = k / 2 + (k & 1);
		if (odd >= even) {
			foru(i, 1, n + 1) {
				if (depth[i]) {
					cout << i << " "; cnt++;
				}
				if (cnt == k2)break;
			}
		}
		else {
			foru(i, 1, n + 1) {
				if (!depth[i]) {
					cout << i << " "; cnt++;
				}
				if (cnt == k2)break;
			}
		}
	}
	else {
		vi cycle;
		while (stk.top() != st) {
			cycle.pb(stk.top());
			stk.pop();
		}
		cycle.pb(st);
		if (cycle.size() <= k) {
			cout << 2 << endl << cycle.size() << endl;
			for (int pp : cycle)cout << pp << " ";
			cout << endl;
		}
		else {
			int cyclesz = cycle.size(),cnt=0,k2=k/2+(k&1);
			us<int> indset;
			bool good = true;
			foru(i, 0, cyclesz) {
				indset.insert(cycle[i]);
				for (auto x : adj[cycle[i]]) {
					if (indset.find(x) != indset.end()) {
						cout << 2 << endl<<i+1<<endl;
						foru(j, 0, i + 1)cout << cycle[j] << " ";
						good = false;
						break;
					}
				}
				if (!good||indset.size()==k2)break;
				i++;
			}
			if (good) {
				cout << 1 << endl;
				for (int num : indset)cout << num << " ";
				cout << endl;
			}
		}
	}
	return 0;
}