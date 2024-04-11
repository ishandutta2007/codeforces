#include <bits/stdc++.h>
 
using namespace std;

#define err(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
typedef long long ll;

const int dd = (int)1e6 + 7;

int A[dd];

struct Node {
	int c;
	Node *l, *r;

	Node() { c = 0, l = r = NULL; }
};
Node* R = new Node();

int get_c(Node* R) {
	return R == NULL ? 0 : R->c;
}

int get(int X, int t, Node* R) {
	R->c--;
	if (t == -1) return 0;
	if ((X >> t) & 1) {
		if (get_c(R->r))
			return get(X, t - 1, R->r);
		return (1 << t) + get(X, t - 1, R->l);
	} else {
		if (get_c(R->l))
			return get(X, t - 1, R->l);
		return (1 << t) + get(X, t - 1, R->r);
	}
}

void push(int X, int t, Node* R) {
	R->c++;
	if (t == -1) return;
	if ((X >> t) & 1) {
		if (R->r == NULL)
			R->r = new Node();
		push(X, t - 1, R->r);
	} else {
		if (R->l == NULL)
			R->l = new Node();
		push(X, t - 1, R->l);
	}
}

int main() {
	int n, X;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &A[i]);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &X);
		push(X, 29, R);
	}

	for (int i = 0; i < n; ++i)
		printf("%d ", get(A[i], 29, R));
    return 0;
}