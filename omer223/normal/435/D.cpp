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
using namespace std;
const int INF = 1 << 29;
typedef long long ll;
typedef unsigned long long ull;
inline int two(int n) { return 1 << n; }
ll extgcd(ll a, ll b, ll& x, ll& y) { if (b == 0) { x = 1; y = 0; return a; } else { int g = extgcd(b, a%b, y, x); y -= a / b * x; return g; } }
ll modpow(ll a, ll b) { ll res = 1; a %= MOD; for (; b; b >>= 1) { if (b & 1)res = res * a%MOD; a = a * a%MOD; }return res; }

const int sz = 420;
bool a[sz][sz]; //true == good
ll amt[sz][sz][8];
int main() {
	fast;
	ifstream in("input.txt");
	ofstream out("output.txt");
	int n, m;
	ll cnt = 0;
	string s;
	cin >> n >> m;
	foru(i, 0, n) {
		cin >> s;
		foru(j, 0, m)a[i][j] = (s[j] == '0');
	}
	foru(i, 0, n) {
		int lst = m;
		ford(j, m - 1, 0) {
			if (a[i][j])amt[i][j][0] = lst - j - 1;
			else lst = j;
		}
		lst = -1;
		foru(j, 0, m) {
			if (a[i][j])amt[i][j][4] = j - lst - 1;
			else lst = j;
		}
	}
	foru(j, 0, m) {
		int lst = n;
		ford(i, n - 1, 0) {
			if (a[i][j])amt[i][j][6] = lst - i - 1;
			else lst = i;
		}
		lst = -1;
		foru(i, 0, n) {
			if (a[i][j])amt[i][j][2] = i - lst - 1;
			else lst = i;
		}
	}
	foru(s, 0, n + m - 1) {
		int x, y;
		if (s < m) { x = 0; y = s; }
		else { x = s - m + 1; y = m - 1; }
		int prev = -1, iter = 0;
		while (x + iter < n&&y - iter >= 0) {
			if (a[x+iter][y-iter])amt[x+iter][y-iter][1] = iter - prev - 1;
			else prev = iter;
			iter++;
		}
		x += iter - 1, y -= (iter - 1);
		iter = 0;
		prev = -1;
		while (x - iter >= 0 && y + iter < m) {
			if (a[x - iter][y + iter])amt[x - iter][y + iter][5] = iter - prev - 1;
			else prev = iter;
			iter++;
		}
	}
	foru(s, 0, n + m - 1) {
		int x, y, iter = 0, prev = -1;
		if (s < m) { x = 0; y = m - s - 1; }
		else { x = s - m + 1; y = 0; }
		while (x + iter < n&&y + iter < m) {
			if (a[x + iter][y + iter])amt[x + iter][y + iter][3] = iter - prev - 1;
			else prev = iter;
			iter++;
		}
		x += (iter - 1); y += (iter - 1);
		prev = 0;
		iter = -1;
		while (x - iter >= 0 && y - iter >= 0) {
			if (a[x - iter][y - iter])amt[x - iter][y - iter][7] = iter - prev - 1;
			else prev = iter;
			iter++;
		}
	}
	foru(i, 0, n) {
		foru(j, 0, m) {
			for (int d = 2; d <= amt[i][j][0]; d += 2) {
				if (amt[i][j][1] >= d / 2 && amt[i][j + d][3] >= d / 2)cnt++;
				if (amt[i][j][7] >= d / 2 && amt[i][j + d][5] >= d / 2)cnt++;
			}
			for (int d = 2; d <= amt[i][j][2]; d += 2) {
				if (amt[i][j][1] >= d / 2 && amt[i - d][j][7] >= d / 2)cnt++;
				if (amt[i][j][3] >= d / 2 && amt[i - d][j][5] >= d / 2)cnt++;
			}
			for (int d = 1; d <= amt[i][j][1]; d++) {
				if (amt[i][j][0] >= d && amt[i - d][j + d][6] >= d)cnt++;
				if (amt[i][j][2] >= d && amt[i - d][j + d][4] >= d)cnt++;
			}
			for (int d = 1; d <= amt[i][j][3]; d++) {
				if (amt[i][j][2] >= d && amt[i - d][j - d][0] >= d)cnt++;
				if (amt[i][j][4] >= d && amt[i - d][j - d][6] >= d)cnt++;
			}
		}
	}
	cout << cnt << endl;
	return 0;
}