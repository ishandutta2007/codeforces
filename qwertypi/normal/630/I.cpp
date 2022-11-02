#include <iostream>

using namespace std;
int main(){
	int n;
	cin >> n;
	cout << (3LL << (2*n-3)) + ((9LL * (n - 3)) << (2*n-6)); 
}