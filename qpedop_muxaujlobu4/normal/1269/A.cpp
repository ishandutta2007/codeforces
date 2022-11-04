#include <iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<queue>
#include<string>
#include <tuple>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	long long n;
	cin >> n;
	if (n == 1) {
		cout << 9 << " " << 8;
		return 0;
	}
	cout << 3 * n << " " << 2 * n;
	return 0;
}
// int a, b, c; tuple<i,i,i> t
// tie(a, b, c) = t;