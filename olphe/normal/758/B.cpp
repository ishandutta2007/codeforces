#include "iostream"
#include "climits"
#include "list"
#include "queue"
#include "set"
#include "functional"
#include "algorithm"
#include "math.h"
#include "utility"

using namespace std;

int N;
char letter[101];
int status[4];
int ans[4];
int sum[4];
bool flag[4];
bool out;

int main() {
	cin >> letter;
	for (int i = 0; letter[i] != NULL; i++) {
		N = i;
		if (letter[i] == 'R') {
			status[0] = i % 4;
			sum[0]++;
		}
		else if (letter[i] == 'B') {
			status[1] = i % 4;
			sum[1]++;
		}
		else if (letter[i] == 'Y') {
			status[2] = i % 4;
			sum[2]++;
		}
		else if (letter[i] == 'G') {
			status[3] = i % 4;
			sum[3]++;
		}
	}
	N++;
	for (int i = 0; i < 4; i++) {
		ans[i] = N / 4;
		ans[i] += (N % 4 > status[i]);
		ans[i] -= sum[i];
		cout << ans[i] << " ";
	}
	cout << endl;
	return 0;
}