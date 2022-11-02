#include <iostream>
using namespace std;
int main()
{
	int a, b, c;
	int an, d, m;
	cin >> an >> d >> m;
	cin >> a >> b >> c;
	int sum = a + b + c;
	if (an <= a) {
		a -= an;
		sum -= an;
	}
	else {
		cout << "NO";
		return 0;
	}
	if (sum - c >= d) {
		sum -= d;
	}
	else {
		cout << "NO";
		return 0;
	}
	if (sum >= m) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}
}