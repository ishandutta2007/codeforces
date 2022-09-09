#include <iostream>
#include <cmath>

using namespace std;

//
long long n, m;
//

//
int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//
	cin >> n;
	//
	if (n%36 > 34) {
		cout << ((n+1)/36) << " 0" << endl;
		return 0;
	}
	cout << (n / 36) << " ";
	if ((n%36)%3 < 2) cout << int((n% 36)/3) << endl;
	if ((n%36)%3 >= 2) cout << int((n% 36)/3+1) << endl;
	//
	return 0;
}