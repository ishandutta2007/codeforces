#include <bits/stdc++.h>

using namespace std;

long long n,a[1000069],zs[2],sq[2][1000069];

int main()
{
	long long i,ii,iii;
	string s;
	bool bad;
	
	cin>>s;
	n=s.length();
	for(i=1;i<=n;i++)
	{
		a[i]=s[i-1]-'a';
	}
	for(i=1;i<=n+1-i;i+=2)
	{
		bad=0;
		for(ii=0;!bad&&ii<2;ii++)
		{
			for(iii=0;iii<2;iii++)
			{
				if(a[i+ii]==a[n+1-i-iii])
				{
					sq[0][i/2]=a[i+ii];
					zs[0]++;
					if(i+ii!=n+1-i-iii)
					{
						sq[1][i/2]=a[i+ii];
						zs[1]++;
					}
					bad=1;
					break;
				}
			}
		}
	}
	for(i=0;i<zs[0];i++)
	{
		printf("%c",sq[0][i]+'a');
	}
	for(i=zs[1]-1;i>=0;i--)
	{
		printf("%c",sq[1][i]+'a');
	}
	printf("\n");
}