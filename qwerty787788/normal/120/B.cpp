#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int n, k;
int a[1000];

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	//
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	k--;
	while (true) {
		if (a[k]) {
			cout << k+1 << endl;
			break;
		}else {
			k++;
			if (k == n) {
				k = 0;
			}
		}
	}
	//
	return 0;
}