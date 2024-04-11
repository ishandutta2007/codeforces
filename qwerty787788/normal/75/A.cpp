#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;


int n;
int a, b, c;
//
int without(int x) {
	int answ = 0;
	int z = 1;
	while (x != 0) {
		if (x%10 == 0) {
			
		} else {
			answ += z*(x % 10);
			z*=10;
		}
		x /= 10;
	}
	return answ;
};
//
int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//
	cin >> a >> b;
	c = a+b;
	if (without(a)+without(b) == without(a+b)) {
		cout << "YES" << endl; 
	} else {
		cout << "NO" << endl;
	}
	
	//
	return 0;
}