#include <iostream>
#include <cmath>
#include <string>

using namespace std;

//
string s;
//

//
int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//
	cin >> s;
	int h = 0;
	//
	for (int i = 0; i < s.size(); i++) {
		if ((s[i] == '<') && (s[i+1] != '/')) {
			for (int j = 0; j < 2*h; j++) cout << " ";
			while (s[i] != '>') {
				cout << s[i];
				i++;
			}
			cout << ">";
			h++;
		} else {
		if ((s[i] == '<') && (s[i+1] == '/')) {
			h--;
			for (int j = 0; j < 2*h; j++) cout << " ";
			while (s[i] != '>') {
				cout << s[i];
				i++;
			}
			cout << ">";
		}
		}
		cout << endl;
	}
	//
	return 0;
}