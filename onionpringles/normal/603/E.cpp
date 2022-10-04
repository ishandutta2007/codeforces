#pragma warning(disable:4996)

#include <stdio.h>
#include <vector>
#include <algorithm>
#define mp(a,b) make_pair(a,b)

using namespace std;

int oddcnt = 0;

struct Node {
	int key;
	int cnt;
	Node* par;
	Node(int k) {
		key = k;
		par = NULL;
		cnt = 1;
	}
};

struct History {
	int valid;
	Node* ndch;
	int cntpar;
	History() {}
} hist[700000];

int histpt = 0;

inline void pushvoid() {
	hist[histpt].valid = 0;
	histpt++;
}

inline Node* find(Node* x) {
	while (x->par) {
		x = x->par;
	}
	return x;
}

void merge(Node* x, Node* y) {
	x = find(x);
	y = find(y);
	if (x == y) {
		pushvoid();
		return;
	}
	if (x->cnt < y->cnt) swap(x, y);
	hist[histpt].valid = 1;
	hist[histpt].cntpar = x->cnt;
	hist[histpt].ndch = y;
	histpt++;
	y->par = x;
	if ((x->cnt) % 2 == 1 && (y->cnt) % 2 == 1) oddcnt -= 2;
	x->cnt += y->cnt;
	
}

void pophist() {
	histpt--;
	if (hist[histpt].valid) {
		Node* par = hist[histpt].ndch->par;
		par->cnt = hist[histpt].cntpar;
		hist[histpt].ndch->par = NULL;
		if ((par->cnt) % 2 == 1 && (hist[histpt].ndch->cnt) % 2 == 1) oddcnt += 2;
	}
}

struct Edge {
	int a;
	int b;
	int len;
	int time;
	Edge() {}
} len_sort[300001];

int time_sort[300001];

Node* vt[100001];

int res[300001];

int curlen = 0;
int curtime = 0;

void move_r() {
	curtime++;
	if (time_sort[curtime] <= curlen) {
		int a = len_sort[time_sort[curtime]].a;
		int b = len_sort[time_sort[curtime]].b;
		merge(vt[a], vt[b]);
	}
	else {
		pushvoid();
	}
}

void move_u() {
	curlen++;
	if (len_sort[curlen].time <= curtime) {
		int a = len_sort[curlen].a;
		int b = len_sort[curlen].b;
		merge(vt[a], vt[b]);
	}
	else {
		pushvoid();
	}
}
int m;
void solve(int l, int r) {
	int mid = (l + r) / 2;
	int svl = curlen;
	int svt = curtime;
	while (curtime < mid) move_r();
	while (1) {
		if (oddcnt == 0) break;
		if (curlen == m - 1) break;
		move_u();
	}
	int goodlen = curlen;
	if (oddcnt == 0) res[mid] = len_sort[curlen].len;
	else res[mid] = -1;
	while (curlen > svl) { pophist(); curlen--; }
	if (goodlen == svl && res[mid]!=-1) {
		for (int i = mid + 1; i <= r; i++) {
			res[i] = len_sort[goodlen].len;
		}
	}
	else if (mid < r) {
		move_r();
		solve(mid + 1, r);
		pophist();
		curtime--;
	}
	while (curtime > svt) { pophist(); curtime--; }
	if (res[mid] == -1) {
		for (int i = l; i < mid; i++) {
			res[i] = -1;
		}
		return;
	}
	if (l == mid) {
		return;
	}
	while (curlen < goodlen) move_u();
	solve(l, mid - 1);
	while (curlen > svl) { pophist(); curlen--; }
	return;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//setbuf(stdout, NULL);
	int n;
	scanf("%d %d", &n, &m);
	if (n % 2) {
		for (int i = 0; i < m; i++) puts("-1");
		return 0;
	}
	oddcnt = n;
	for (int i = 0; i < n; i++) {
		vt[i] = new Node(i);
	}
	for (int i = 0; i < m; i++) {
		int a, b, l;
		scanf("%d %d %d", &a, &b, &l);
		a--; b--;
		len_sort[i].a = a;
		len_sort[i].b = b;
		len_sort[i].len = l;
		len_sort[i].time = i;
	}
	sort(len_sort, len_sort + m, [&](const Edge& a, const Edge& b)->bool {return (a.len < b.len) || (a.len==b.len && a.time>b.time); });
	for (int i = 0; i < m; i++) {
		time_sort[len_sort[i].time] = i;
	}
	if (time_sort[0] == 0) {
		merge(vt[len_sort[0].a], vt[len_sort[0].b]);
	}
	solve(0, m - 1);
	for (int i = 0; i < m; i++) {
		printf("%d\n", res[i]);
	}
	return 0;
}