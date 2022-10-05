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
#include <fstream>
#include <random>
#define endl '\n'
#define flush fflush(stdout), cout.flush()
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define debug cout << "ok" << endl
#define in(X) ((X) - '0')
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll hs = 199;
const ldb eps = 1e-9, pi = acos(-1);
using namespace std;

int n, a[100001], b[200002], c[200002];
int at = -1, p, p2;
int s1;

int main() {
	fast;
	cin >> n;
	for (int i = 0; i < n + 1; i++) cin >> a[i];
	for (int i = 0; i < n; i++) {
		if (a[i] > 1 && a[i + 1] > 1) at = i;
	}
	if (at == -1) finish("perfect");

	p = 1, p2 = 1;
	c[0] = 0;
	for (int i = 1; i < n + 1; i++) {
		if (i - 1 == at) s1 = p;
		for (int j = 0; j < a[i]; j++, p2++)
			c[p2] = p;
		p = p2;
	}
	for (int i = 0; i < p2; i++) b[i] = c[i];
	b[s1]--;
	
	cout << "ambiguous" << endl;
	for (int i = 0; i < p2; i++) cout << b[i] << " "; cout << endl;
	for (int i = 0; i < p2; i++) cout << c[i] << " "; cout << endl;
}