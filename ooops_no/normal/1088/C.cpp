#include<vector>
#include<iostream>
using namespace std;
int main() {
	int n, i;
	cin >> n;
	vector<int> v(n);
	for (i = 0; i < n; i++) {
		cin >> v[i];
	}
	int summa = 0,b;
	cout << n + 1 << endl;
	for (i = n - 1; i > -1;i--){
		b = i - (summa + v[i]) % n;
		if (b < 0) {
			b += n;
		}
		summa += b;
		cout << "1 "<<i + 1 << " " << b << endl;
	}
	cout << "2 " << n << " " << n;
}