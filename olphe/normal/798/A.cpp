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

int N;
string S;

int main() {
	cin >> S;
	string::iterator itr = S.begin();
	string::reverse_iterator ritr = S.rbegin();
	bool flag = true;
	for (; itr != S.end(); ++itr, ++ritr) {
		if (*itr != *ritr) {
			*ritr = *itr;
			flag = false;
			break;
		}
	}
	if (flag&&S.size() % 2 == 0) {
		cout << "NO\n";
		return 0;
	}
	itr = S.begin();
	ritr = S.rbegin();
	for (; itr != S.end(); ++itr, ++ritr) {
		if (*itr != *ritr) {
			cout << "NO\n";
			return 0;
		}
	}
	cout << "YES\n";
	return 0;
}