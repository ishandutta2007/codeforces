//sobskdrbhvk
//remember...
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef long double LD;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define smin(x, y) (x) = min((x), (y))
#define smax(x, y) (x) = max((x), (y))
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()

const int maxn = 1e5 + 10;
set<int> seg[maxn << 2];
int otim[3][2],
	ord[maxn],
	qord[maxn],
	ctim[maxn][3],
	qtim[maxn][3],
	ans[maxn],
	n, m, q;

bool ccmp(int i, int j) {
	return ctim[i][0] < ctim[j][0];
}

bool qcmp(int i, int j) {
	return qtim[i][0] < qtim[j][0];
}

void add(int idx, int val, int l = 0, int r = maxn, int id = 1) {
	if (idx < l or r <= idx)
		return;
	seg[id].insert(val);
	if (r - l == 1)
		return;
	int mid = (l + r) >> 1;
	add(idx, val, l, mid, id << 1 | 0);
	add(idx, val, mid, r, id << 1 | 1);
}

bool get(int st, int en, int s, int e, int l = 0, int r = maxn, int id = 1) {
	if (r <= st or en <= l)
		return false;
	if (st <= l and r <= en) {
		auto it = seg[id].lower_bound(s);
		return it != seg[id].end() and *it <= e;
	}
	int mid = (l + r) >> 1;
	return get(st, en, s, e, l, mid, id << 1 | 0)
		or get(st, en, s, e, mid, r, id << 1 | 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	for (int i = 0; i < 3; i++)
		cin >> otim[i][0];
	cin >> n >> m >> q;
	for (int i = 0; i < n; i++) {
		int tim[3];
		for (int j = 0; j < 3; j++) {
			cin >> tim[j];
			smin(otim[j][0], tim[j]);
			smax(otim[j][1], tim[j]);
		}
	}
	for (int i = 0; i < m; i++) {
		bool incor = true;
		for (int j = 0; j < 3; j++) {
			cin >> ctim[i][j];
			if (otim[j][0] > ctim[i][j] or ctim[i][j] > otim[j][1])
				incor = false;
		}
		if (incor)
			return cout << "INCORRECT\n", 0;
	}
	iota(ord, ord + m, 0);
	sort(ord, ord + m, ccmp);
	
	memset(ans, -1, sizeof ans);
	for (int i = 0; i < q; i++) {
		bool open = true;
		for (int j = 0; j < 3; j++) {
			cin >> qtim[i][j];
			if (qtim[i][j] < otim[j][0] or otim[j][1] < qtim[i][j])
				open = false;
			else
				smax(qtim[i][j], otim[j][1]);
		}
		if (open)
			ans[i] = 0;
	}
	iota(qord, qord + q, 0);
	sort(qord, qord + q, qcmp);

	int ptr = 0;
	for (int i = 0; i < q; i++) {
		int qid = qord[i];
		if (ans[qid] == 0 or qtim[qid][0] < otim[0][0])
			continue;
		while (ptr < m and ctim[ord[ptr]][0] <= qtim[qid][0]) {
			if (ctim[ord[ptr]][0] >= otim[0][0])
				add(ctim[ord[ptr]][1], ctim[ord[ptr]][2]);
			ptr++;
		}
		int sg[3][2];
		for (int ii = 1; ii < 3; ii++)
			for (int j = 0; j < 2; j++)
				sg[ii][j] = otim[ii][j];
		for (int j = 1; j < 3; j++) {
			if (qtim[qid][j] < otim[j][0])
				sg[j][0] = qtim[qid][j];
			else
				sg[j][1] = qtim[qid][j];
		}
		ans[qid] = 1 << get(sg[1][0], sg[1][1] + 1, sg[2][0], sg[2][1]);
	}

	for (int i = 0; i < maxn * 4; i++)
		if (sz(seg[i]))
			seg[i].clear();
	
	ptr = m - 1;
	for (int i = q - 1; i >= 0; i--) {
		int qid = qord[i];
		if (ans[qid] == 0 or qtim[qid][0] >= otim[0][1])
			continue;
		while (ptr >= 0 and ctim[ord[ptr]][0] >= qtim[qid][0]) {
			if (ctim[ord[ptr]][0] <= otim[0][1])
				add(ctim[ord[ptr]][1], ctim[ord[ptr]][2]);
			ptr--;
		}
		int sg[3][2];
		for (int ii = 1; ii < 3; ii++)
			for (int j = 0; j < 2; j++)
				sg[ii][j] = otim[ii][j];
		for (int j = 1; j < 3; j++) {
			if (qtim[qid][j] < otim[j][0])
				sg[j][0] = qtim[qid][j];
			else
				sg[j][1] = qtim[qid][j];
		}
		ans[qid] = 1 << get(sg[1][0], sg[1][1] + 1, sg[2][0], sg[2][1]);
	}

	cout << "CORRECT\n";
	for (int i = 0; i < q; i++)
		if (ans[i] == 0)
			cout << "OPEN\n";
		else if (ans[i] == 2)
			cout << "CLOSED\n";
		else
			cout << "UNKNOWN\n";

	return 0;
}