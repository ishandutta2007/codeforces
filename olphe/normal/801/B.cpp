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

string x, y, z;

int main(){
	cin >> x;
	cin >> y;
	string::iterator i = x.begin();
	string::iterator j = y.begin();
	for (; i != x.end(); ++i, ++j) {
		if (*i < *j) {
			cout << "-1\n";
			return 0;
		}
		z += *j;
	}
	cout << z << endl;
}