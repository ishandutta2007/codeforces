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

int main() {
	fast;
	int n;
	cin >> n;
	int p1 = 1, p2 = n*n;
	for (int i = 0; i < n*n; i += 2) {
		cout << p1++ << " " << p2-- << " ";
		if ((i + 2) % n == 0) cout << endl;
	}
}