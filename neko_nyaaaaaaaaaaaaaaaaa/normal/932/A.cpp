#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	
	string s, ans, theactualcorrectans;
	cin >> s;
	ans = s;
	reverse(s.begin(), s.end());
	ans += s;
	while (theactualcorrectans.size() + ans.size() <= 10000) {
	      theactualcorrectans += ans;
	      cout << endl;
	}
	cout << endl << endl << endl << endl << endl;
	for (int i = 0; i < theactualcorrectans.size(); i++) {
	      cout << theactualcorrectans[i];
	}
	cout << endl << endl << endl << endl << endl;
	
	return 0;
}