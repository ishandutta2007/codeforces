#include <iostream>

using namespace std;

string str;
int n;

int main() {
	cin >> n >> str;
	for(int gap = 1;gap <= n;gap++) {
		for(int i = 0;i < n;i++) {
			for(int j = 0;j < 5;j++) {
				if(i + j * gap >= n || str[i + j * gap] == '.') {
					break;
				}
				if(j == 4) {
					cout << "yes" << endl;
					return 0;
				}
			}
		}
	}
	cout << "no" << endl;
	return 0;
}