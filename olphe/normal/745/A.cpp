#include "iostream"
#include "climits"
#include "list"
#include "queue"
#include "set"
#include "functional"
#include "algorithm"
#include "math.h"
using namespace std;

int N;
char letter[50][51];
int flag[50];
bool box;
int ans;

int main() {
	cin >> letter[0];
	for (int i = 0; letter[0][i] != NULL; i++) {
		N = i;
	}
	//cout << N << "\n";
	for (int i = 1; i <= N; i++) {
		flag[i] = i;
		for (int j = 0; j <= N; j++) {		
			letter[i][j] = letter[0][(j + i) % (N + 1)];
		}
	}
	for (int i = 0; i <= N; i++) {
		for (int j = i + 1; j <= N; j++) {
			box = true;
			for (int k = 0; k <= N; k++) {
				if (letter[i][k] != letter[j][k]) {
					box = false;
				}
			}
			if (box) {
				flag[j] = i;
			}
		}
	}
	for (int i = 0; i <= N; i++) {
	//cout << letter[i] << "\n";
		if (i == flag[i])ans++;
	}
	cout << ans << "\n";
	return 0;
}