#define fast ios::sync_with_stdio(false); cin.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back
#define mp make_pair

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <list>
#include <bitset>
#include <stack>
#include <set>
#include <queue>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int sz = 1e6 + 5;
ll  n;


int main() {
	fast;
	string a, b;
	cin >> n >> a >> b;
	ll o = 0, z = 0, ob = 0, zb = 0;
	foru(i, 0, n) {
		if (a[i] == '1') {
			o++;
			if (b[i] == '1')ob++;
		}
		if (a[i] == '0') {
			z++;
			if (b[i] == '1')zb++;
		}
	}
	cout << z * o - ob * zb << endl;
	return 0;
}