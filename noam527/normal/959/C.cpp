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
const ldb eps = 1e-7, pi = acos(-1);
using namespace std;

void correct(int n) {
	for (int i = 1; i < n; i++)
		cout << i << " " << i + 1 << endl;
}
void incorrect(int n) {
	if (n <= 5) {
		cout << -1 << endl;
		return;
	}
	cout << "1 2\n2 3\n2 4" << endl;
	for (int i = 5; i <= n; i++)
		cout << 1 << " " << i << endl;
}

int main() {
	fast;
	int n;
	cin >> n;
	incorrect(n);
	correct(n);
}