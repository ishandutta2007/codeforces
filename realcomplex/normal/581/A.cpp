#include <iostream>
using namespace std;
 
int main() {
	int n,m;
	cin >> n >> m;
	int k = min(n,m);
	cout << k << " ";
	n-=k;
	m-=k;
	cout << max(n,m)/2;
	return 0;
}