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

int n, d;
string s;

int check(int i) {
	for (int x = i + d; x > i; x--)
		if (s[x] == '1') return x;
	return -1;
}

int main() {
	fast;
	cin >> n >> d >> s;
	for (int i = 0; i < d + 5; i++) s.push_back('1');

	int at = 0, cnt = 0;
	while (at < n - 1) {
		at = check(at), cnt++;
		if (at == -1) finish(-1);
	}
	finish(cnt);
}