#include <bits/stdc++.h>

using namespace std;
 
int main() {
	int n;
	cin >> n;
	int only1 = 1, k = 1;
	int m = 0;
	while (only1 * k <= n) {
		if (n % (only1 * k) == 0)
			m = only1 * k;
		only1 = only1 * 2 + 1;
		k *= 2;
	}
	cout << m;
	//system("pause");
    return 0;
}