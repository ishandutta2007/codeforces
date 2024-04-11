#include <bits/stdc++.h>
using namespace std;

const int S = 320;
const int N = 100000;

int n, m;
int a[N];
int cnt[N + 2];

struct Query {
	int l, r;
	int idx;
	
	bool operator < (const Query &other) const {
		if (l / S != other.l / S) return l < other.l;
		return r < other.r;
	}
} query[N];

int ans[N];

int cur;
void add (int x) {
	if (a[x] > n) return;
	if (cnt[a[x]] == a[x]) cur--;
	cnt[a[x]]++;
	if (cnt[a[x]] == a[x]) cur++;
}

void remove (int x) {
	if (a[x] > n) return;
	if (cnt[a[x]] == a[x]) cur--;
	cnt[a[x]]--;
	if (cnt[a[x]] == a[x]) cur++;
}

int main () {
	
	scanf ("%d %d", &n, &m);
	for (int i=0; i<n; i++) scanf ("%d", a + i);
	
	for (int i=0; i<m; i++) {
		scanf ("%d %d", &query[i].l, &query[i].r);
		query[i].l--; query[i].r--;
		query[i].idx = i;
	}
	
	sort (query, query + m);
	int l = 0; int r = -1;
	for (int i=0; i<m; i++) {
		while (l < query[i].l) remove(l++);
		while (l > query[i].l) add(--l);
		while (r < query[i].r) add(++r);
		while (r > query[i].r) remove(r--);
		
		ans[query[i].idx] = cur;
	}
	
	for (int i=0; i<m; i++) printf ("%d\n", ans[i]);
	
	return 0;
}