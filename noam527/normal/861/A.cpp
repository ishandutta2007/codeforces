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

ll n, k, p, m = 1;
int c2 = 0, c5 = 0;



int main() {
	fast;
	cin >> n >> k;
	p = n;
	while (p % 2 == 0) p /= 2, c2++;
	while (p % 5 == 0) p /= 5, c5++;
	for (; c2 < k; c2++) n *= 2LL;
	for (; c5 < k; c5++) n *= 5LL;
	cout << n << endl;
}