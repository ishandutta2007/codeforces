#include <iostream>

using namespace std;

int a1, a2, k1, k2;
int n;

int main() {
	cin >> a1 >> a2 >> k1 >> k2;
	if (k1 > k2) {swap(k1,k2); swap(a1,a2);}
	cin >> n;
	int c1 = max(0,n-(a1*(k1-1))-(a2*(k2-1)));
	int c2 = 0;
	while (n >= k1 && a1) {n -= k1; a1--; c2++;}
	while (n >= k2 && a2) {n -= k2; a2--; c2++;}
	cout << c1 << " " << c2 << "\n";
}