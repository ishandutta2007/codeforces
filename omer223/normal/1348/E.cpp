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
pll arr[505];
ll n, k, lastvalid;
bool dp[505][505], pd[505][505];

void csort() {
	foru(i, 0, n - 1) {
		foru(j, 0, n - i - 1) {
			if (arr[j].first + arr[j].second > arr[j + 1].first + arr[j + 1].second) swap(arr[j], arr[j + 1]);
		}
	}
}

int main() {
	fast;
	ifstream in("input.txt");
	ofstream out("output.txt");
	ll s1 = 0, s2 = 0;
	cin >> n >> k;
	lastvalid = n;
	foru(i, 0, n) {
		cin >> arr[i].first >> arr[i].second;
		s1 += arr[i].first;
		s2 += arr[i].second;
	}
	vector<pll> f, s;
	csort();
	ford(i, n - 1, 0) {
		if (arr[i].first + arr[i].second < k)break;
		f.pb(mp(max(0LL, k - arr[i].second), min(k, arr[i].first)));
		s.pb(mp(max(0LL, k - arr[i].first), min(k, arr[i].second)));
		lastvalid--;
	}
	if (lastvalid == n || s1 % k == 0 || s2 % k == 0)
	{
		cout << s1 / k + s2 / k << endl; return 0;
	}
	ll rem1 = s1 % k, rem2 = s2 % k;
	int sz = f.size();
	bool flag = false;
	dp[0][0] = 1; pd[0][0] = 1;
	foru(until, 1, sz + 1) {
		foru(r, 0, k) {
			ll left = f[until - 1].first, right = f[until - 1].second, lmod = left%k, rmod = right%k;
			if (right - left >= k) {
				foru(i, 0, k) {
					dp[until][r] |= dp[until - 1][(r - i + k) % k];
					if (dp[until][r])break;
				}
			}
			else if (lmod <= rmod) {
				foru(i, lmod, rmod + 1) {
					dp[until][r] |= dp[until - 1][(r - i + k) % k];
					if (dp[until][r])break;
				}
			}
			else {
				foru(i, lmod, k) {
					dp[until][r] |= dp[until - 1][(r - i + k) % k];
					if (dp[until][r])break;
				}
				if (dp[until][r])continue;
				foru(i, 0, rmod + 1) {
					dp[until][r] |= dp[until - 1][(r - i + k) % k];
					if (dp[until][r])break;
				}
			}
			dp[until][r] |= dp[until - 1][r];
		}
		if (dp[until][rem1]) {
			cout << (s1 + s2) / k << endl;
			return 0;
		}
	}
	foru(until, 1, sz + 1) {
		foru(r, 0, k) {
			ll left = s[until - 1].first, right = s[until - 1].second, lmod = left % k, rmod = right % k;
			if (right - left >= k) {
				foru(i, 0, k) {
					pd[until][r] |= pd[until - 1][(r - i + k) % k];
					if (pd[until][r])break;
				}
			}
			else if (lmod <= rmod) {
				foru(i, lmod, rmod + 1) {
					pd[until][r] |= pd[until - 1][(r - i + k) % k];
					if (pd[until][r])break;
				}
			}
			else {
				foru(i, lmod, k) {
					pd[until][r] |= pd[until - 1][(r - i + k) % k];
					if (pd[until][r])break;
				}
				if (pd[until][r])continue;
				foru(i, 0, rmod + 1) {
					pd[until][r] |= pd[until - 1][(r - i + k) % k];
					if (pd[until][r])break;
				}
			}
			pd[until][r] |= pd[until - 1][r];
		}
		if (pd[until][rem2]) {
			cout << (s1 + s2) / k << endl;
			return 0;
		}
	}
	cout << s1 / k + s2 / k << endl;
	return 0;
}