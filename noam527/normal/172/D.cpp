#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	vector<int> d(1e7 + 1, -1);
	for (int i = floor(sqrt(1e7)); i >= 1; i--)
		for (int j = i * i; j <= 1e7; j += i * i)
			if (d[j] == -1) d[j] = i * i;
	int a, n;
	cin >> a >> n;
	long long p = 0;
	for (int i = a; i < a + n; i++) p += i / d[i];
	cout << p << endl;
}