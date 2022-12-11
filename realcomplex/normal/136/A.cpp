#include <iostream>
using namespace std;

int main() {
	
	int sk;
	cin >> sk;
	int humans[sk];
	int num;
	for(int x = 1;x<=sk;x++){
		cin >> num;
		humans[num - 1] = x;
	}
	for(int y = 0;y<sk;y++){
		cout << humans[y] << " ";
	}
	return 0;
}