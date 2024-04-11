#include <iostream>
#include <map>

using namespace std;

map<char, int> p;
int sum = 0;

int main() {
	p['Q'] = 9;
	p['R'] = 5;
	p['B'] = 3;
	p['N'] = 3;
	p['P'] = 1;
	p['q'] = -9;
	p['r'] = -5;
	p['b'] = -3;
	p['n'] = -3;
	p['p'] = -1;
	p['.'] = 0;
	p['K'] = p['k'] = 0;
	for(int i = 0;i < 8;i++) {
		string str;
		cin >> str;
		for(int j = 0;j < 8;j++) {
			sum += p[str[j]];
		}
	}
	if(sum == 0) {
		cout << "Draw" << endl;
	}else if(sum > 0) {
		cout << "White" << endl;
	}else {
		cout << "Black" << endl;
	}
	return 0;
}