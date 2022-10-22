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

int t;

int main() {
	ios::sync_with_stdio(false);
	cin >> t;
	for (int i = 0; i < t; i++) {
		long long int x, y, p, q;
		long long int z, r;
		cin >> x >> y >> p >> q;
		z = y - x;
		r = q - p;
		long long int box = 0, bag = 0;
		if (p) {
			box = x / p;
			if (x%p)box++;
		}
		if (!r||!p) {
			if (!r) {
				if (z) {
					cout << "-1\n";

				}
				else {
					cout << "0\n";

				}
			}
			else {
				if (x) {
					cout << "-1\n";
				}
				else cout << "0\n";
			}
		}
		else {
			bag = z / r;
			if (z%r)bag++;
			cout << max(box, bag)*p - x + max(box, bag)*r - z << endl;
		}
	}
	return 0;
}