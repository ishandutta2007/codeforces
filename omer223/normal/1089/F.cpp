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


const int sz = 1e9 + 5;

ll pw(ll a, int k) {
	if (!k)return 1;
	ll tmp = pw(a, k / 2);
	ll ans = tmp * tmp;
	if (k & 1)ans = ans * a;
	return ans;
}

int main() {
	fast;
	ifstream in("input.txt");
	ofstream out("output.txt");
	ll n,tmp;
	cin >> n;
	if (n <= 5) {
		cout << "NO" << endl;
		return 0;
	}
	vector<pll> div;
	tmp = n;
	for (ll i = 2; i * i <= tmp; i++) {
		if (tmp%i == 0) {
			int cnt = 0;
			while (tmp%i == 0) {
				cnt++;
				tmp /= i;
			}
			div.pb(mp(i, cnt));
		}
	}
	if (tmp != 1&& tmp != n)div.pb(mp(tmp, 1));
	if (div.size()<=1) {
		cout << "NO" << endl;
		return 0;
	}
	cout << "YES" << endl<<2<<endl;
	ll a = 1e9 , b=1, x, y,ind;
	for (int i = 0; i < div.size(); i++) {
		ll tmppw = pw(div[i].first, div[i].second);
		if (tmppw < a) {
			a = tmppw;
			ind = i;
		}
	}
	for (int i = 0; i < div.size(); i++) {
		if (i == ind)continue;
		b *= pw(div[i].first, div[i].second);
	}
	for (ll i = 1; b * i <= n; i++) {
		if ((n - 1 - i * b) % a == 0) {
			y = i;
			x = (n - 1 - i * b) / a;
			break;
		}
	}
	cout << y << " " << a << endl;
	cout << x << " " << b << endl;
	return 0;
}