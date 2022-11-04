#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int query(int x, int y) {
	int dist;
	cout << "? " << x << " " << y << endl;
	cin >> dist;
	assert(dist != -1);
	if (dist == -1) {exit(0); return 0;}
	return dist;
}

int main() {
	int y, Y, x, X;

	int st = 1, dr = INF;

	int h1 = query(1, 1);
	int h2 = query(1, INF);

	if (h1 > h2) st = st + (h1 - h2);	
	else dr = dr - (h2 - h1);

	int mij = (st + dr) / 2;
	int h = query(1, mij);

	x = h + 1;

	st = 1; dr = INF;
	h1 = query(1, 1);
	h2 = query(INF, 1);

	if (h1 > h2) st = st + (h1 - h2);	
	else dr = dr - (h2 - h1);

	mij = (st + dr) / 2;
	h = query(mij, 1);
	y = h + 1;

	st = 1; dr = INF;
	h1 = query(INF, 1);
	h2 = query(INF, INF);

	if (h1 > h2) st = st + (h1 - h2);	
	else dr = dr - (h2 - h1);

	mij = (st + dr) / 2;
	h = query(INF, mij);
	X = INF - h;

	st = 1; dr = INF;
	h1 = query(1, INF);
	h2 = query(INF, INF);

	if (h1 > h2) st = st + (h1 - h2);	
	else dr = dr - (h2 - h1);

	mij = (st + dr) / 2;
	h = query(mij, INF);
	Y = INF - h;

	cout << "! " << x << " " << y << " " << X << " " << Y << endl;

	return 0;
}