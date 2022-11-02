#define MOD 998244353
#define fast ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define foru(i, k, n) for (ll i = k; i < n; i++)
#define ford(i, k, n) for (ll i = k; i >= n; i--)
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
#include <numeric>
using namespace std;
const int INF = 1 << 29;
typedef long long ll;
typedef unsigned long long ull;
inline int two(int n) { return 1 << n; }
ll extgcd(ll a, ll b, ll& x, ll& y) { if (b == 0) { x = 1; y = 0; return a; } else { int g = extgcd(b, a%b, y, x); y -= a / b * x; return g; } }
ll modpow(ll a, ll b) { ll res = 1; a %= MOD; for (; b; b >>= 1) { if (b & 1)res = res * a%MOD; a = a * a%MOD; }return res; }

struct lesson {
	ll a, b, c,ind;
	lesson() {
		a = b = c = 0;
		ind = 0;
	}
};
struct {
	bool operator()(const lesson& x, const lesson& y) {
		if (x.c != y.c)return x.c <= y.c;
		else if (x.a != y.a)return x.a <= y.a;
		else if(x.b!=y.b)return x.b <= y.b;
		else return x.ind <= y.ind;
	}
}lessonCmp;
const int sz = 51, len = 101;
ll dp[sz][sz][len]; //amt, starts, pos
int to[sz][sz][len], way[sz][sz][len];
ll n, m, k;
lesson les[sz];
int main() {
	fast;
	ifstream in("input.txt");
	ofstream out("output.txt");
	cin >> n >> m >> k;
	foru(i, 0, m) {
		cin >> les[i].a >> les[i].b >> les[i].c;
		les[i].ind = i;
	}
	sort(les, les + m, lessonCmp);
	foru(amt, 1, n + 1) {
		ford(i, m - 1, 0) {
			foru(co, les[i].a, les[i].b + 1) {
				if (amt == 1) {
					dp[amt][i][co - les[i].a] = co;
					to[amt][i][co - les[i].a] = -1;
				}
				else {
					foru(j, i + 1, m) {
						if (les[j].c <= les[i].c)continue;
						if (co + k >= les[j].a&&co + k <= les[j].b) {
							if (dp[amt][i][co - les[i].a] < dp[amt - 1][j][co + k - les[j].a] + co&& dp[amt - 1][j][co + k - les[j].a]) {
								dp[amt][i][co - les[i].a] = dp[amt - 1][j][co + k - les[j].a] + co;
								to[amt][i][co - les[i].a] = j;
								way[amt][i][co - les[i].a] = 1;
							}
						}
						if (co * k >= les[j].a&&co * k <= les[j].b) {
							if (dp[amt][i][co - les[i].a] < dp[amt - 1][j][co * k - les[j].a] + co&& dp[amt - 1][j][co * k - les[j].a]) {
								dp[amt][i][co - les[i].a] = dp[amt - 1][j][co * k - les[j].a] + co;
								to[amt][i][co - les[i].a] = j;
								way[amt][i][co - les[i].a] = 2;
							}
						}
					}
				}
			}
		}
	}
	ll mxval = 0,bsti,bstco;
	foru(i, 0, m) {
		foru(co, les[i].a, les[i].b + 1) {
			if (mxval < dp[n][i][co - les[i].a]) {
				mxval = dp[n][i][co - les[i].a];
				bsti = i;
				bstco = co;
			}
		}
	}
	if (!mxval) {
		cout << "NO" << endl;
	}
	else {
		cout << "YES" << endl;
		ford(i, n, 1) {
			cout << les[bsti].ind + 1 << " " << bstco<<endl;
			ll tmpco = bstco;
			if (way[i][bsti][bstco - les[bsti].a] == 1)bstco += k;
			else bstco *= k;
			bsti = to[i][bsti][tmpco - les[bsti].a];
		}
	}
	return 0;
}