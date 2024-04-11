#include <bits/stdc++.h>

using namespace std;

long long n[3],a[3][100069],fq[26];

int main()
{
	long long t,rr,i,j;
	string s;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		for(i=0;i<3;i++)
		{
			cin>>s;
			n[i]=s.length();
			for(j=1;j<=n[i];j++)
			{
				a[i][j]=s[j-1]-'a';
			}
		}
		for(i=0;i<26;i++)
		{
			fq[i]=0;
		}
		for(i=1;i<=n[2];i++)
		{
			fq[a[2][i]]++;
		}
		for(j=1,i=1;i<=n[1];i++)
		{
			if(j<=n[0]&&a[1][i]==a[0][j])
			{
				j++;
			}
			else
			{
				fq[a[1][i]]--;
				if(fq[a[1][i]]<0)
				{
					j=-1;
					break;
				}
			}
		}
		if(j>n[0])
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
}