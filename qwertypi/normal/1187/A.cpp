#include <iostream>

using namespace std;
int main(){
	int t;
	cin >> t;
	for(int i=0;i<t;i++){
		int a, b, c;
		cin >> a >> b >> c;
		int mu = b + c - a;
		b -= mu;
		c -= mu;
		cout << max(b, c) + 1 << endl;
	}
}