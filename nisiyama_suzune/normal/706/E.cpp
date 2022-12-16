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

const int INF = 1E9;

struct Node {
	Node *right;
	Node *down;
	int v;
};

Node G[1100][1100];

Node *GetIndex (int x, int y) {
	Node *p = &G[0][0];
	for (int i = 0; i < x; i++) p = p -> down;
	for (int j = 0; j < y; j++) p = p -> right;
	return p;
}

int main () {
	ios::sync_with_stdio (false);
	cin.tie (0);
	cout.tie (0);
	int N, M, Q;
	cin >> N >> M >> Q;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			cin >> G[i][j].v;
	for (int i = 0; i <= N; i++)
		for (int j = 0; j <= M; j++) {
			if (i == N)
				G[i][j].down = 0;
			else
				G[i][j].down = &G[i + 1][j];
			if (j == M)
				G[i][j].right = 0;
			else
				G[i][j].right = &G[i][j + 1];
		}
	for (int i = 0; i < Q; i++) {
		int x1, y1, x2, y2, h, w;
		cin >> x1 >> y1 >> x2 >> y2 >> h >> w;
		Node *p = GetIndex (x1 - 1, y1 - 1), *q = GetIndex (x2 - 1, y2 - 1);
		Node *r = GetIndex (x1 + h - 1, y1), *s = GetIndex (x2 + h - 1, y2);
		Node *t = GetIndex (x1, y1 + w - 1), *u = GetIndex (x2, y2 + w - 1);
		Node *a = p -> right, *b = q -> right;
		Node *c = p -> down, *d = q -> down;
		for (int i = 0; i < w; i++) {
			swap (a -> down, b -> down);
			swap (r -> down, s -> down);
			a = a -> right;
			b = b -> right;
			r = r -> right;
			s = s -> right;
		}
		for (int i = 0; i < h; i++) {
			swap (c -> right, d -> right);
			swap (t -> right, u -> right);
			c = c -> down;
			d = d -> down;
			t = t -> down;
			u = u -> down;
		}
	}
	for (int i = 1; i <= N; i++) {
		Node *p = &G[i][0];
		for (int j = 1; j <= M; j++) {
			p = p -> right;
			cout << p -> v << " ";
		}
		cout << endl;
	}
	return 0;
}