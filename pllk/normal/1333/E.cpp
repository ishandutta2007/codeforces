#include <iostream>

using namespace std;

int r[555][555];

void create(int n, int y, int x, int u) {
	if (n == 3) {
		int r3[] = {1,2,4,5,3,8,9,6,7};
		int c = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				r[y+i][x+j] = r3[c++]+u;
			}
		}
		return;
	}
	if (n == 4) {
		int r4[] = {1,2,3,4,5,6,7,8,9,10,11,14,13,16,12,15};
		int c = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				r[y+i][x+j] = r4[c++]+u;
			}
		}
		return;
	}
	int c = u+1;
	for (int i = 0; i < n; i++) {
		r[y][x+i] = c++;
	}
	for (int i = n-1; i >= 0; i--) {
		r[y+1][x+i] = c++;
	}
	for (int i = 2; i < n; i++) {
		r[y+i][x] = c++;
	}
	for (int i = n-1; i >= 2; i--) {
		r[y+i][x+1] = c++;
	}
	create(n-2,y+2,x+2,c-1);
}

int main() {
	int n;
	cin >> n;
	if (n <= 2) {
		cout << "-1\n";
		return 0;
	}
	create(n,1,1,0);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << r[i][j] << " ";
		}
		cout << "\n";
	}
}