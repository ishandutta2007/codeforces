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

int main() {
	fast;
	int n, cnt0 = 0, cnt1 = 0;
	string s;
	cin >> n >> s;
	for (auto i : s)
		if (i == '0')
			cnt0++;
		else
			cnt1++;
	cout << n - 2 * min(cnt0, cnt1) << endl;
}