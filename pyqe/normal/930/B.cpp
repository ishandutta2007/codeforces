#include <bits/stdc++.h>

using namespace std;

long long n,a[5069],as[5069][5069],inf=1e18;
vector<long long> vl[26];

int main()
{
	long long i,j,r,sz,c,mx,z=0;
	string s;
	
	cin>>s;
	n=s.length();
	for(i=0;i<n;i++)
	{
		a[i]=s[i]-'a';
		vl[a[i]].push_back(i);
	}
	for(i=0;i<26;i++)
	{
		sz=vl[i].size();
		for(j=0;j<sz;j++)
		{
			for(r=0;r<n;r++)
			{
				as[r][j]=a[(vl[i][j]+r)%n];
			}
		}
		if(sz)
		{
			mx=-inf;
			for(j=0;j<n;j++)
			{
				sort(as[j],as[j]+sz);
				c=0;
				for(r=0;r<sz;r++)
				{
					c+=(!r||as[j][r]>as[j][r-1])&&(r==sz-1||as[j][r]<as[j][r+1]);
				}
				mx=max(mx,c);
			}
			z+=mx;
		}
	}
	printf("%.15lf\n",(double)z/n);
}