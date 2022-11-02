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
bool of = 0;
ll modpow(ll a, ll b) {
	if (!b)return 1;
	ll tmp = modpow(a, b / 2);
	if (tmp > 1e18 / tmp)of = 1;
	tmp *= tmp;
	if (b & 1) {
		if (tmp > 1e18 / a)of = 1;
		tmp *= a;
	}
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
const int sz = 3e2;
int idarr[sz], vals[sz], n;
um<string, int> ids;
int dp[sz][sz], z[sz+5];
int pre[sz];
int findFirst(int st, int dist) {
	int j = st + dist, fst = j + 1,len=n-st+1;
	vector<int> tmp;
	foru(i, 0, n - st + 1) {
		if (st+i <= j)tmp.pb(idarr[st+i]);
		else if (st+i == j + 1)tmp.pb(-1);
		else tmp.pb(idarr[st+i - 1]);
	}
	int l = 0, r = 0, k;
	z[0] = 0;
	for (int i = 1; i < len; i++) {
		if (i > r) {
			l = r = i;
			while (r < len&&tmp[r - l] == tmp[r])r++;
			z[i] = r - l;
			r--;
		}
		else {
			k = i - l;
			if (z[k] < r - i + 1)z[i] = z[k];
			else {
				l = i;
				while(r < len&&tmp[r - l] == tmp[r])r++;
				z[i] = r - l;
				r--;
			}
		}
		if (z[i] == dist + 1)return st + i - 1;
	}
	return -1;
}
int query(int s, int e) {
	if (!s)return pre[e];
	return pre[e] - pre[s - 1];
}
int main() {
	fast;
	ifstream in("input.txt");
	ofstream out("output.txt");
	int currid = 1, tot=0;
	string s;
	cin >> n;
	foru(i, 0, n) {
		cin >> s;
		if (ids.find(s) == ids.end()) {
			ids[s] = currid;
			currid++;
		}
		idarr[i] = ids[s];
		vals[i] = s.length();
		tot += vals[i];
		if (!i)pre[i] = vals[i];
		else pre[i] = pre[i - 1] + vals[i];
	}
	tot += (n - 1);
	int mn = tot;
	foru(dist, 0, n) {
		ford(i, n - dist - 1, 0) {
			if (i + 2 * dist + 1 >= n) dp[dist][i] = 1;
			else {
				int ap = findFirst(i, dist);
				if (ap == -1)dp[dist][i] = 1;
				else {
					dp[dist][i] = dp[dist][ap] + 1;
					mn = min(mn, tot - dp[dist][i] * (query(i, i + dist) - 1));
				}
			}
		}
	}
	cout << mn << endl;
	return 0;
}