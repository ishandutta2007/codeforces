#include <bits/stdc++.h>
using namespace std;

int n;
string s;

char us[3];

int wyn=1;

int main()
{
	cin >> n;
	cin >> s;
	us[0]=us[1]='X';
	for (int i=0; i<n; i++)
	{
		int p=(s[i]=='L' || s[i]=='R');
		if (us[p]!='X' && us[p]!=s[i])
		{
			wyn++;
			us[0]='X';
			us[1]='X';
		}
		us[p]=s[i];
	}
	cout << wyn << endl;
	return 0;
}