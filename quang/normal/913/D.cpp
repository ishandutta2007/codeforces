#include <bits/stdc++.h>

using namespace std;

const int N = 200010;
const int INF = (int)1e9 + 100;

int n, t;
int id[N];	

struct data {
	int a, b, id;
	data(int a = 0, int b = 0) : a(a), b(b) {};
} a[N];

bool cmp(data u, data v) {
	return u.b < v.b;
}

bool cmpPos(int u, int v) {
	return a[u].a > a[v].a;
}

struct IT {
	int num[N * 4], sum[N * 4];

	void init() {
		for (int i = 1; i <= n * 4; i++) {
			num[i] = sum[i] = 0;
		}
	}

	void add(int node, int l, int r, int id, int val) {
		if (id > r || id < l) {
			return;
		}
		if (l == r) {
			num[node] = 1;
			sum[node] = val;
			return;
		}
		int m = (l + r) >> 1;
		add(node << 1, l, m, id, val);
		add(node << 1 | 1, m + 1, r, id, val);
		num[node] = num[node << 1] + num[node << 1 | 1];
		sum[node] = sum[node << 1] + sum[node << 1 | 1];
	}

	int get(int node, int l, int r, int cnt) {
		if (cnt == 0) {
			return 0;
		}
		if (cnt > num[node]) {
			return INF;
		}
		if (cnt == num[node]) {
			return sum[node];
		}
		int m = (l + r) >> 1;
		if (cnt > num[node << 1]) {
			return sum[node << 1] + get(node << 1 | 1, m + 1, r, cnt - num[node << 1]);
		}
		return get(node << 1, l, m, cnt);
	}

	void go(int node, int l, int r, int &cnt) {
		if (cnt == 0) {
			return;
		}
		if (num[node] == 0) {
			return;
		}
		if (l == r) {
			printf("%d ", a[l].id);
			cnt--;
			return;
		}
		int m = (l + r) >> 1;
		go(node << 1, l, m, cnt);
		go(node << 1 | 1, m + 1, r, cnt);
	}

	void trace(int cnt) {
		go(1, 1, n, cnt);
	}
} tr;

int main() {
	scanf("%d %d", &n, &t);
	for (int i = 1; i <= n; i++) {
		scanf("%d %d", &a[i].a, &a[i].b);
		a[i].id = i;
		id[i] = i;
	}
	sort(a + 1, a + n + 1, cmp);
	sort(id + 1, id + n + 1, cmpPos);
	tr.init();
	int cur = 1;
	int res = 0;
	for (int i = n; i; i--) {
		while (cur <= n && a[id[cur]].a == i) {
			tr.add(1, 1, n, id[cur], a[id[cur]].b);
			cur++;
		}
		int foo = tr.get(1, 1, n, i);
		if (foo <= t) {
			printf("%d\n", i);
			printf("%d\n", i);
			tr.trace(i);
			return 0;
		}
	}
	cout << 0 << endl << 0;
	return 0;
}