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
#include <random>

using namespace std;

typedef long long ll;
typedef long double ld;

#define TASK "lasers"

int solve();

int main() {
#ifdef Dron37_21
	freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
#else
	//freopen(TASK".in", "r", stdin), freopen(TASK".out", "w", stdout);
#endif
	return solve();
}

const int dd = (int)3e4 + 7;
const int inf = (int)1e9 + 7;

int F[26][26];

int solve() {
	string s, s1;
	cin >> s >> s1;
	for (int i = 0; i < (int)s.size(); ++i) {
	    F[s[i] - 'a'][s1[i] - 'a'] = 1;
	    F[s1[i] - 'a'][s[i] - 'a'] = 1;
	}
	int cnt = 0;
	for (int i = 0; i < 26; ++i) {
		int cur = 0;
		for (int j = 0; j < 26; ++j) if (F[i][j]) {
		    if (i != j) ++cnt;
		    ++cur;
		}
		if (cur - 1 && cur)
		    return 0 * puts("-1");
	}
	printf("%d\n", cnt / 2);
	for (int i = 0; i < 26; ++i)
	    for (int j = i + 1; j < 26; ++j) if (F[i][j])
	        printf("%c %c\n", i + 'a', j + 'a');
	return 0;
}