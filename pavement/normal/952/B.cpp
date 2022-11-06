#include <bits/stdc++.h>
using namespace std;
 
string s, a[] = {"are you serious", "don't even", "worse", "terrible", "go die in a hole", "no way"};
 
main() {
	sort(a, a + 6);
	for (int i = 0; i <= 6; i++) {
		cout << i << endl;
		getline(cin, s);
		if (s != "no") {
			if (binary_search(a, a + 6, s)) cout << "grumpy\n";
			else cout << "normal\n";
			return 0;
		}
	}
}