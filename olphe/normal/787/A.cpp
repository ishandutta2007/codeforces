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
long long int ans = 0;

int main() {
	cin >> a >> b;
	cin >> c >> d;
	for (int i = 0; i <= 100; i++) {
		for (int j = 0; j <= 100; j++) {
			if (b + a*i == d + c*j) {
				if (!ans)ans = b + a*i;
				else ans = min(b + a*i, ans);
			}
		}
	}
	if(ans)cout << ans << endl;
	else cout << "-1\n";
	return 0;
}