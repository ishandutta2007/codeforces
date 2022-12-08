#include <iostream>
using namespace std;

#define Mod 1000000007

int x[6], n;

int main(){
	cin >> x[0] >> x[1] >> n;
	n--;
	x[2] = x[1] - x[0];
	for(int i = 3; i < 6; i++)
		x[i] = -x[i - 3];
	cout << (x[n % 6] % Mod + Mod) % Mod << endl;
	return 0;
}