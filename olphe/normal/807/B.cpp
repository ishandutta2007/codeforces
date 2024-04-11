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
#include "unordered_map"
#include "iomanip"
#include "random"

using namespace std;
const long long int MOD = 1000000007;

int p, x, y;

int main() {
	ios::sync_with_stdio(false);
	cin >> p >> x >> y;
	
	for (int i = x; i >= y; i-=50) {
		int ra = (i / 50) % 475;
		for (int j = 0; j < 25; j++) {
			ra = (ra * 96 + 42) % 475;
			if (ra + 26 == p) {
				cout << "0\n";
				return 0;
			}
		}
	}
	for (int i = x; i <= 50000; i += 50) {
		int ra = (i / 50) % 475;
		for (int j = 0; j < 25; j++) {
			ra = (ra * 96 + 42) % 475;
			if (ra + 26 == p) {
				if ((i - x) % 100) {
					cout << (i - x) / 100 + 1 << endl;
				}
				else {
					cout << (i - x) / 100 << endl;
				}
				return 0;
			}
		}
	}
	return 0;
}