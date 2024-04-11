#include <iostream>
using namespace std;

int main()
{
	int n,t;
	cin >> n >> t;
	if(n == 1 && t == 10)
	{
		cout << -1 << '\n';
		return 0;
	}
	cout << t;
	n--;
	if(t==10) n--;
	while(n>0)
	{
		cout << '0';
		n--;
	}
	cout << '\n';
}