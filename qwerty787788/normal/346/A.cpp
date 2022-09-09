#include<stdio.h>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<memory.h>
#include<set>
#include<map>
#include<queue>
#include<cstring>
#include<sstream>
#define SS stringstream
#define pw(x) (1ll << (x))
#define m0(x) memset(x, 0, sizeof(x))
#define F first
#define S second
#define pb push_back
#define mp make_pair

using namespace std;

int n, a[111];

int main() {
//	freopen("1.in", "r", stdin);
//	freopen("1.out", "w", stdout);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	int g = 0;
	for (int i = 0; i < n; i++) g = __gcd(g, a[i]);
	int ma = 0;
	for (int i = 0; i < n; i++) ma = max(ma, a[i]);

	int all = ma / g;
	int rest = all - n;
	if (rest % 2) puts("Alice"); else puts("Bob");
	return 0;
}