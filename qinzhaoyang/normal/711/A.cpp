#include <iostream>

using namespace std;

int n;
string a[1002];
bool f = false;

int main()
{
	cin >> n;
	cin.get();
	for(int i = 1; i <= n; i++)
	{
		getline(cin , a[i]);
		if(f)
			continue;
		if(a[i][0] == a[i][1] && a[i][0] == 'O')
		{
			a[i][0] = a[i][1] = '+';
			f = true;
		}
		else if(a[i][3] == a[i][4] && a[i][3] == 'O')
		{
			a[i][3] = a[i][4] = '+';
			f = true;
		}
	}
	if(f)
	{
		cout << "YES" << endl;
		for(int i = 1; i <= n; i++)
			cout << a[i] << endl;
	}
	else
		cout << "NO" << endl;
	return 0;
}