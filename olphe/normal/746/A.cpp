#include "iostream"
#include "climits"
#include "list"
#include "queue"
#include "set"
#include "functional"
#include "algorithm"
#include "math.h"
using namespace std;

int a,b,c;
int ans;

int main() {
	cin >> a >> b >> c;
	ans = min({ a / 1,b / 2,c / 4 });
	cout << ans * 7 << "\n";
	return 0;
}