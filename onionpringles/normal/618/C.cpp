#pragma warning(disable:4996)

#include <stdio.h>
#include <vector>
#include <algorithm>
#define mp make_pair

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int line(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3) {
	ll det = x2*y3 - x3*y2;
	det += (x3*y1 - x1*y3);
	det += (x1*y2 - x2*y1);
	return det == 0;
}

pair<pii, int> co[100000];

int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		co[i] = mp(mp(x, y), i + 1);
	}
	sort(co, co + n);
	for (int i = 0; i + 2 < n; i++) {
		if (line(co[i].first.first, co[i].first.second, co[i + 1].first.first, co[i + 1].first.second, co[i + 2].first.first, co[i + 2].first.second)) continue;
		printf("%d %d %d", co[i].second, co[i + 1].second, co[i + 2].second);
		break;
	}
	
	return 0;
}