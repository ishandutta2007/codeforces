#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	if(n<=2) cout << 1 << '\n' << 1 << '\n';
	else if(n==3) cout << 2 << '\n' << "1 3\n";
	else
	{
		cout << n << '\n';
		for(int i=2;i<=n;i+=2)
			cout << i << ' ';
		for(int i=1;i<=n;i+=2)
			cout << i << ' ';
		cout << '\n';
	}
}