#include "iostream"
#include "climits"
#include "list"
#include "queue"
#include "stack"
#include "set"
#include "functional"
#include "algorithm"
#include "math.h"
#include "utility"
#include "map"

using namespace std;
const long long int MOD = 1000000007;

long long int K, A, B;

int main() {
	cin >> K >> A >> B;
	if (K > A&&K > B) {
		cout << "-1\n";
		return 0;
	}
	if (K > A) {
		if (B%K) {
			cout << "-1\n";
			return 0;
		}
	}
	if (K > B) {
		if (A%K) {
			cout << "-1\n";
			return 0;
		}
	}
	cout << A / K + B / K << endl;
	return 0;
}