#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <complex>
#include <list>
#define mp make_pair
#define ni(x) scanf("%d", &(x))
#define nii(x,y) scanf("%d%d", &(x), &(y))
#define save(A, x) (A).push_back(mp(&x, x))
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MN = 500000;

class Node {
public:
	pii val;
	Node* next;
	Node(pii _val) { val = _val; next = NULL; };
};

class List {
public:
	Node* front;
	Node* back;
	List() { front = back = NULL; }
	void merge(const List& l) {
		if (!l.front) {
			return;
		}
		if(front){
			back->next = l.front;
			back = l.back;
		}
		else {
			front = l.front;
			back = l.back;
		}
	}
	void pop_front() {
		Node* tmp = front;
		if (front == back) {
			front = back = NULL;
			delete tmp;
			return;
		}
		front = front->next;
		delete tmp;
	}
	void insert(Node* nd) {
		if (!front) {
			front = back = nd;
		}
		else {
			back->next = nd;
			back = nd;
		}
	}
};

set<int> adj1[MN];
set<int> adj2[MN];

set<int> delq[MN];
set<int> insq[MN];
List inslist[MN];

vector<int> postord;
int par[MN];

int rnk[MN];
int ufpar[MN];

inline int find(int x) {
	while (ufpar[x] != -1) x = ufpar[x];
	return x;
}

void merge_uf(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y) return;
	if (rnk[x] < rnk[y]) {
		ufpar[x] = y;
		inslist[y].merge(inslist[x]);
	}
	else {
		ufpar[y] = x;
		inslist[x].merge(inslist[y]);
		if (rnk[x] == rnk[y]) rnk[x]++;
	}
	return;
}

void dfs(int i) {
	for (auto &x : adj1[i]) {
		if (x == par[i]) continue;
		par[x] = i;
		dfs(x);
	}
	int ii = find(i);
	for (auto &x : insq[i]) {
		inslist[ii].insert(new Node(mp(i, x)));
	}
	if (delq[i].find(par[i]) != delq[i].end()) {
		printf("%d %d ", i + 1, par[i] + 1);
		while (1) {
			auto v = inslist[ii].front->val;
			inslist[ii].pop_front();
			if (insq[v.first].find(v.second) == insq[v.first].end()) continue;
			printf("%d %d\n", v.first + 1, v.second + 1);
			insq[v.second].erase(v.first);
			insq[v.first].erase(v.second);

			merge_uf(ii, v.second);

			break;
		}
	}
	else {
		if (par[i] != -1) {
			merge_uf(ii, par[i]);
		}
	}
	return;
}



int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n; ni(n);
	for (int i = 0; i < n - 1; i++) {
		int u, v; nii(u, v);
		u--; v--;
		adj1[u].insert(v);
		adj1[v].insert(u);
	}
	for (int i = 0; i < n - 1; i++) {
		int u, v; nii(u, v);
		u--; v--;
		adj2[u].insert(v);
		adj2[v].insert(u);
	}
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (auto &x : adj1[i]) {
			if (adj2[i].find(x) == adj2[i].end()) {
				delq[i].insert(x); cnt++;
			}
		}
		for (auto &x : adj2[i]) {
			if (adj1[i].find(x) == adj1[i].end()) insq[i].insert(x);
		}
	}
	for (int i = 0; i < n; i++) ufpar[i] = -1;
	printf("%d\n", cnt / 2);
	par[0] = -1;
	dfs(0);
	return 0;
}