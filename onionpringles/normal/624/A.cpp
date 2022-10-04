#pragma warning(disable:4996)

#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <string.h>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#define ni(x) scanf("%d", &(x))
#define mp make_pair

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int d, l, v1, v2;
	scanf("%d %d %d %d", &d, &l, &v1, &v2);
	printf("%.15f", (double)(l - d) / (v1 + v2));


	return 0;
}