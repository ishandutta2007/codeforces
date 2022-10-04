#pragma warning(disable:4996)

#include <stdio.h>
#include <vector>
#include <set>
#include <algorithm>
#include <assert.h>
#include <string.h>
#include <string>
#include <iostream>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int x;
	string tmp;
	string tmp2;
	cin >> x >> tmp >> tmp2;
	if (tmp2 == "week") {
		if (x == 7 || x < 5) puts("52");
		else puts("53");
		return 0;
	}
	else {
		if (x <= 29) puts("12");
		else if (x == 30)puts("11");
		else puts("7");
		return 0;
	}
	

	return 0;
}