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
#include <queue>
#define ni(x) scanf("%d", &(x))
#define mp make_pair

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

priority_queue<int> pq;
set<int> st;

int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ll ans = 0;
	int n; ni(n);
	for (int i = 0; i < n; i++) {
		int x;
		ni(x);
		pq.push(x);
	}
	while (!pq.empty()) {
		int t = pq.top(); pq.pop();
		while (t > 0) {
			if (st.find(t) != st.end()) {
				t--;
				continue;
			}
			else {
				ans = ans + t;
				st.insert(t);
				break;
			}
		}
	}
	printf("%I64d", ans);
	return 0;
}