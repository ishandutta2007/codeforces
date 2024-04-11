#include <iostream>
using namespace std;

int main()
{
	int x;
	cin >> x;
	if(x==0)
	{
		cout << 0 << endl;
		return 0;
	}
	if(x<0)
		x = -x;
	if(x%2)
	{
		int ans = 2;
		int mult = 3;
		while(x>((ans/2)*mult))
		{
			ans += 4;
			mult += 4;
		}
		if(x<=((ans-1)*(mult-1)/2))
			cout << ans-1 << endl;
		else
			cout << ans << endl;
	}
	else
	{
		int ans = 4;
		int mult = 5;
		while(x>((ans/2)*mult))
		{
			ans += 4;
			mult += 4;
		}
		if(x<=((ans-1)*(mult-1)/2))
			cout << ans-1 << endl;
		else
			cout << ans << endl;
	}
}