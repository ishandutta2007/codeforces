#include <iostream>
#include <string>
using namespace std;
int main() {
	string s1, s2;
	cin >> s1 >> s2;
	int cnt = 0;
	for (int i = 0; i < s1.size(); i += 2) {
		if (s1[i] == '8') {
			if (s2[i] == '[')
				cnt++;
			if (s2[i] == '(')
				cnt--;
		}
		else if (s1[i] == '[') {
			if (s2[i] == '(')
				cnt++;
			if (s2[i] == '8')
				cnt--;
		}
		else {
			if (s2[i] == '8')
				cnt++;
			if (s2[i] == '[')
				cnt--;
		}
	}
	if (cnt == 0) cout << "TIE" << endl;
	else if (cnt > 0) cout << "TEAM 1 WINS" << endl;
	else cout << "TEAM 2 WINS" << endl;
	return 0;
}