#include <iostream>
using namespace std;

int main()
{
	long long n;
	cin >> n;
	if(n%2)
		cout << -(n+1)/2 << endl;
	else
		cout << (n+1)/2 << endl;
	return 0;
}