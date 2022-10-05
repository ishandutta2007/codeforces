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
#include <random>
#include <fstream>
#define endl '\n'
#define flush fflush(stdout), cout.flush()
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define debug cout << "ok" << endl
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll hs = 199;
const ldb eps = 1e-9, pi = acos(-1);
using namespace std;

string s;
vector<char> chk = { '1', '3', '5', '7', '9', 'a', 'e', 'i', 'o', 'u' };
int cnt = 0;

int main() {
	fast;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		for (int j = 0; j < chk.size(); j++)
			if (s[i] == chk[j]) cnt++;
	}
	cout << cnt << endl;
}