#include <bits/stdc++.h>
#define CHECK cout << "ok" << endl
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 1e18;
const int OO = 1;
const int OOO = 1;
using namespace std;

int n, c = 0;
string s;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> s;
	n = s.size();
	for (auto &i : s)
		if (i == 'a') c++;
	finish(min(n, 2 * c - 1));
}