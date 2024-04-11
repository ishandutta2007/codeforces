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

int n, p[3000], c = 0;

int main() {
	fast;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> p[i];
	for (int i = 0; i < n; i++) for (int j = i + 1; j < n; j++) if (p[i] > p[j]) c++;
	cout << c / 2 * 4 + (c & 1) << endl;
}