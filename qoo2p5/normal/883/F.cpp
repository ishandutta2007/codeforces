#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <memory.h>
#include <iomanip>

using namespace std;

typedef long long ll;

const int INF = (int) 1e9 + 123;
const ll LINF = (ll) 1e18 + 123;

#define rep(i, s, t) for (auto i = (s); i < (t); ++(i))
#define sz(x) ((int) x.size())
#define all(x) (x).begin(), (x).end()

void run();

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
#endif
	run();
#ifdef _DEBUG
	cerr << "OK" << endl;
	while (1);
#endif
	return 0;
}

const int N = 405;

int n;
vector<string> a;

string f(string s) {
	while (s.find("kh") != string::npos) {
		int k = s.find("kh");
		s = s.substr(0, k) + "h" + s.substr(k + 2, sz(s) - k - 2);
	}
	while (s.find("u") != string::npos) {
		int k = s.find("u");
		s = s.substr(0, k) + "oo" + s.substr(k + 1, sz(s) - k - 1);
	}
	return s;
}

void run() {
	cin >> n;
	rep(i, 0, n) {
		string s;
		cin >> s;
		a.push_back(f(s));
	}
	sort(all(a));
	a.resize(unique(all(a)) - a.begin());
	cout << sz(a) << "\n";
}