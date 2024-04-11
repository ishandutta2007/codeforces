#define MOD 998244353
#define fast ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back
#define mp make_pair
#define has(mpp, x) mpp.find(x) != mpp.end()
#define nohas(set, x) mpp.find(x) == mpp.end()
#define inc(mpp, x) {if(has(mpp, x)) mpp[x]++; else mpp.insert(mp(x,1));}
#define decc(mpp, x) {if(has(mpp, x)) {if(mpp[x] > 1) mpp[x]--; else mpp.erase(x);}}
#define F first
#define S second
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
#include <numeric>
#include <bitset>
#include <stack>
using namespace std;
const int INF = 1 << 29;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<vll> vvll;

int main() {
	fast;
	int t;
	ll c, h, mid;
	cin >> t;
	while (t--) {
		cin >> h >> c >> mid;
		h -= c; mid -= c; c = 0;
		if (mid <= h / 2) {
			cout << 2 << endl;
			continue;
		}
		else if (mid == h) {
			cout << 1 << endl;
			continue;
		}
		ll supposed = mid / (2 * mid - h);
		if (mid % (2 * mid - h) == 0) {
			cout << 2 * supposed - 1 << endl;
			continue;
		}
		supposed++;
		ll a = supposed - 1, b = supposed;
		if (h*(4 * supposed*supposed - 6 * supposed + 1) <= 2 * mid*(2 * supposed - 3)*(2 * supposed - 1)) {
			cout << 2 * a - 1 << endl;
			continue;
		}
		else {
			cout << 2 * b - 1 << endl;
			continue;
		}
	}
	return 0;
}