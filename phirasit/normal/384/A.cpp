#include <iostream>

using namespace std;

int n;

int main() {
	int i,j;
	cin >> n;
	cout << n * (n/2 + n%2) - (n%2) * (n/2) << endl;
	for(i=0;i<n;i++) {
		for(j=0;j<n;j++) {
			if((i+j)%2)
				cout << ".";
			else
				cout << "C";
		}
		cout << endl;
	}
	return 0;
}