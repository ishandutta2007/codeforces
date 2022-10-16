#include <bits/stdc++.h>

using namespace std;

long long n,m=9,a[9],sq[100069][9];

int main()
{
	long long i,j,p,pp,sz;
	bool bad;
	string s;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		cin>>s;
		sz=s.length();
		for(j=0;j<sz;j++)
		{
			if(s[sz-1-j]!='?')
			{
				sq[i][j]=s[sz-1-j]-'0';
			}
			else
			{
				sq[i][j]=-1;
			}
		}
		for(p=m-1;p+1&&(sq[i][p]==-1||a[p]==sq[i][p]);p--);
		for(pp=p+1;pp<m&&(sq[i][pp]!=-1||a[pp]==9);pp++);
		if(pp==m&&p+1&&a[p]>sq[i][p])
		{
			printf("NO\n");
			return 0;
		}
		bad=0;
		for(j=m-1;j+1;j--)
		{
			if(sq[i][j]==-1)
			{
				if(!bad)
				{
					sq[i][j]=max(a[j]+(j==pp&&p+1&&a[p]>sq[i][p]),(long long)(j==sz-1));
				}
				else
				{
					sq[i][j]=0;
				}
			}
			bad|=a[j]!=sq[i][j];
		}
		bad=1;
		for(j=0;j<m;j++)
		{
			a[j]=sq[i][j]+bad;
			bad=a[j]/10;
			a[j]%=10;
		}
	}
	printf("YES\n");
	for(i=1;i<=n;i++)
	{
		bad=0;
		for(j=m-1;j+1;j--)
		{
			bad|=sq[i][j];
			if(bad)
			{
				printf("%lld",sq[i][j]);
			}
		}
		printf("\n");
	}
}