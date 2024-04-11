#include<bits/stdc++.h>
using namespace std;
char x[1000001]; 
int main()
{
	cin >> x;
	for (int i=2;i<strlen(x);i++)
	{
		int a=x[i-1]-'A',b=x[i-2]-'A',c=x[i]-'A';
		if (c!=(a+b)%26)
		{
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	return 0;
}