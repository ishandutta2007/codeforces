#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;


int n, k;
//
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	//
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> k;
		cout << 1-k%2<< endl;
	}
	//
	return 0;
}