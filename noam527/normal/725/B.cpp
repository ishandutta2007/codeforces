#include <iostream>
#include <string>
using namespace std;

int main() {
	string str;
	cin >> str;
	long long n = 0, i = 0, s = (str[str.size() - 1] > 'c' ? 'g' - str[str.size() - 1] : str[str.size() - 1] - 'a' + 4);
	while (str[i] < 'a') n = n * 10 + str[i] - '0', i++;
	n--;
	cout << 16 * (n / 4) + (n % 2) * 7 + s << endl;
}