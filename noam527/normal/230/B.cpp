#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <string>
#include <time.h>
#define last(x, y) (x)[(x).size() - y]
#define endl '\n'
#define flush fflush(stdout), cout.flush()
#define fast ios::sync_with_stdio(0), cin.tie(0)
#define debug cout << "ok" << endl
#define in(X) ((X) - '0')
const int md = 1e9 + 7;
//const double pi = acos(-1);
typedef long long ll;
typedef long double ldb;
using namespace std;

vector<bool> b(1e6 + 4, true);

void sieve() {
	b[1] = false;
	int i = 2;
	for (; i*i < b.size(); i++)
		if (b[i])
			for (int j = i*i; j < b.size(); j += i) b[j] = false;
}

int main() {
	fast;
	sieve();
	ll n, v, s;
	cin >> n;
	while (n--) {
		cin >> v;
		s = floor(sqrt(v));
		if (s*s != v || !b[s]) cout << "NO" << endl;
		else cout << "YES" << endl;
	}
}