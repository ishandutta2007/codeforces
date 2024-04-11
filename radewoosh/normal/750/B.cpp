#include <bits/stdc++.h>
using namespace std;

int n;

int ja;

string s;
int x;

int main()
{
	cin >> n;
	for (int i=1; i<=n; i++)
	{
		cin >> x >> s;
		if (s[0]=='S')
			ja+=x;
		if (s[0]=='N')
			ja-=x;
		if ((s[0]=='W' || s[0]=='E') && (ja==0 || ja==20000))
		{
			printf("NO\n");
			return 0;
		}
		if (ja<0 || ja>20000)
		{
			printf("NO\n");
			return 0;
		}
	}
	if (ja)
	{
		printf("NO\n");
		return 0;
	}
	printf("YES\n");
	return 0;
}