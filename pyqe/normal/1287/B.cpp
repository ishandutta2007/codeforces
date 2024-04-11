#include <bits/stdc++.h>

using namespace std;

int n,m;
array<int,31> a[1569];
map<array<int,31>,int> fq;
map<char,int> yk;
array<int,31> tmp;

int main()
{
	int i,j,r,ii,z=0;
	string s;
	
	yk['S']=0;
	yk['E']=1;
	yk['T']=2;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
	{
		cin>>s;
		for(j=1;j<=m;j++)
		{
			a[i][j]=yk[s[j-1]];
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=i+1;j<=n;j++)
		{
			for(r=1;r<=m;r++)
			{
				if(a[i][r]==a[j][r])
				{
					tmp[r]=a[i][r];
				}
				else
				{
					for(ii=0;ii==a[i][r]||ii==a[j][r];ii++);
					tmp[r]=ii;
				}
			}
			z+=fq[tmp];
		}
		fq[a[i]]++;
	}
	printf("%d\n",z);
}