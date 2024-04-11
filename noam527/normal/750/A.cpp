#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int tot = 0, n, k, i = 0;

int main() {
	ios::sync_with_stdio(0);
	cin >> n >> k;
	while (i < n && tot <= 240 - k)
		tot += 5 * ++i;
	if (tot > 240 - k) i--;
	cout << i << endl;
	return 0;
}