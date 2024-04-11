#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, k, t, x, y;
int bx2[1001];
int by2[1001];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//
	cin >> n >> m >> k >> t;
	for (int i = 0; i < k; i++) {
		cin >> by2[i] >> bx2[i];
	}	
	//
	for (int i = 0; i < t; i++) {
		bool al = false;
		cin >> y >> x;
		long long sum = m*(y-1)+x;
		for (int j = 0; j < k; j++)
			if (by2[j] < y || (by2[j]==y && bx2[j] <= x)) 
				if (by2[j] == y && bx2[j] == x) {
					cout << "Waste" << endl;
					al = true;
					break;
				} else sum--;
		if (!al)
		if ((sum % 3) == 0) cout << "Grapes" << endl; else
			if ((sum % 3) == 1) cout << "Carrots" << endl; else
				if ((sum % 3) == 2) cout << "Kiwis" << endl;
	}
	//
	return 0;
};