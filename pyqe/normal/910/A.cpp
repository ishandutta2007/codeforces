#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long c=0,i,ln,p=0,d;
	string s;
	
	scanf("%lld%lld",&ln,&d);
	cin>>s;
	while(p<ln-1)
	{
		for(i=min(ln-1,p+d);i>p;i--)
		{
			if(s[i]=='1')
			{
				p=i;
				i=-69;
				c++;
				break;
			}
		}
		if(i!=-69)
		{
			printf("-1\n");
			return 0;
		}
	}
	printf("%lld\n",c);
}