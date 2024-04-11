#include <bits/stdc++.h>

using namespace std;

long long n,a[200069],fw[200069],fi;
queue<long long> vl[26];

void ud(long long x,long long w)
{
	for(fi=x;fi<=n;fi+=fi&-fi)
	{
		fw[fi]+=w;
	}
}

long long qr(long long x)
{
	long long z=0;
	
	for(fi=x;fi;fi-=fi&-fi)
	{
		z+=fw[fi];
	}
	return z;
}

int main()
{
	long long i,k,z=0;
	char ch;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf(" %c",&ch);
		a[i]=ch-'a';
		vl[a[i]].push(i);
	}
	for(i=n;i;i--)
	{
		k=vl[a[i]].front();
		vl[a[i]].pop();
		ud(k,1);
		z+=k-qr(k);
	}
	printf("%lld\n",z);
}