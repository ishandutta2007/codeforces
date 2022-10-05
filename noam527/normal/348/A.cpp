#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <string>
#include <time.h>
#include <stack>
#include <queue>
#include <random>
#include <fstream>
#define endl '\n'
#define flush fflush(stdout), cout.flush()
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define debug cout << "ok" << endl
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7, inf = 1e9 + 7;
const ll hs = 199;
const ldb eps = 1e-9, pi = acos(-1);
using namespace std;

int n;
vector<int> a;
ll s = 0, m;

int main() {
	fast;
	cin >> n;
	a.resize(n);
	for (auto &i : a) cin >> i;
	m = *max_element(a.begin(), a.end());
	for (const auto &i : a) s += m - i;
	cout << m + max(0LL, (m - s + n - 2) / (n - 1)) << endl;
}