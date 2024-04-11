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
const int md = 1e9 + 7;
const ll hs = 199;
const ldb eps = 1e-9, pi = acos(-1);
using namespace std;

string s, t, ans = string(40, 'z');

string minf(string a, string b) {
  int p = 0;
  while (p < a.size() && p < b.size() && a[p] == b[p]) p++;
  if (p == a.size()) return a;
  if (p == b.size()) return b;
  if (a[p] < b[p]) return a;
  return b;
}

int main() {
	fast;
	cin >> s >> t;
	for (int i = 0; i < s.size(); i++) for (int j = 0; j < t.size(); j++)
		ans = minf(ans, s.substr(0, i + 1) + t.substr(0, j + 1));
	cout << ans;
}