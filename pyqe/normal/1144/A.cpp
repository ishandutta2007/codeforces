#include <bits/stdc++.h>

using namespace std;

long long fq[26],ln;

int main()
{
	long long t,rr,i,u=0;
	bool bad;
	string s;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		cin>>s;
		ln=s.length();
		for(i=0;i<26;i++)
		{
			fq[i]=0;
		}
		for(i=0;i<ln;i++)
		{
			fq[s[i]-'a']++;
		}
		bad=0;
		u=0;
		for(i=0;i<26;i++)
		{
			if(fq[i]>1)
			{
				bad=1;
				break;
			}
			if(fq[i]==1&&u==0)
			{
				u++;
			}
			else if(fq[i]==0&&u==1)
			{
				u++;
			}
			else if(fq[i]==1&&u==2)
			{
				bad=1;
				break;
			}
		}
		if(!bad)
		{
			printf("Yes\n");
		}
		else
		{
			printf("No\n");
		}
	}
}