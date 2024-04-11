#include <bits/stdc++.h>
using namespace std;

int N, A[100005];

struct node {
	node *left = NULL, *right = NULL;
	int p;
	node(int _p) : p(_p) {}
	void insert(int x) {
		if (p == -1) return;
		if (!(x & (1 << p))) {
			if (left == NULL) left = new node(p - 1);
			left->insert(x);
		} else {
			if (right == NULL) right = new node(p - 1);
			right->insert(x);
		}
	}
	int dp() {
		if (left == NULL && right == NULL) return 0;
		if (left == NULL ^ right == NULL) {
			if (left != NULL) return left->dp();
			else return right->dp();
		}
		int x = min(left->dp(), right->dp());
		return x | (1 << p);
	}
} *root = new node(31);

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
		root->insert(A[i]);
	}
	cout << root->dp() << '\n';
}