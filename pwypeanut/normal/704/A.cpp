#include <bits/stdc++.h>
using namespace std;

int N, Q, cur, ans, prev1;
bool read[300005];
vector<int> notifs[300005];
deque<int> D;

int main() {
	scanf("%d%d", &N, &Q);
	while (Q--) {
		int t;
		scanf("%d", &t);
		if (t == 1) {
			int x;
			scanf("%d", &x);
			notifs[x].push_back(cur);
			D.push_back(cur);
			cur++;
			ans++;
		} else if (t == 2) {
			int x;
			scanf("%d", &x);
			for (int i = 0; i < notifs[x].size(); i++) {
				if (!read[notifs[x][i]]) {
					read[notifs[x][i]] = 1;
					ans--;
				}
			}
			notifs[x].clear();
		} else {
			int x;
			scanf("%d", &x);
			for (int i = prev1; i < x; i++) {
				if (!read[D[i]]) {
					read[D[i]] = 1;
					ans--;
				}
				//D.pop_front();
			}
			prev1 = max(prev1, x);
		}
		printf("%d\n", ans);
	}
}