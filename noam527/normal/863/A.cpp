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

string s;

bool check() {
	for (int i = 0; 2 * i + 1 < s.size(); i++)
		if (s[i] != s[s.size() - i - 1]) return false;
	return true;
}

int main() {
	fast;
	cin >> s;
	for (int i = 0; i < (int)s.size() / 2; i++) swap(s[i], s[s.size() - i - 1]);
	for (int i = 0; i < 20; i++) {
		if (check()) return cout << "YES" << endl, 0;
		s.push_back('0');
	}
	cout << "NO" << endl;
}