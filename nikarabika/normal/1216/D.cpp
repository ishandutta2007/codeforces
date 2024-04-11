//sobskdrbhvk
//remember...
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef long double LD;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define smin(x, y) (x) = min((x), (y))
#define smax(x, y) (x) = max((x), (y))
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	int a[n];
	int z = 0;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int mxid = max_element(a, a + n) - a;
	for (int i = 0; i < n; i++)
		z = __gcd(a[mxid] - a[i], z);
	LL y = 0;
	for (int i = 0; i < n; i++)
		y += (a[mxid] - a[i]) / z;
	cout << y << ' ' << z << endl;
	return 0;
}