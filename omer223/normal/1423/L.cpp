#define _CRT_SECURE_NO_WARNINGS
#define fast ios::sync_with_stdio(false); cin.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back
#define mp make_pair

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <list>
#include <bitset>
#include <numeric>
#include <queue>
#include <map>
#include <intrin.h>
#include <unordered_map>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int sz = 1e3, precSize = 20, bsSize = 30;
int n, s, d;
bitset<sz> bs[bsSize], goal, onlineBS[(1<<(bsSize - precSize))];
unordered_map<bitset<sz>, int> bstime;
bitset<sz> idbs[(1 << precSize)];

void prec() {
	int mysz = min(precSize, s);
	bitset<sz> tmp;
	bstime[tmp] = 0;
	int crdigs = 0, ppcnt;
	for (int i = 1; i < (1 << mysz); i++) {
		ppcnt = __popcnt(i);
		if (ppcnt == 1)crdigs++;//CHANGE
		idbs[i] = idbs[i & ((1 << (crdigs - 1)) - 1)];
		idbs[i] ^= bs[crdigs - 1];
		if (bstime.find(idbs[i]) == bstime.end()) bstime[idbs[i]] = ppcnt;
		else bstime[idbs[i]] = min(bstime[idbs[i]], ppcnt);
	}
	int onlineBSSize = max(0, s - precSize);
	crdigs = 0;
	for (int i = 1; i < (1 << onlineBSSize); i++) {
		if (__popcnt(i) == 1)crdigs++;//CHANGE
		onlineBS[i] = onlineBS[i & ((1 << (crdigs - 1)) - 1)];
		onlineBS[i] ^= bs[precSize + crdigs - 1];
	}
}

void init() {
	scanf("%d %d %d", &n, &s, &d);
	int tmp, p;
	foru(i, 0, s) {
		scanf("%d", &tmp);
		foru(j, 0, tmp) {
			scanf("%d", &p);
			bs[i][--p] = 1;
		}
	}
	prec();
}

int calc() {
	if (s <= precSize) {
		if (bstime.find(goal) == bstime.end())return -1;
		else return bstime[goal];
	}
	ll crmn = 1e18, remain = s - precSize, tmp, ppcnt;
	bitset<sz> tmpbs;
	for (int i = 0; i < (1 << remain); i++) {
		ppcnt = __popcnt(i);
		tmpbs = goal ^ onlineBS[i];
		if (bstime.find(tmpbs) != bstime.end()) {
			tmp = bstime[tmpbs] + ppcnt;
			crmn = (tmp < crmn ? tmp : crmn);
		}
	}
	return (crmn < 1e10 ? crmn : -1);
}

int main() {
	init();
	int tmp, p;
	queue<int> q;
	goal.reset();
	while (d--) {
		scanf("%d", &tmp);
		foru(j, 0, tmp) {
			scanf("%d", &p); p--;
			goal[p] = 1;
			q.push(p);
		}
		printf("%d\n", calc());
		while (!q.empty()) {
			goal[q.front()] = 0;
			q.pop();
		}
	}
	return 0;
}