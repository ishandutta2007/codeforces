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

const int sz = 1e5 + 5;
ll a[sz], n;
bool is[sz];
stack<int> stk;
queue<int> q;
deque<int> de;
set<pll, greater<pll>> org;
int main() {
	fast;
	ifstream in("input.txt");
	ofstream out("output.txt");
	cin >> n;
	foru(i, 0, n) {
		cin >> a[i];
		if (a[i]) org.insert(mp(a[i], i));
		else {
			int j = 0;
			while (!org.empty() && j < 3) {
				pll t = *org.begin();
				is[t.second] = 1;
				org.erase(t);
				j++;
			}
			org.clear();
		}
	}
	int p = 0;
	foru(i, 0, n) {
		if (a[i]) {
			if (is[i]) {
				switch (p % 3) {
				case 0:
					de.push_front(a[i]);
					cout << "pushFront" << endl;
					break;
				case 1:
					q.push(a[i]);
					cout << "pushQueue" << endl;
					break;
				case 2:
					stk.push(a[i]);
					cout << "pushStack" << endl;
					break;
				}
				p++;
			}
			else {
				de.push_back(a[i]);
				cout << "pushBack" << endl;
			}
		}
		else {
			vector<string> v;
			if (!stk.empty()) {
				stk.pop();
				v.pb("popStack");
			}
			if (!q.empty()) {
				q.pop();
				v.pb("popQueue");
			}
			if (!de.empty()) {
				de.pop_front();
				v.pb("popFront");
			}
			cout << v.size();
			if (v.size())cout << " ";
			foru(i, 0, v.size()) {
				cout << v[i];
				if (i != v.size() - 1)cout << " ";
			}
			cout << endl;
			while (!stk.empty())stk.pop();
			while (!q.empty())q.pop();
			while (!de.empty())de.pop_back();
		}
	}
	return 0;
}