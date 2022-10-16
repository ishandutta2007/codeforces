#include <bits/stdc++.h>

using namespace std;

long long d[2];
bool fq[2];

int main()
{
	long long t,rr,i,ln,c,sz;
	bool bad;
	string s;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		bad=0;
		scanf("%lld%lld",d,d+1);
		cin>>s;
		ln=s.length();
		c=0;
		fq[0]=0;
		fq[1]=0;
		for(i=0;i<ln;i++)
		{
			if(s[i]=='.')
			{
				c++;
				if(i==ln-1||s[i+1]=='X')
				{
					if(c>=d[1]&&c<d[0])
					{
						bad=1;
						break;
					}
					else if(c>=d[0]&&c<d[1]*2)
					{
						fq[0]=!fq[0];
					}
					else if(c>=d[1]*2)
					{
						if(fq[1])
						{
							bad=1;
							break;
						}
						fq[1]=1;
						sz=c;
					}
					c=0;
				}
			}
		}
		if(!bad)
		{
			if(fq[1])
			{
				bad=1;
				for(i=0;i+d[0]<=sz;i++)
				{
					if((i>=d[1]&&i<d[0])||i>=d[1]*2||(sz-d[0]-i>=d[1]&&sz-d[0]-i<d[0])||sz-d[0]-i>=d[1]*2)
					{
						continue;
					}
					bad=fq[0]^(i>=d[0]&&i<d[1]*2)^(sz-d[0]-i>=d[0]&&sz-d[0]-i<d[1]*2);
					if(!bad)
					{
						break;
					}
				}
			}
			else
			{
				bad=!fq[0];
			}
		}
		
		if(bad)
		{
			printf("NO\n");
		}
		else
		{
			printf("YES\n");
		}
	}
}