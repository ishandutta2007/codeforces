#include <iostream>
#include <string>
#include <cmath>
#include <map>
#include <vector>

using namespace std;
//
int n;
string s;

//
int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//
	cin >> n;
	cin >> s;
	if (n%2 == 0) {
		for (int i=0; i < s.size(); i++) {
			if ((i!=0) && (i%2==0)) cout << "-";
			cout << s[i];
		}
		cout << endl;
	} else {
		cout << s[0];
		for (int i=1; i < s.size(); i++) {
			if ((i!=1) && (i%2==1)) cout << "-";
			cout << s[i];
		}
		cout << endl;
	}
	//
	return 0;
}