#include <bits/stdc++.h>

using namespace std;
 
int main() {
	int n;
	cin >> n;
	bool ans = true;
	int p1 = 1, p2 = 2;
	for (int i = 0; i < n; ++i) {
		int temp;
		cin >> temp;
		if (temp != p1 && temp != p2)
			ans = false;
		p2 = 6 - p1 - p2;
		p1 = temp;
	}
	if (ans) cout << "YES";
	else cout << "NO";
	//system("pause");
    return 0;
}