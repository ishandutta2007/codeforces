#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <string>
#include <time.h>
#define last(x, y) (x)[(x).size() - y]
#define endl '\n'
#define flush fflush(stdout), cout.flush()
#define fast ios::sync_with_stdio(0), cin.tie(0)
#define debug cout << "ok" << endl
#define in(X) ((X) - '0')
const int md = 1e9 + 7;
const long long hs = 149;
//const double pi = acos(-1);
typedef long long ll;
typedef long double ldb;
using namespace std;

string s, ans = "";

int main() {
	fast;
	cin >> s;
	int at = 0;
	while (at < s.size()) {
		if (s[at] == '.') ans.push_back('0'), at++;
		else if (s[at + 1] == '.') ans.push_back('1'), at += 2;
		else ans.push_back('2'), at += 2;
	}
	cout << ans << endl;
}