#include <map>
#include <iostream>
#include <cstring>
#include <vector>
#include <cctype> 
#include <cstdio>
#include <string>
#include <ctime>
#include <cmath>
#include <algorithm>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
//
long long n, x;
long long a[5];
//
int main() {
    //freopen("Input.txt", "r", stdin);
    //freopen("Output.txt", "w", stdout);
    //
	cin >> n;
	for (int i = 0; i < n; i++) {
		scanf("%d ", &x);
		a[x]++;
	}
	long long res = a[4];
	x = min(a[3], a[1]);
	res += x;
	a[3] -= x;
	a[1] -= x;
	if (a[3] > 0) res += a[3];
	x = a[2]/2;
	a[2] -= 2*x;
	res += x;
	if (a[1] + 2 * a[2] > 0)
		res += 1 + (a[1]+2*a[2] - 1) / 4;
	cout << res;
}