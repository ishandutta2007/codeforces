#include <bits/stdc++.h>

using namespace std;

long long n,m,fq[2],faf[500069];
bitset<500069> a;

int main()
{
	long long i,j,k;
	string s;
	
	cin>>s;
	n=s.length();
	for(i=1;i<=n;i++)
	{
		k=s[i-1]-'0';
		fq[k]++;
	}
	cin>>s;
	m=s.length();
	faf[0]=-1;
	for(i=1;i<=m;i++)
	{
		a[i]=s[i-1]-'0';
		for(j=faf[i-1];j>=0&&a[j+1]!=a[i];j=faf[j]);
		faf[i]=j+1;
	}
	for(j=1,i=1;i<=n;i++,j++)
	{
		if(j>m)
		{
			j=faf[m]+1;
		}
		if(fq[a[j]])
		{
			printf("%d",(bool)a[j]);
			fq[a[j]]--;
		}
		else
		{
			printf("%d",(bool)!a[j]);
			fq[!a[j]]--;
		}
	}
	printf("\n");
}