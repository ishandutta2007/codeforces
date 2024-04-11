#include <iostream>

using namespace std;

int n;

int main() {
	int i,j;
	cin >> n;
	if(n%2) {
		for(i=0;i<n;i++)
			cout << i << " ";
		cout << endl;
		for(i=0;i<n;i++)
			cout << i << " ";
		cout << endl;
		for(i=0;i<n;i++)
			cout << (i+i)%n << " ";
	}else {
		cout << "-1";
	}
	cout << endl;
	return 0;
}