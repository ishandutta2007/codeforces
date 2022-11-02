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
typedef tuple<int, int, int, int> qu;
typedef unsigned long long ull;
typedef long double ld;
inline int two(int n) { return 1 << n; }
ll extgcd(ll a, ll b, ll& x, ll& y) { if (b == 0) { x = 1; y = 0; return a; } else { int g = extgcd(b, a%b, y, x); y -= a / b * x; return g; } }
ll modpow(ll a, ll b) { ll res = 1; a %= MOD; for (; b; b >>= 1) { if (b & 1)res = res * a%MOD; a = a * a%MOD; }return res; }
void mult(ll &a, ll b) {
	a = ((a % MOD) * (b % MOD)) % MOD;
}
void add(ll &a, ll b) {
	a = ((a % MOD) + (b % MOD)) % MOD;
}
void subtract(ll &a, ll b) {
	if (a >= b)a = (a - b) % MOD;
	else a = (a - b) % MOD + MOD;
}
const int sz = 1e3 + 5;
char a[sz][sz][4];
ll times[sz][sz][4];
string str = "++++-|-||-|-^>v<>v<^v<^><^>vURDLRDLUDLURLURD****", allowstr = "+|^LRD+->LUD+|vLRU+-<RUD";
char carr[] = { '+', '-','|','^','>','v','<','U','R','D','L','*' };
int n, m, xs, ys, xe, ye;
um<char, int> mem;
us<char> allow[4];//URDL
void initMem() {
	foru(i, 0, 12)mem[carr[i]] = i;
	foru(i, 0, 4) {
		foru(j, 0, 6)allow[i].insert(allowstr[6 * i + j]);
	}
}
void input() {
	initMem();
	cin >> n >> m;
	foru(i, 0, n) {
		foru(j, 0, m) {
			cin >> a[i][j][0];
			foru(k, 1, 4)a[i][j][k] = str[mem[a[i][j][0]] * 4 + k];
			foru(k, 0, 4)times[i][j][k] = 1e15;
		}
	}
	cin >> xs >> ys >> xe >> ye;
	xs--;
	ys--;
	xe--;
	ye--;
}
int main() {
	fast;
	ifstream in("input.txt");
	ofstream out("output.txt");
	input();
	queue<qu> q;
	q.push(make_tuple(xs, ys, 0, 0)); //x,y,universe,time
	times[xs][ys][0] = 0;
	while (!q.empty()) {
		qu p = q.front(); q.pop();
		int x = get<0>(p), y = get<1>(p), u = get<2>(p), t = get<3>(p);
		if (x > 0 && has(allow[0], a[x][y][u]) && has(allow[2], a[x - 1][y][u]) && times[x - 1][y][u] > t + 1) {
			times[x - 1][y][u] = t + 1;
			q.push(make_tuple(x - 1, y, u, t + 1));
		}
		if (x < n - 1 && has(allow[2], a[x][y][u]) && has(allow[0], a[x + 1][y][u]) && times[x + 1][y][u] > t + 1) {
			times[x + 1][y][u] = t + 1;
			q.push(make_tuple(x + 1, y, u, t + 1));
		}
		if (y > 0 && has(allow[3], a[x][y][u]) && has(allow[1], a[x][y - 1][u]) && times[x][y - 1][u] > t + 1) {
			times[x][y - 1][u] = t + 1;
			q.push(make_tuple(x, y - 1, u, t + 1));
		}
		if (y < m - 1 && has(allow[1], a[x][y][u]) && has(allow[3], a[x][y + 1][u]) && times[x][y + 1][u] > t + 1) {
			times[x][y + 1][u] = t + 1;
			q.push(make_tuple(x, y + 1, u, t + 1));
		}
		if (times[x][y][(u + 1) % 4] > t + 1) {
			times[x][y][(u + 1) % 4] = t + 1;
			q.push(make_tuple(x, y, (u + 1) % 4, t + 1));
		}
	}
	ll mn = 1e15;
	foru(ss, 0, 4)mn = min(mn, times[xe][ye][ss]);
	if(mn<1e15)cout << mn << endl;
	else cout << -1 << endl;
	return 0;
}