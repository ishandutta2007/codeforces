#include "iostream"
#include "climits"
#include "list"
#include "queue"
#include "set"
#include "functional"
#include "algorithm"
#include "math.h"
using namespace std;

int n;
char letter[10001];
char ans[10001];

int main() {
	cin >> n;
	cin >> letter;
	if (n % 2 == 1) {
		for (int i = 0; i < n; i++) {
			ans[(n / 2) - ((i % 2) * 2 - 1)*(i + 1) / 2] = letter[i];
		}
	}
	else {
		for (int i = 0; i < n; i++) {
			ans[((n - 1) / 2) + ((i % 2) * 2 - 1)*(i + 1) / 2] = letter[i];
		}
	}
	ans[n] = NULL;
	cout << ans << "\n";
	return 0;
}