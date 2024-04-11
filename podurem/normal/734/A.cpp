#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:256000000")
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <sstream>
#include <fstream>
#include <ctime>
#include <cstring>
#include <numeric>
#include <queue>
#include <cassert>
#include <unordered_map>
#include <unordered_set>

using namespace std;

typedef long long ll;
typedef long double ld;

#define TASK "light"
#define all(v) v.begin(), v.end()

int solve();

int main() {
#ifdef Dron37_21
	freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
#else
	//freopen(TASK".in", "r", stdin), freopen(TASK".out", "w", stdout);
#endif
	solve();
}

int solve() {
	int n;
	string s;
	cin >> n >> s;
	int iA = 0, iD = 0;
	for (auto i : s) {
		if (i == 'A') iA++;
		else iD++;
	}
	if (iA == iD) puts("Friendship");
	else if (iA > iD) puts("Anton");
	else puts("Danik");
	return 0;
}