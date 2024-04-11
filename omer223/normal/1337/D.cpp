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

ll gems[3][100000];
ll n[3];

ll foo(ll a, ll b, ll c) {
	return (a - b) * (a - b) + (a - c) * (a - c) + (b - c) * (b - c);
}

ll bestFind(ll a, ll b, int t) {
	ll mid = (a + b) / 2, l = 0, r = n[t] - 1, guess = (l + r + 1) / 2, bst = -1;
	while (l <= r) {
		guess = (l + r + 1) / 2;
		if (gems[t][guess] == mid) return mid;
		else if (gems[t][guess] > mid) {
			r = guess - 1;
		}
		else {
			l = guess + 1;
		}
		if (bst == -1 || abs(gems[t][guess] - mid) < abs(bst - mid)) bst = gems[t][guess];
	}
	return bst;
}

int main() {
	fast;
	ifstream in("input.txt");
	ofstream out("output.txt");
	ll t, bst;
	cin >> t;
	vector<vector<int>>c{ {0,1,2},{0,2,1},{1,2,0},{1,0,2},{2,0,1},{2,1,0} };
	while (t--) {
		cin >> n[0] >> n[1] >> n[2];
		bst = -1;
		FOR(i, n[0]) cin >> gems[0][i];
		FOR(i, n[1]) cin >> gems[1][i];
		FOR(i, n[2]) cin >> gems[2][i];
		sort(gems[0], gems[0] + n[0]);
		sort(gems[1], gems[1] + n[1]);
		sort(gems[2], gems[2] + n[2]);
		for (vector<int> v : c) {
			ll p1 = 0, p2 = 0;
			for (ll p1 = 0; p1 < n[v[0]]; p1++) {
				while (p2 < n[v[1]] && gems[v[1]][p2] < gems[v[0]][p1]) p2++;
				if (p2 == n[v[1]]) p2--;
				else if (p2 == 0) p2 = 0;
				else if (abs(gems[v[1]][p2] - gems[v[0]][p1]) > abs(gems[v[1]][p2 - 1] - gems[v[0]][p1])) p2--;
				if (bst == -1) bst = foo(bestFind(gems[v[0]][p1], gems[v[1]][p2], v[2]), gems[v[0]][p1], gems[v[1]][p2]);
				else bst = min(bst, foo(bestFind(gems[v[0]][p1], gems[v[1]][p2], v[2]), gems[v[0]][p1], gems[v[1]][p2]));
			}
		}
		cout << bst << endl;
	}
	return 0;
}