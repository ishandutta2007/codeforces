#define MOD 998244353
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

const int sz = 3e5 + 5;
pll x[sz];
ll n, k, edges[sz], pre[sz], dpup[sz], dpdown[sz], preup[sz], predown[sz];

void preCalc() {
	foru(i, 1, n) {
		pre[i] = pre[i - 1] + edges[i];
		dpup[i] = (2 * i - 1)*edges[i];
		dpdown[n - i] = (2 * i - 1)*edges[n - i];
	}
	foru(i, 1, n) {
		preup[i] = preup[i - 1] + dpup[i];
		predown[i] = predown[i - 1] + dpdown[i];
	}
}
ll downquery(int i, int j) {
	return predown[j] - predown[i - 1];
}
ll upquery(int i, int j) {
	return preup[j] - preup[i - 1];
}
ll query(int i, int j) {
	return pre[j] - pre[i - 1];
}
int main() {
	fast;
	ifstream in("input.txt");
	ofstream out("output.txt");
	cin >> n;
	foru(i, 0, n) {
		cin >> x[i].first;
		x[i].second = i;
	}
	cin >> k;
	sort(x, x + n);
	foru(i, 0, n - 1)edges[i + 1] = x[i + 1].first - x[i].first;
	preCalc();
	ll curr = 0;
	foru(i, 1, k)curr += ((i*(k - i))*edges[i]);
	ll f = k / 2, prevsum=curr,mn=curr,mni=1;
	foru(i, k, n) {
		ll prevstart = i - k + 1, prevfirstuntil = prevstart + f - 1, prevsecondstart = prevfirstuntil + 1, prevend = i - 1;
		curr += k * query(prevsecondstart, i);
		curr -= (downquery(prevsecondstart, i) - (n - 1 - i) * 2 * query(prevsecondstart, i));
		curr -= k * query(prevstart, prevfirstuntil);
		curr += (upquery(prevstart, prevfirstuntil) - (prevstart - 1)* 2 * query(prevstart, prevfirstuntil));
		if (mn > curr) {
			mn = curr;
			mni = i - k + 2;
		}
	}
	cout << x[mni - 1].second + 1 << " ";
	foru(i, 0, k - 1) {
		cout << x[mni + i].second + 1 << " ";
	}
	cout << endl;
	return 0;
}