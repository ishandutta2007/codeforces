#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int c(int n) { return n < 2 ? 1 : n * c(n - 1); }
int main() {
	ios::sync_with_stdio(false);
	int a, b;
	cin >> a >> b;
	cout << c(min(a, b)) << endl;
}