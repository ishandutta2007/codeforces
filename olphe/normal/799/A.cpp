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

long long int a, b, c, d;
long long int box, bag;

int main() {
	ios::sync_with_stdio(false);
	cin >> a >> b >> c >> d;
	box = (a / c + !!(a%c))*b - b;
	if (box > d)cout << "YES\n";
	else cout << "NO\n";
	return 0;
}