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

void bad() {
	cout << ":(\n";
	exit(0);
}



int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> s;
	n = s.size();
	int lst = -1;
	for (int i = 0; i < n; i++)
		if (s[i] == 'a') lst = i, c++;
	if (lst == -1) {
		if (n & 1) bad();
		for (int i = 0; i < n / 2; i++)
			if (s[i] != s[i + n / 2]) bad();
		for (int i = 0; i < n / 2; i++) {
			cout << s[i];
		}
		return 0;
	}
	if ((n + c) & 1) bad();
	int l = (n + c) / 2;
	string A = "", B = "";
	for (int i = 0; i < l; i++)
		if (s[i] != 'a') A.push_back(s[i]);
	for (int i = l; i < n; i++)
		B.push_back(s[i]);
	if (A == B) {
		for (int i = 0; i < l; i++) cout << s[i];
		return 0;
	}
	bad();
}