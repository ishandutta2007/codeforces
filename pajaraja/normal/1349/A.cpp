#include <bits/stdc++.h>
using namespace std;
vector<int> pe[200007];
bool sl[200007];
int a[200007];
void eratosten(int b)
{
	for(int i=2;i<=b;i++)
	{
		if(!sl[i]) for(int j=2*i;j<=b;j+=i) sl[j]=true;
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	eratosten(200000);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	for(int i=0;i<n;i++)
	{
		for(int j=2;j*j<=a[i];j++) if(a[i]%j==0)
		{
			int exp=0;
			while(a[i]%j==0) {exp++; a[i]/=j;}
			pe[j].push_back(exp);
		}
		pe[a[i]].push_back(1);
	}
	long long sol=1;
	for(int i=2;i<=200000;i++) if(!sl[i])
	{
		sort(pe[i].begin(),pe[i].end());
		int x;
		if(pe[i].size()==n) x=pe[i][1];
		if(pe[i].size()==n-1) x=pe[i][0];
		if(pe[i].size()<n-1) x=0;
		for(int j=0;j<x;j++) sol=(sol*(long long)i);
	}
	printf("%lld",sol);
}