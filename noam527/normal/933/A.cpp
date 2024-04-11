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
const int md = 1e9 + 7, inf = 1e9 + 7;
const ll hs = 199;
const ldb eps = 1e-9, pi = acos(-1);
using namespace std;

int n, a[2000], pre[2000], suf[2000], cpre[2000], csuf[2000];

int main() { 
	fast;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i], --a[i], cpre[i] = (1 ^ a[i]), csuf[i] = a[i];
	for (int i = 1; i < n; i++) cpre[i] += cpre[i - 1];
	for (int i = n - 2; i >= 0; i--) csuf[i] += csuf[i + 1];

	pre[0] = 1;
	for (int i = 1; i < n; i++) {
		if (a[i]) pre[i] = pre[i - 1] + 1;
		else pre[i] = max(cpre[i], pre[i - 1]);
	}
	suf[n - 1] = 1;
	for (int i = n - 2; i >= 0; i--) {
		if (!a[i]) suf[i] = suf[i + 1] + 1;
		else suf[i] = max(csuf[i], suf[i + 1]);
	}

	int mx = max(suf[0], pre[n - 1]);
	for (int i = 1; i < n; i++)
		mx = max(mx, pre[i - 1] + suf[i]);
	cout << mx << endl;
}