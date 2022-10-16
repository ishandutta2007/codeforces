#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long ln,i;
	string s;
	
	scanf("%lld",&ln);
	cin>>s;
	if(s[0]=='S'&&s[ln-1]=='F')
	{
		printf("YES\n");
	}
	else
	{
		printf("NO\n");
	}
}