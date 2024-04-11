#include <bits/stdc++.h>

using namespace std;

bitset<26> spc;

int main()
{
	long long t,rr,i,ln,c;
	string s;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		cin>>s;
		ln=s.length();
		spc.reset();
		c=0;
		for(i=0;i<ln;i++)
		{
			c++;
			if(i==ln-1||s[i]!=s[i+1])
			{\
				if(c%2==1)
				{
					spc[s[i]-'a']=1;
				}
				c=0;
			}
		}
		for(i=0;i<26;i++)
		{
			if(spc[i])
			{
				printf("%c",i+'a');
			}
		}
		printf("\n");
	}
}