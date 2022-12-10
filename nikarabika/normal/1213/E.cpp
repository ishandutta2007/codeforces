//sobskdrbhvk
//remember...
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef long double LD;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define smin(x, y) (x) = min((x), (y))
#define smax(x, y) (x) = max((x), (y))
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()

void print0(int n, string p) {
	cout << "YES\n";
	for (int i = 0; i < n; i++)
		cout << p;
	cout << '\n';
	exit(0);
}

void print1(int n, string p) {
	cout << "YES\n";
	for (int i = 0; i < n * 3; i++)
		cout << p[i / n];
	cout << '\n';
	exit(0);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n;
	string s, t;
	cin >> n
		>> s
		>> t;
	string p;
	if (s[0] != s[1])
		swap(s, t);
	if (s[0] == s[1] or s == t) {
		if (t == "ab" or t == "bc" or t == "ca")
			print0(n, "cba");
		else
			print0(n, "abc");
	}
	else if (s[0] == t[1] and t[0] == s[1]) {
		p = "xxx";
		p[0] = s[0];
		p[2] = s[1];
		p[1] = s[0] ^ s[1] ^ 'a' ^ 'b' ^ 'c';
		print1(n, p);
	}
	else {
		if (s[0] == t[0]) {
			p = "xxx";
			p[0] = s[1];
			p[1] = t[1];
			p[2] = s[0];
			print1(n, p);
		}
		else if (s[1] == t[1]) {
			p = "xxx";
			p[0] = s[1];
			p[1] = s[0];
			p[2] = t[0];
			print1(n, p);
		}
		else {
			if (s[1] != t[0])
				swap(s, t);
			p = "xxx";
			p[0] = t[1];
			p[1] = t[0];
			p[2] = s[0];
			print0(n, p);
		}
	}
	return 0;
}