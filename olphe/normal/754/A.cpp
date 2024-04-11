#include "iostream"
#include "iomanip"
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
int sum;
bool flag;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> num[i];
		sum += num[i];
		if (num[i] != 0)flag = 1;
	}
	if (!flag) {
		cout << "NO\n";
		return 0;
	}
	cout << "YES\n";
	if (sum != 0) {
		cout << "1\n1 " << N << "\n";
		return 0;
	}
	cout << "2\n";
	for (int i = 0; i < N; i++) {
		if (num[i] != 0) {
			cout << "1 " << i + 1 << "\n";
			cout << i + 2 << " " << N << "\n";
			break;
		}
	}
	return 0;
}