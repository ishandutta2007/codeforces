#include <bits/stdc++.h>

using namespace std;

long long n,nn[2],ca[2][1069],faf[1069];
string s[1069];

bool cln(string x,string y)
{
	return x.length()<y.length();
}

int main()
{
	long long i,j,r,ii,c;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		cin>>s[i];
	}
	sort(s+1,s+n+1,cln);
	for(i=1;i<n;i++)
	{
		for(ii=0;ii<2;ii++)
		{
			nn[ii]=s[i+ii].length();
			for(j=1;j<=nn[ii];j++)
			{
				ca[ii][j]=s[i+ii][j-1]-'a';
			}
		}
		faf[0]=-1;
		for(j=1;j<=nn[0];j++)
		{
			for(r=faf[j-1];r+1&&ca[0][r+1]!=ca[0][j];r=faf[r]);
			faf[j]=r+1;
		}
		c=0;
		for(j=1;j<=nn[1];j++)
		{
			for(;c+1&&ca[0][c+1]!=ca[1][j];c=faf[c]);
			c++;
			if(c==nn[0])
			{
				break;
			}
		}
		if(j>nn[1])
		{
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
	for(i=1;i<=n;i++)
	{
		printf("%s\n",s[i].c_str());
	}
}