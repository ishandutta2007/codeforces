#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <string>
#include <time.h>
#define last(x, y) (x)[(x).size() - y]
#define endl '\n'
#define flush fflush(stdout), cout.flush()
#define fast ios::sync_with_stdio(0), cin.tie(0)
#define debug cout << "ok" << endl
#define in(X) ((X) - '0')
const int md = 1e9 + 7;
//const double pi = acos(-1);
typedef long long ll;
typedef long double ldb;
using namespace std;

int fac(int n) {return n == 0 ? 1 : n * fac(n - 1);}

int nck(int n, int k) {
	return fac(n) / fac(k) / fac(n - k);
}

int main() {
	fast;
	cout.precision(12);
	string s1, s2;
	int cnt = 0, l1 = 0, l2 = 0;
	cin >> s1 >> s2;
	for (auto i : s1)
		if (i == '+')
			l1++;
		else
			l1--;
	for (auto i : s2)
		if (i == '+')
			l2++;
		else if (i == '-')
			l2--;
		else
			cnt++;
	int d = abs(l1 - l2);
	if (d > cnt || ((cnt & 1) != (d & 1))) cout << 0 << endl;
	else cout << (double)nck(cnt, (d + cnt) / 2) / pow(2, cnt) << endl;
}