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
const long long hs = 137;
//const double pi = acos(-1);
typedef long long ll;
typedef long double ldb;
using namespace std;

string s;
vector<int> a;

bool iscon(char &c) {
	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return false;
	return true;
}

int main() {
	fast;
	cin >> s;
	if (s.size() < 3){
	    cout << s << endl;
	    return 0;
	}
	a.resize(s.size(), 0);
	for (int i = 0; i < s.size() - 2; i++) {
		if (iscon(s[i]) && iscon(s[i + 1]) && iscon(s[i + 2]) && (s[i] != s[i + 1] || s[i] != s[i + 2] || s[i + 1] != s[i + 2])) a[i] = 1;
	}
	int at = 0;
	while (at < s.size()) {
		if (a[at]) cout << s[at] << s[at + 1] << " ", at += 2;
		else cout << s[at], at++;
	}
}