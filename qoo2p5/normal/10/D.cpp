#include <iostream>
#include <list>
#include <cstring>

using namespace std;

int n, m;
int a[501];
int b[501];

int d[501][501];
int p[501];

int main() {
	ios::sync_with_stdio(false);

	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	cin >> m;
	for(int i = 1; i <= m; i++) {
		cin >> b[i];
	}

	for(int i = 1; i <= n; i++) {
		int best = 0;
		int ind = 0;

		for(int j = 1; j <= m; j++) {
			d[i][j] = d[i-1][j];

			if(a[i] == b[j] && d[i][j] < best + 1) {
				d[i][j] = best + 1;
				p[j] = ind;
			}

			if(a[i] > b[j] && best < d[i-1][j]) {
				best = d[i-1][j];
				ind = j;
			}
		}
	}

	int j = 0;
	for(int i = 1; i <= m; i++) {
		if(d[n][j] < d[n][i]) {
			j = i;
		}
	}

	list<int> ans;
	while(j != 0) {
		ans.push_front(b[j]);
		j = p[j];
	}

	cout << ans.size() << "\n";
	for(int i : ans) {
		cout << i << " ";
	}
	cout << endl;

	return 0;
}