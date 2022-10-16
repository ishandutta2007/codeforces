#include <bits/stdc++.h>

using namespace std;

long long n,ln,ky[26],fq[26],a[100069];

int main()
{
	long long t,rr,i,j;
	string s;
	bool bad;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		for(i=0;i<26;i++)
		{
			ky[i]=0;
			fq[i]=0;
		}
		cin>>s;
		n=s.length();
		for(i=1;i<=n;i++)
		{
			ky[s[i-1]-'a']++;
		}
		cin>>s;
		ln=s.length();
		bad=1;
		for(i=1;i<=ln;i++)
		{
			a[i]=s[i-1]-'a';
			fq[a[i]]++;
			if(i>n)
			{
				fq[a[i-n]]--;
			}
			if(i>=n)
			{
				for(j=0;j<26;j++)
				{
					if(fq[j]!=ky[j])
					{
						j=-1;
						break;
					}
				}
				if(j!=-1)
				{
					bad=0;
					break;
				}
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