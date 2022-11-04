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

void run()
{
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int res = 0;
	res += (abs(a - c) + 1) * 2;
	res += (abs(b - d) + 1) * 2;
	if (a == c || b == d) res += 2;
	cout << res;
}