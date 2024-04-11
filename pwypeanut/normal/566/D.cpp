#include <bits/stdc++.h>
//#include "restructuring.h"
using namespace std;

int p[300005];
set<int> S;

int fp(int x) {
	if (p[x] == x) return x;
	else return p[x] = fp(p[x]);
}

void init(int N) {
	for (int i = 0; i < N; i++) p[i] = i;
	for (int i = 0; i < N; i++) S.insert(i);
}

void merge_two(int x, int y) {
	x = fp(x);
	y = fp(y);
	p[x] = y;
}

void merge_all(int x, int y) {
	set<int>::iterator it_l = S.lower_bound(x);
	set<int>::iterator it_r = S.upper_bound(y);
	for (set<int>::iterator it = it_l; it != it_r; it++) {
		if (it != it_l) {
			set<int>::iterator it2 = (--it);
			it++;
			merge_two(*it, *it2);
		}
	}
	int l = *it_l, r = *(--it_r);
	it_r++;
	for (set<int>::iterator it = it_l; it != it_r;) {
		set<int>::iterator it2 = it;
		it++;
		S.erase(it2);
	}
	S.insert(l);
	S.insert(r);
}

bool is_same_department(int x, int y) {
	return fp(x) == fp(y);
}






int N, Q;

int main() {
	scanf("%d%d", &N, &Q);
	init(N);
	while (Q--) {
		int op, a, b;
		scanf("%d%d%d", &op, &a, &b);
		op--;
		a--;
		b--;
		if (op == 0) merge_two(a, b);
		else if (op == 1) merge_all(a, b);
		else {
			if (is_same_department(a, b)) printf("YES\n");
			else printf("NO\n");
		}
	}
}