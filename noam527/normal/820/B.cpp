#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#define endl '\n'
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	int n, a;
	cin >> n >> a;
	cout << "1 2 " << max(3, n + 1 - max(1, (int)round(a / ((1.0 - (n - 2.0) / n) * 90.0)))) << endl;
	return 0;
}