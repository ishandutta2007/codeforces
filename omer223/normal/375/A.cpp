#define MOD 1000000000000000005
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
bool of = false;
ll pw(ll a, ll b) {
	if (!b)return 1;
	ll tmp = pw(a, b / 2);
	if (tmp > 1e9) of = 1;
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

string rems[7] = { "1869", "1968", "1689","6891","1698","9168","1896" };
int cnt[10];
int main() {
	fast;
	ifstream in("input.txt");
	ofstream out("output.txt");
	string a;
	cin >> a;
	for (char c : a)cnt[c - '0']++;
	cnt[1]--;
	cnt[6]--;
	cnt[8]--;
	cnt[9]--;
	ll rem = 0;
	string ans = "";
	bool f = 0;
	foru(i, 1, 10)f |= (cnt[i] > 0);
	if (!f) {
		cout << rems[0];
		while (cnt[0]--)cout << 0;
		cout << endl;
		return 0;
	}
	foru(i, 1, 11) {
		while (cnt[i%10]--) {
			rem *= 10;
			rem += (i%10);
			rem %= 7;
			ans.pb((i%10) + '0');
		}
	}
	rem *= 10000;
	rem %= 7;
	ans += rems[(7-rem)%7];
	cout << ans << endl;
	return 0;
}