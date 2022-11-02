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

int n, k;
um<int, int> indVal, orderInd, indOrder;
map<int, int> valInd;
us<int> medians;
pii ask(us<int> pos) {
	cout << "? ";
	for (int k : pos)cout << k << " ";
	cout << endl;
	fflush(stdout);
	pii ans;
	cin >> ans.first >> ans.second;
	return ans;
}
int main() {
	fast;
	ifstream in("input.txt");
	ofstream out("output.txt");
	cin >> n >> k;
	if (k == 1) {
		cout << "! 1" << endl;
		return 0;
	}
	us<int> tmp;
	foru(i, 0, k)tmp.insert(i + 1);
	foru(iter, 0, n - k + 1) {
		pii x = ask(tmp);
		medians.insert(x.first);
		valInd.insert(mp(x.second, x.first));
		indVal.insert(x);
		tmp.erase(x.first);
		tmp.insert(k + iter + 1);
	}
	int curr = 0;
	for (auto x : valInd) {
		orderInd.insert(mp(curr, x.second));
		indOrder.insert(mp(x.second, curr));
		curr++;
	}
	if (valInd.size() >= k) {
		us<int> big;
		foru(i, 0, k)big.insert(orderInd[i]);
		pii a = ask(big);
		cout << "! " << indOrder[a.first] + 1 << endl;
		return 0;
	}
	tmp.clear();
	foru(i, 0, n) {
		if (indVal.find(i+1) == indVal.end())tmp.insert(i+1);
	}
	int l = 0, r = 0;
	us<int> send = tmp;
	send.insert(orderInd[0]);
	send.insert(orderInd[1]);
	for (auto x : tmp) {
		send.erase(x);
		pii b = ask(send);
		if (b.first == orderInd[0])r++;
		else l++;
		send.insert(x);
	}
	cout << "! " << l + 1 << endl;
	return 0;
}