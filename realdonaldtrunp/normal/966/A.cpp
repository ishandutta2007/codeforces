#include "bits/stdc++.h"
using namespace std;


int n;
int m;
int cl;
int ce;
int v;
vector<int> st;
vector<int> el;
int main() {
	cin >> n >> m >> cl >> ce >> v;
	for (int i = 0; i < cl; i++) {
		int a;
		scanf("%d", &a);
		st.push_back(a);
	}
	for (int i = 0; i < ce; i++) {
		int a;
		scanf("%d", &a);
		el.push_back(a);
	}
	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		int x1, y1, x2, y2;
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		pair<int, int> p1 = make_pair(x1, y1);
		pair<int, int> p2 = make_pair(x2, y2);
		if (p1 > p2)swap(p1, p2);
		if (p1.first == p2.first) {
			printf("%d\n", p2.second - p1.second);
			continue;
		}
		int ans = INT_MAX;
		{
			int id = lower_bound(st.begin(), st.end(), p1.second)-st.begin();
			for (int j = 0; j < 2; j++) {
				if (id >= 0 && id < st.size()) {
					int x = st[id];
					ans = min(ans, abs(p1.first - p2.first)+abs(x-y1)+abs(x-y2) );
				}
				id--;
			}
		}
		{
			int id = lower_bound(el.begin(), el.end(), p1.second) - el.begin();
			for (int j = 0; j < 2; j++) {
				if (id >= 0 && id < el.size()) {
					int x = el[id];
					ans = min(ans, (abs(p1.first - p2.first)+v-1)/v + abs(x - y1) + abs(x - y2));
				}
				id--;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}