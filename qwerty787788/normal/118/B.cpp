#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <set>
//#include <cmath>
using namespace std;
#define PI 3.1415926535897932384626433832795
//
int n;
//
int main() {
	//freopen("input.txt", "r", stdin);
	//
	cin >> n;
	for (int i = 0; i <= n; i++) {
		int k = 2*n+2*(-i);
		for (int j = 0; j < k; j++) cout << " ";
		for (int j = 0; j < i; j++) cout << j << " ";
		for (int j = i; j>= 0; j--) {
			cout << j;
			if (j != 0) cout << " ";	
		}
		//for (int j = 0; j < k; j++) cout << " ";
		cout << endl;
	}
	for (int i = n-1; i >= 0; i--) {
		int k = 2*n+2*(-i);
		for (int j = 0; j < k; j++) cout << " ";
		for (int j = 0; j < i; j++) cout << j << " ";
		for (int j = i; j>= 0; j--) {
			cout << j;
			if (j != 0) cout << " ";	
		}
		//for (int j = 0; j < k; j++) cout << " ";
		cout << endl;
	}
	//
	return 0;
}