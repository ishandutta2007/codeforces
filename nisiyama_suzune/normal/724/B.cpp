#include <iostream>

using namespace std;

int N, M;
int A[30][30];

int main () {
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			cin >> A[i][j];
	for (int i = 1; i <= M; i++)
		for (int j = 1; j <= M; j++) {
			for (int k = 1; k <= N; k++)
				swap (A[k][i], A[k][j]);
			for (int k = 1; k <= N; k++) {
				int dis = 0;
				for (int l = 1; l <= M; l++)
					if (A[k][l] != l) dis++;
				if (dis > 2) goto nextTry;
			}
			cout << "YES" << endl;
			return 0;
nextTry:;
			for (int k = 1; k <= N; k++)
				swap (A[k][i], A[k][j]);
		}
	cout << "NO" << endl;
}