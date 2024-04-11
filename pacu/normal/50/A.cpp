#include <iostream>
using namespace std;
int main()
{
	int m,n;
	cin >> m >> n;
	if(!((m*n)%2)) cout << m*n/2 << endl;
	else
	{
		cout << (n/2) + (m-1)*n/2 << endl;
	}
}