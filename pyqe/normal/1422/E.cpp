#include <bits/stdc++.h>

using namespace std;

long long n,nn=0,a[100069],ls[100069],pst[100069],sza[100069];
string sq[100069];

int main()
{
	long long i,j,k;
	string s;
	
	cin>>s;
	n=s.length();
	for(i=n;i;i--)
	{
		k=s[i-1];
		if(k==a[nn]&&pst[nn]==i+1&&k>ls[nn])
		{
			nn--;
		}
		else
		{
			nn++;
			a[nn]=k;
			ls[nn]=ls[nn-1];
			if(k!=a[nn-1])
			{
				ls[nn]=a[nn-1];
			}
			pst[nn]=i;
		}
		sza[i]=nn;
		if(nn<=10)
		{
			for(j=nn;j;j--)
			{
				sq[i]+=(char)a[j];
			}
		}
		else
		{
			for(j=nn;j>nn-5;j--)
			{
				sq[i]+=(char)a[j];
			}
			sq[i]+="...";
			for(j=2;j;j--)
			{
				sq[i]+=(char)a[j];
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		printf("%lld",sza[i]);
		if(sza[i])
		{
			printf(" ");
		}
		printf("%s\n",sq[i].c_str());
	}
}