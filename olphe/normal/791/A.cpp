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

long long int a, b;
int ans;

int main() {
	cin >> a >> b;
	while (a <= b) {
		a *= 3;
		b *= 2;
		ans++;
	}
	cout << ans << endl;
	return 0;
}