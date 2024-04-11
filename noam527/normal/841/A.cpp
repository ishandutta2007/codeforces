#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#define last(x, y) (x)[(x).size() - y]
#define endl '\n'
#define flush fflush(stdout), cout.flush()
#define fast ios::sync_with_stdio(0), cin.tie(0)
#define debug cout << "ok" << endl
#define in(X) ((X) - '0')
const int md = 1e9 + 7;
typedef long long ll;
typedef long double ldb;
using namespace std;

int n, k;
string s;
vector<int> a(26, 0);

int main() {
	fast;
	cin >> n >> k >> s;
	for (auto i : s) a[i - 'a']++;
	int mx = -1;
	for (auto i : a) mx = max(mx, i);
	if (mx > k) {
		cout << "NO" << endl;
	}
	else cout << "YES" << endl;
}