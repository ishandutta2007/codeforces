#include <iostream>
using namespace std;

int main()
{
	int a,b,c;
	cin >> a >> b >> c;
	bool good = 0;
	while(c >= 0)
	{
		if(c%b == 0) good = 1;
		c -= a;
	}
	if(good) cout << "Yes\n";
	else cout << "No\n";
}