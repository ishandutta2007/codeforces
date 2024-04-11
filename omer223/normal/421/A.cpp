#define fast ios::sync_with_stdio(false); cin.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back
#define mp make_pair
#define F "BitLGM"
#define S "BitAryo"

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <list>


using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int sz = 5e5;
int aa[sz],bb[sz];
bool is[sz];
int main() {
	fast;
	ll n, a, b,t;
	cin >> n >> a >> b;
	foru(i, 0, a) {
		cin >> t;
		is[t] = 1;
	}
	foru(i, 0, b)cin >> t;
	foru(i, 0, n) {
		if (is[i + 1])cout << 1 << " ";
		else cout << 2 << " ";
	}
	return 0;
}