#include <bits/stdc++.h>

using namespace std;

int num = 0;

int main() {
	setbuf(stdout, NULL);
	for (int i = 0; i < 10; i++) {
		cout << i << endl;
		string a;
		getline(cin, a);
		if (a == "cool" || a == "not bad" || a == "don't think so" || a == "don't touch me!" || a == "great!") {
			cout << "normal" << endl;
			return 0;
		}
		if (a == "terrible" || a == "worse" || a == "go die in a hole" || a == "are you serious?" || a == "no way" || a == "don't even") {
			cout << "grumpy" << endl;
			return 0;
		}
		num++;
		if (num >= 4) {
			cout << "normal" << endl;
			return 0;
		}
	}
	return 0;
}