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
#include <numeric>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


int main() {
	fast;
	ll n, a, b, p, q, lab;
	cin >> n >> a >> b >> p >> q;
	lab = lcm(a, b);
	ll allA = n / a - n / lab, allB = n / b - n / lab, both = n / lab;
	if (p < q)cout << (allB + both)*q + allA * p << '\n';
	else cout << (allA + both)*p + allB * q << '\n';
	return 0;
}