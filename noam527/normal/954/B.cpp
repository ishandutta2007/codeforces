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

int n, c = 0;
string s;

int main() {
	fast;
	cin >> n >> s;
	for (int x = n / 2; x > 0; x--) {
		int cnt = 0;
		for (int i = 0; i < x; i++)
			if (s[i] != s[i + x]) cnt++;
		if (!cnt) finish(n - x + 1);
	}
	finish(n);
}