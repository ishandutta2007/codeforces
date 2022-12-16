
//IO
#include <iostream>
#include <cstdio>
#include <iomanip>

//General
#include <cmath>
#include <cstdlib>
#include <cstring>

//STL
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

const long long INF = 1E9;

struct node {
	long long val;
	node *l;
	node *r;
};

node * newNode () {
	node *n = new node;
	n -> val = 0;
	n -> l = n -> r = 0;
	return n;
}

void addNode (node *r, long long val, long long d, long long depth = 0) {
	r -> val += d;
	if (depth > 20) {
		return;
	}
	if (val % 2 == 0) {
		if (r -> l == 0) r -> l = newNode ();
		addNode (r -> l, val / 10, d, depth + 1);
	} else {
		if (r -> r == 0) r -> r = newNode ();
		addNode (r -> r, val / 10, d, depth + 1);
	}
}

long long queryNode (node *r, char *val, long long s, long long depth = 0) {
	if (depth > 20) return r -> val;
	if (s < 0 || val[s] == '0') {
		if (r -> l == 0) return 0;
		return queryNode (r -> l, val, s - 1, depth + 1);
	}
	if (r -> r == 0) return 0;
	return queryNode (r -> r, val, s - 1, depth + 1);
}

long long N;
char str[100];

int main () {
	ios::sync_with_stdio (false);
	cin.tie (0);
	cout.tie (0);
	cin >> N;
	node *root = newNode ();
	for (long long i = 0; i < N; i++) {
		char c;
		long long t;
		cin >> c;
		if (c == '+') {
			cin >> t;
			addNode (root, t, 1);
		}
		if (c == '-') {
			cin >> t;
			addNode (root, t, -1);
		}
		if (c == '?') {
			cin >> str;
			cout << queryNode (root, str, strlen (str) - 1) << endl;
		}
	}
	return 0;
}