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
typedef long long ll;
typedef long double ldb;
using namespace std;

int k;

int main() {
	fast;
	cin >> k;
	if (k == 0) return cout << 'a' << endl, 0;
	string ans = "";

	int i;
	char j = 'a';
	while (k > 0) {
		i = 0;
		while (k >= i) k -= i, i++, ans.push_back(j);
		j++;
	}
	cout << ans << endl;
}