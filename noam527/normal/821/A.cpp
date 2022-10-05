#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <string>
using namespace std;

int n, a[50][50];

// Time: O(N ^ 4). did not bother optimizing since 50 ^ 4 = ~6M, good enough.

bool findsum(vector<int> &r, vector<int> &c, int val) {
	for (int i = 0; i < r.size(); i++) for (int j = 0; j < c.size(); j++)
		if (r[i] + c[j] == val)
			return true;
	return false;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> a[i][j];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] != 1) {
				vector<int> r, c;
				for (int k = 0; k < n; k++)
					r.push_back(a[i][k]);
				for (int k = 0; k < n; k++)
					c.push_back(a[k][j]);
				if (!findsum(r, c, a[i][j])) {
					cout << "No" << endl;
					return 0;
				}
			}
		}
	}
	cout << "Yes" << endl;
	return 0;
}