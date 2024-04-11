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
	string s;
	int c = 0;
	cin >> s;
	for (auto i : s) if (i > 'Z') c++;
	if (2 * c >= s.size())
		for (auto i : s) cout << (char)(i % 32 + 96);
	else
		for (auto i : s) cout << (char)(i % 32 + 64);
}