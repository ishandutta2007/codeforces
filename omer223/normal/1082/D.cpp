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
#include <bitset>
#include <numeric>
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

pll arr[500];
vector<pll> ans;
int main() {
	fast;
	ifstream in("input.txt");
	ofstream out("output.txt");
	ll n, s = 0, s1 = 0, s2 = 0, cnt = 0;
	cin >> n;
	foru(i, 0, n) {
		cin >> arr[i].first;
		s += arr[i].first;
		if (arr[i].first == 1)s1++;
		else {
			s2 += arr[i].first; cnt++;
		}
		arr[i].second = i;
	}
	sort(arr, arr + n);
	if (s < 2 * n - 2 || s2 - 2 * cnt + 2 < s1) {
		cout << "NO" << endl;
		return 0;
	}
	cout << "YES ";
	if (arr[2].first > 1) {
		cout << n - 1 << endl;
		cout << n - 1 << endl;
		foru(i, 1, n - 1) cout << arr[i].second + 1 << " " << arr[i + 1].second + 1 << endl;
		cout << arr[0].second + 1<< " " << arr[n - 1].second + 1<< endl;
		return 0;
	}
	if (cnt == 1) {
		cout << 2 << endl;
		cout << n - 1 << endl;
		foru(i, 0, n - 1) cout << arr[i].second + 1<< " " << arr[n - 1].second + 1<< endl;
		return 0;
	}
	int bigbegin = s1;
	cout << cnt + 1 << endl;
	foru(i, bigbegin + 1, n - 1) ans.pb(mp(arr[i].second + 1, arr[i + 1].second + 1));
	ans.pb(mp(arr[bigbegin].second + 1, arr[n - 1].second + 1));
	ans.pb(mp(arr[0].second + 1, arr[bigbegin].second + 1));
	ans.pb(mp(arr[1].second + 1, arr[bigbegin + 1].second + 1));
	int r = bigbegin;
	foru(i, 2, s1) {
		while (arr[r].first <= 2) r++;
		if (r == n)return 0;
		ans.pb(mp(arr[i].second + 1, arr[r].second + 1));
		arr[r].first--;
	}
	cout << ans.size() << endl;
	for (auto x : ans) cout << x.first << " " << x.second << endl;
	return 0;
}