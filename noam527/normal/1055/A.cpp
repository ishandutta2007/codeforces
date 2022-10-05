#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
#define endl '\n'
#define fast ios::sync_with_stdio(0), cin.tie(0)
#define debug cout << "ok" << endl
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7, inf = 1e9 + 7;
const ll hs = 199;
const ldb eps = 1e-9, pi = acos(-1);
using namespace std;

int n, s;
vector<int> a, b;

int main() {
	fast;
	cin >> n >> s;
	--s;
	a.resize(n);
	b.resize(n);
	for (auto &i : a) cin >> i;
	for (auto &i : b) cin >> i;
	if (a[0] == 0) finish("NO");
	if (a[s] == 1) finish("YES");
	if (b[s] == 0) finish("NO");
	for (int i = s; i < n; i++)
		if (a[i] == 1 && b[i] == 1) finish("YES");
	finish("NO");
}