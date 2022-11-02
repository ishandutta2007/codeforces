#define _CRT_SECURE_NO_WARNINGS
#define fast ios::sync_with_stdio(false); cin.tie(0);
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define ff first
#define ss second

#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
#include <stack>
#include <set>
#include <string>
#include <queue>
#include <time.h>
#include <chrono>
#include <random>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef pair<ld, ld> pld;

ll ask(string& st) {
	cout << st << endl;
	fflush(stdout);
	ll ans;
	cin >> ans;
	if (ans)return ans;
	else exit(0);
}

const int L = 300;

int main() {
	fast;
	string a1 = "", b1 = "";
	foru(i, 0, L)a1.push_back('a'), b1.push_back('b');
	ll k1 = ask(a1), k2 = ask(b1);
	int n = 2 * L - k1 - k2, b = k1 - L + n, a = n - b;
	string tgt = "";
	foru(i, 0, n)tgt.push_back('a');
	int crb = b;
	ford(i, n - 1, 1) {
		tgt[i] = 'b';
		int ns = ask(tgt);
		if (ns == crb - 1)crb--;
		else tgt[i] = 'a';
	}
	int cnt = 0;
	for (char c : tgt)cnt += (c == 'b');
	if (cnt != b)tgt[0] = 'b';
	ask(tgt);
	return 0;
}