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
int num[100];
int ans;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> num[i];
		if (ans < num[i])ans = num[i];
	}
	ans *= N;
	for (int i = 0; i < N; i++) {
		ans -= num[i];
	}
	cout << ans << endl;
	return 0;
}