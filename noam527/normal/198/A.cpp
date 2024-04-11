#include <iostream>
using namespace std;
int main() {
	long long k, b, n, t, a = 1, i = 0;
	cin >> k >> b >> n >> t;
	while (a <= t) a = a * k + b, i++;
	cout << (n - i + 1 > 0 ? n - i + 1 : 0) << endl;
}