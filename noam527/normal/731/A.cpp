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

int dist(char a, char b) {
	int ans = max(a, b) - min(a, b);
	ans = min(26 - ans, ans);
	return ans;
}

string s;
int ans = 0;

int main() {
	fast;
	cin >> s;
	s.insert(s.begin(), 'a');
	for (int i = 0; i < s.size() - 1; i++) ans += dist(s[i], s[i + 1]);
	finish(ans);
}