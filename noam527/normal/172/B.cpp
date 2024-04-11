#include <iostream>
#include <vector>
using namespace std;

int main() {
	int a, b, m, r, i = 0;
	cin >> a >> b >> m >> r;
	vector<int> seen(m, -1);
	seen[r] = 0;
	while (++i) {
		r = (a * r + b) % m;
		if (seen[r] != -1) {
			cout << i - seen[r] << endl;
			return 0;
		}
		seen[r] = i;
	}
}