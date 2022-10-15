#include <iostream>

using namespace std;

#define M 1000000007

typedef long long ll;
ll d[2333444];

int main() {
	d[1] = 0;
	d[2] = 0;
	for (int i = 3; i <= 2000000; i++) {
		d[i] = 2*d[i-2]+d[i-1];
		if (i%3 == 0) d[i] += 4;
		d[i] %= M;
	}
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		cout << d[n] << "\n";
	}
}