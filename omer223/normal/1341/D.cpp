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
#include <intrin.h>
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

int toNum(string str) {
	int l = str.length(), mult = 1;
	int res = 0;
	ford(i, l - 1, 0) {
		res += (str[i] - '0') * mult;
		mult <<= 1;
	}
	return res;
}

int distToDigit(int src, int digit) {
	int to = -1, count = 0;
	switch (digit) {
	case 0:
		to = 119;
		break;
	case 1:
		to = 18;
		break;
	case 2:
		to = 93;
		break;
	case 3:
		to = 91;
		break;
	case 4:
		to = 58;
		break;
	case 5:
		to = 107;
		break;
	case 6:
		to = 111;
		break;
	case 7:
		to = 82;
		break;
	case 8:
		to = 127;
		break;
	case 9:
		to = 123;
		break;
	}
	if (to == -1) return -1;
	foru(i, 0, 7) {
		if (src & 1) {
			if (!(to & 1)) return -1;
		}
		else {
			if (to & 1) count++;
		}
		src >>= 1;
		to >>= 1;
	}
	return count;
}

int validDigit(int src) {
	int to = -1;
	switch (src) {
	case 119:
		return 0;
	case 18:
		return 1;
	case 93:
		return 2;
	case 91:
		return 3;
		break;
	case 58:
		return 4;
		break;
	case 107:
		return 5;
		break;
	case 111:
		return 6;
		break;
	case 82:
		return 7;
		break;
	case 127:
		return 8;
		break;
	case 123:
		return 9;
		break;
	}
	return -1;
}

ll n, k;
string tmp;
ll a[2000];
pii dp[2001][2001]; //with k turn ons, from n onward (digit, ptr to previous place)

int main() {
	fast;
	ifstream in("input.txt");
	ofstream out("output.txt");
	cin >> n >> k;
	foru(i, 0, n) {
		cin >> tmp;
		a[i] = toNum(tmp);
	}
	int bstDigit, bstTmp, d;
	foru(on, 0, k + 1) {
		ford(j, n - 1, 0) {
			int dig = validDigit(a[j]);
			if (on == 0) {
				if (j == n - 1) {
					if (dig != -1) {
						dp[on][j].first = dig;
						dp[on][j].second = -2;
					}
					else {
						dp[on][j].first = -1;
						dp[on][j].second = -1;
					}
				}
				else {
					if (dig != -1 && dp[on][j + 1].first != -1) {
						dp[on][j].first = dig;
						dp[on][j].second = on;
					}
					else {
						dp[on][j].first = -1;
						dp[on][j].second = -1;
					}
				}
			}
			else {
				bstDigit = -1, bstTmp = -1;
				if (dig != -1) {
					if (j == n - 1 && on == 0) {
						bstDigit = dig;
						bstTmp = on;
					}
					else if(j < n - 1 && dp[on][j + 1].first != -1){
						bstDigit = dig;
						bstTmp = on;
					}
				}
				foru(i, 0, 10) {
					d = distToDigit(a[j], i);
					if (d == -1 || on < d || (j == n - 1 && on > d)) continue;
					if (i > bstDigit && (j == n - 1 || dp[on - d][j + 1].first != -1)) {
						bstDigit = i;
						bstTmp = on - d;
					}
				}
				dp[on][j].first = bstDigit;
				dp[on][j].second = bstTmp;
			}
		}
	}
	int r;
	if (dp[k][0].first == -1) {
		cout << -1 << endl;
		return 0;
	}
	foru(i, 0, n) {
		if (i == 0) {
			cout << dp[k][i].first;
			r = dp[k][i].second;
		}
		else {
			cout << dp[r][i].first;
			r = dp[r][i].second;
		}
	}
	cout << endl;
	return 0;
}