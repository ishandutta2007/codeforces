#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
#define endl '\n'
#define debug cout << "ok" << endl
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7, inf = 1e9 + 7;
const ll hs = 199;
const ldb eps = 1e-9, pi = acos(-1);
using namespace std;

int a[2], b[2], c[2];

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int n;
	cin >> n;
	cin >> a[0] >> a[1] >> b[0] >> b[1] >> c[0] >> c[1];
	if ((b[0] > a[0] && c[0] < a[0]) || (b[1] > a[1] && c[1] < a[1]) || (b[0] < a[0] && c[0] > a[0]) || (b[1] < a[1] && c[1] > a[1])) finish("NO");
	finish("YES");
}