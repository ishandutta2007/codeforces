#define fast ios::sync_with_stdio(false); cin.tie(0);
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back
#define ff first
#define ss second

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <numeric>
#include <set>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;


int main() {
	fast;
	vector<int> v(3);
	int d;
	foru(i, 0, 3)cin >> v[i];
	cin >> d;
	sort(v.begin(), v.end());
	ll cnt = 0;
	if (v[1] - v[0] < d)cnt += (d - (v[1] - v[0]));
	if (v[2] - v[1] < d)cnt += (d - (v[2] - v[1]));
	cout << cnt;
	return 0;
}