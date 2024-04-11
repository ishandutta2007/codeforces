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

bool isprime(int x) {
	for (int i = 2; i * i <= x; i++)
		if (x % i == 0) return false;
	return true;
}

int n;
vector<int> a;

int main() {
	fast;
	cin >> n;
	for (int i = 2; i <= n; i++) {
		if (isprime(i)) {
			for (int x = i; x <= n; x *= i)
				a.push_back(x);
		}
	}
	cout << a.size() << endl;
	for (const auto &i : a) cout << i << " "; cout << endl;
}