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
#define last(x, y) (x)[(x).size() - (y)]
#define endl '\n'
#define flush fflush(stdout), cout.flush()
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define debug cout << "ok" << endl
#define in(X) ((X) - '0')
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll hs = 199;
//const ldb eps = 1e-9, pi = acos(-1);
using namespace std;

int ans = 0;
string s;

int main() {
	cin >> s;
	for (int i = 0; i < s.size(); i++)
		for (int j = i + 1; j < s.size(); j++)
			for (int k = j + 1; k < s.size(); k++)
				if (s[i] == 'Q' && s[j] == 'A' && s[k] == 'Q')
					ans++;
	cout << ans << endl;
}