#include <iostream>   
using namespace std;


int main()
{
	int x, c, max = 0, sum = 0;
	cin >> x;
	for (int i = 0; i < x; i++) {
		cin >> c;
		if (c > max) {
			max = c;
		}
		sum += c;
	}
	while (!(x*max - sum > sum)) {
		max += 1;
	}
	cout << max;
}