#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, int> pii;
typedef pair <int, pii> ppp;

int a[200010], id[200010], b[200010];
map <int, vector <int> > all;
map <int, vector <int> > pos;
vector <ppp> tmp;

bool cmp(int x, int y) {
	return a[x] < a[y];
}

int main() {
	int n; scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]), id[i] = i, pos[a[i]].push_back(i);
	for (auto x : pos) {
		if (x.se.size() >= 4) {
			printf("YES\n");
			for (int i = 0; i < 4; i++) {
				printf("%d ", x.se[i]);
			}
			printf("\n");
			return 0;
		}
	}
	sort(id + 1, id + n + 1, cmp);
	for (int i = 1; i <= n; i++) b[i] = a[id[i]];
	for (int i = 1; i <= n; i++) a[i] = b[i];
	for (int i = 1; i < n; i++) all[a[i + 1] - a[i]].push_back(i);
	a[0] = -0x3f3f3f3f, a[n + 1] = 0x3f3f3f3f;
	for (int i = 1; i < n; i++) {
		int len = a[i + 1] - a[i], cnt = (a[i] - a[i - 1] == len) + (a[i + 2] - a[i + 1] == len);
		const vector <int> &tmp = all[len];
		if (tmp.size() == cnt + 1) continue;
		printf("YES\n");
		for (auto x : tmp) {
			if (abs(x - i) > 1) {
				printf("%d %d %d %d\n", id[x], id[i + 1], id[i], id[x + 1]);
				break;
			}
		}
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			tmp.push_back(mp(a[j] - a[i], mp(i, j)));
		}
	}
	sort(tmp.begin(), tmp.end());
	for (int i = 0; i < tmp.size(); i++) {
		int j = i, X = -1, Y = -1;
		while (j < tmp.size() && tmp[i].fi == tmp[j].fi) j++;
		for (int a = i; a < min(i + 5, j); a++) {
			for (int b = a + 1; b < min(i + 5, j); b++) {
				if (tmp[a].se.fi != tmp[b].se.fi && tmp[a].se.fi != tmp[b].se.se
				 && tmp[a].se.se != tmp[b].se.fi && tmp[a].se.se != tmp[b].se.se) {
					printf("YES\n");
					printf("%d %d %d %d\n", id[tmp[b].se.fi], id[tmp[a].se.se], id[tmp[a].se.fi], id[tmp[b].se.se]);
					return 0;
				}
			}
		}
	}
	printf("NO\n");
	return 0;
}