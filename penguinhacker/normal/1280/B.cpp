#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define arr array

int r, c;
string grid[60];
bool pos;

void solve() {
	pos=0;
	cin >> r >> c;
	for (int i=0; i<r; ++i)
		cin >> grid[i];

	for (int i=0; i<r; ++i) {
		for (int j=0; j<c; ++j) {
			if (grid[i][j] == 'A') {
				pos=1;
				break;
			}
		}
		if (pos)
			break;
	}

	if (!pos) {
		cout << "MORTAL\n";
		return;
	}

	int best = 4;

	for (int i=0; i<r; ++i) {
		if (grid[i][0]=='A' || grid[i][c-1]=='A')
			best=3;
	}
	for (int i=0; i<c; ++i) {
		if (grid[0][i]=='A' || grid[r-1][i]=='A')
			best=3;
	}
	if (grid[0][0]=='A' || grid[0][c-1]=='A' || grid[r-1][0]=='A' || grid[r-1][c-1]=='A')
		best=2;
	for (int i=1; i<r-1; ++i) {
		pos=1;
		for (int j=0; j<c; ++j) {
			if (grid[i][j]=='P') {
				pos=0;
				break;
			}
		}
		if (pos) {
			best=2;
			break;
		}
	}
	for (int j=1; j<c-1; ++j) {
		pos=1;
		for (int i=0; i<r; ++i) {
			if (grid[i][j]=='P') {
				pos=0;
				break;
			}
		}
		if (pos) {
			best=2;
			break;
		}
	}

	pos=1;
	for (int i=0; i<r; ++i) {
		if (grid[i][0]=='P') {
			pos=0;
			break;
		}
	}
	if (pos)
		best=1;

	pos=1;
	for (int i=0; i<r; ++i) {
		if (grid[i][c-1]=='P') {
			pos=0;
			break;
		}
	}
	if (pos)
		best=1;

	pos=1;
	for (int i=0; i<c; ++i) {
		if (grid[0][i]=='P') {
			pos=0;
			break;
		}
	}
	if (pos)
		best=1;

	pos=1;
	for (int i=0; i<c; ++i) {
		if (grid[r-1][i]=='P') {
			pos=0;
			break;
		}
	}
	if (pos)
		best=1;

	pos=1;
	for (int i=0; i<r; ++i) {
		for (int j=0; j<c; ++j) {
			if (grid[i][j]=='P') {
				pos=0;
				break;
			}
		}
		if (!pos)
			break;
	}
	if (pos)
		best=0;
	cout << best << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--)
		solve();

	return 0;
}