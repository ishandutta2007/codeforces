#include <iostream>
#include <cstring>
#include <vector>
#include <cctype>
#include <cstdio>
#include <string>
#include <cmath>
#include <ctime>
#include <algorithm>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
//
long long n, m, a[12];
//
int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//
	cin >> n;
	for (int i = 0; i < 12; i++)
		cin >> a[i];
	sort(a, a+12);
	reverse(a, a+12);
	int su = 0;
	for (int i = 0; i < 12; i++)
		if (n > 0) {
			su++;
			n -= a[i];
		}
	if (n > 0) su = -1;
	cout << su << endl;
}