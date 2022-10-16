#include <bits/stdc++.h>

using namespace std;

long long n,pm[6][3]={{0,1,2},{0,2,1},{1,0,2},{1,2,0},{2,0,1},{2,1,0}};
string s;
vector<long long> v,a[3],aa[6];

void cv()
{
	long long i,k;
	
	n=s.length();
	v.clear();
	for(i=1;i<=n;i++)
	{
		k=s[i-1];
		if(k>='A'&&k<='Z')
		{
			k+=32;
		}
		k-='a';
		if(k>=0&&k<26)
		{
			v.push_back(k);
		}
	}
}

int main()
{
	long long t,rr,i,j,r,sz;
	
	for(i=0;i<3;i++)
	{
		cin>>s;
		cv();
		a[i]=v;
	}
	for(i=0;i<6;i++)
	{
		for(j=0;j<3;j++)
		{
			sz=a[pm[i][j]].size();
			for(r=0;r<sz;r++)
			{
				aa[i].push_back(a[pm[i][j]][r]);
			}
		}
	}
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		cin>>s;
		cv();
		for(i=0;i<6;i++)
		{
			if(v==aa[i])
			{
				i=-1;
				break;
			}
		}
		if(i==-1)
		{
			printf("ACC\n");
		}
		else
		{
			printf("WA\n");
		}
	}
}