#include <iostream>

using namespace std;

int n, m, k;

bool table[1002][1002];

int main() {
	ios::sync_with_stdio(false);

	cin >> n >> m >> k;

	int lose = -1;

	for(int step = 1; step <= k; step++) {
		int i, j;
		cin >> i >> j;

		table[i][j] = true;

		for(int dx = -1; dx <= 0; dx++) {
			for(int dy = -1; dy <= 0; dy++) {
				if(table[i+dx][j+dy] && table[i+dx+1][j+dy] && table[i+dx+1][j+dy+1] && table[i+dx][j+dy+1]) {
					if(lose == -1) {
						lose = step;
					}
				}
			}
		}
	}

	if(lose == -1) {
		cout << 0 << endl;
	} else {
		cout << lose << endl;
	}

	return 0;
}