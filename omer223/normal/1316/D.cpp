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
ll modpow(ll a, ll b) {
	if (!b)return 1;
	ll tmp = modpow(a, b / 2);
	tmp *= tmp;
	if (b & 1)tmp *= a;
	return tmp;
}
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

const int sz = 1e3;
pii a[sz][sz];
int n;
bool wrong = false, vis[sz][sz];
char ans[sz][sz];
queue<pii> fx;
us<int> cyc;

inline int tn(int x, int y) {
	return x * n + y;
}
void dfscycle(int x, int y,int tox, int toy, char dir, bool lookcycle) {
	vis[x][y] = 1;
	if (lookcycle)cyc.erase(tn(x, y));
	if (dir != 'X') {
		ans[x][y] = dir;
	}
	if (x > 0 && !vis[x - 1][y] && a[x - 1][y].first == tox && a[x - 1][y].second == toy) {
		if (!lookcycle || cyc.find(tn(x -1 ,y)) != cyc.end())dfscycle(x - 1, y,tox,toy, 'D',lookcycle);
	}
	if (x < n - 1 && !vis[x + 1][y] && a[x + 1][y].first == tox && a[x + 1][y].second == toy) {
		if (!lookcycle || cyc.find(tn(x + 1, y)) != cyc.end())dfscycle(x + 1, y,tox,toy, 'U',lookcycle);
	}
	if (y > 0 && !vis[x][y - 1] && a[x][y - 1].first == tox && a[x][y - 1].second == toy) {
		if (!lookcycle || cyc.find(tn(x, y - 1)) != cyc.end())dfscycle(x, y - 1,tox,toy, 'R',lookcycle);
	}
	if (y < n - 1 && !vis[x][y + 1] && a[x][y + 1].first == tox && a[x][y + 1].second == toy) {
		if(!lookcycle||cyc.find(tn(x,y+1))!=cyc.end())dfscycle(x, y + 1,tox,toy, 'L',lookcycle);
	}
}
bool dealWithCycles() {
	while (!cyc.empty() && !wrong) {
		int p = *cyc.begin();
		cyc.erase(p);
		int x = p / n, y = p % n;
		if (x > 0 && cyc.find(tn(x - 1, y)) != cyc.end()) ans[x][y] = 'U';
		else if (x < n - 1 && cyc.find(tn(x + 1, y)) != cyc.end()) ans[x][y] = 'D';
		else if (y > 0 && cyc.find(tn(x, y - 1)) != cyc.end()) ans[x][y] = 'L';
		else if (y < n - 1 && cyc.find(tn(x, y + 1)) != cyc.end()) ans[x][y] = 'R';
		else {
			wrong = 1;
			break;
		}
		dfscycle(x, y,-2,-2, 'X',true);
	}
	if (wrong)return false;
	return true;
}

int main() {
	fast;
	ifstream in("input.txt");
	ofstream out("output.txt");
	cin >> n;
	foru(i, 0, n) {
		foru(j, 0, n) {
			cin >> a[i][j].first >> a[i][j].second;
			a[i][j].first--;
			a[i][j].second--;
			if (a[i][j].first == i && a[i][j].second == j)fx.push(mp(i, j));
			if (a[i][j].first == -2 && a[i][j].second == -2)cyc.insert(i*n + j);
		}
	}
	bool is = dealWithCycles();
	if (!is) {
		cout << "INVALID" << endl;
		return 0;
	}
	while (!fx.empty()) {
		pii t = fx.front();
		fx.pop();
		ans[t.first][t.second] = 'X';
		dfscycle(t.first, t.second, t.first, t.second, 'X', false);
	}
	foru(i, 0, n) {
		foru(j, 0, n) {
			if (!vis[i][j]) {
				cout << "INVALID" << endl;
				return 0;
			}
		}
	}
	cout << "VALID" << endl;
	foru(i, 0, n) {
		foru(j, 0, n)cout << ans[i][j];
		cout << endl;
	}
	return 0;
}