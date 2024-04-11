#include <bits/stdc++.h>

using namespace std;

long long n,m=0,a[100069],pst[100069];

int main()
{
	long long i,ls=0;
	string s;
	
	cin>>s;
	n=s.length();
	for(i=1;i<=n;i++)
	{
		a[i]=s[i-1]-'a';
		if(a[i])
		{
			m++;
			pst[m]=i;
		}
		else
		{
			ls=i;
		}
	}
	pst[m+1]=n+1;
	if(m%2==1||pst[m/2+1]<ls)
	{
		printf(":(\n");
		return 0;
	}
	for(i=1;i<=m/2;i++)
	{
		if(a[pst[i]]!=a[pst[i+m/2]])
		{
			printf(":(\n");
			return 0;
		}
	}
	for(i=1;i<pst[m/2+1];i++)
	{
		printf("%c",(char)a[i]+'a');
	}
	printf("\n");
}