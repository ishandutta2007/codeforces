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

int main() {
	cin >> N;
	cout << N / 2 << "\n";
	for (int i = 0; i < N / 2-1; i++) {
		cout << "2 ";
	}
	if (N % 2 == 0)cout << "2\n";
	else cout << "3\n";
	return 0;
}