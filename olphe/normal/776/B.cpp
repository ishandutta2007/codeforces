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
#include "string"
#include "map"

using namespace std;
const long long int MOD = 1000000007;

int N;
list<int>P;

int main() {
	cin >> N;
	if (N == 1) {
		cout << "1\n";
		cout << "1";
		return 0;
	}
	if (N == 2) {
		cout << "1\n";
		cout << "1 1";
		return 0;
	}
	if (N > 2) {
		P.push_back(2);
		P.push_back(3);
		cout << "2\n";
		cout << "1 1 ";
		for (int i = 4; i <= N + 1; i++) {
			bool flag = true;
			for (auto j = P.begin(); j != P.end(); ++j) {
				if (!(i % (*j))) {
					flag = false;
					break;
				}
			}
			if (flag) {
				P.push_back(i);
				cout << "1 ";
			}
			else cout << "2 ";
		}
	}
	return 0;
}