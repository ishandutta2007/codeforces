#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pi pair<int, int>
const int MOD=1e9+7;

int n, m, k;

void getCell(int x) {
	int row = x/m, col;
	if (row%2==0)
		col = x%m+1;
	else
		col = m-(x%m);
	cout << row+1 << ' ' << col << ' ';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int curr = 0;
	cin >> n >> m >> k;
	for (int i=1; i<k; ++i) {
		cout << "2 ";
		getCell(curr);
		curr++;
		getCell(curr);
		curr++;
		cout << '\n';
	}
	cout << n*m-2*(k-1) << ' ';
	for (int i=0; i<n*m-2*(k-1); ++i) {
		getCell(curr);
		curr++;
	}
	return 0;
}