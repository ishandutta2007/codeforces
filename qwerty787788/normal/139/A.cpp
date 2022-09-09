#include <vector>
#include <string>
#include <iostream>
#include <cmath>

using namespace std;
int n, a[10];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//
	cin >> n;
	for (int i = 0; i < 7; i++)
		cin >> a[i];
	int day = 0, nday = 1;
	while (n > 0) {
		n -= a[day];
		if (n <= 0) {
			cout << (day+1) << endl;
			return 0;
		}
		nday++;
		day++;
		day %= 7;
	}
	//
}