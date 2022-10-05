#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <string>
#include <time.h>
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

string s;
vector<string> temp = {"Danil", "Olya", "Slava", "Ann", "Nikita"};

int check(int i) {
	int rtn = 0;
	for (int x = 0; x + temp[i].size() <= s.size(); x++)
		if (s.substr(x, temp[i].size()) == temp[i])
			rtn++;
	return rtn;
}

int main() {
	fast;
	cin >> s;
	bool found = false;
	for (int i = 0, t; i < 5; i++) {
		t = check(i);
		if (t) {
			if (found || t > 1) finish("NO");
			found = true;
		}
	}
	if (found) finish("YES");
	finish("NO");
}