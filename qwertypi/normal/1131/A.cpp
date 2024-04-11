#include <iostream>
using namespace std;
int main(){
	int w1, h1, w2, h2;
	cin >> w1 >> h1 >> w2 >> h2;
	cout << 2 * (max(w1, w2) + h1 + h2) + 4;
}