#include <iostream>

using namespace std;

int n;
string a  , b;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n >> a;
		b = "";
		for(int i = 0; i < n; i++)
		{
			if(a[i] == '1')
				break;
			b += '0';
		}
		b += '0';
		for(int i = n - 1; i >= 0; i--)
		{
			if(a[i] == '0')
				break;
			b += '1';
		}
		if(b.size() > a.size())
			cout << a << endl;
		else
			cout << b << endl;
	}
	return 0;
}