#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=1e5+1e3+7;

int n;

char s[N];

int main()
{
	scanf("%d",&n);
	scanf("%s",s+1);
	int stn=0,sto=0;
	for(int i=1;i<=n;i++)
	{
		stn+=s[i]=='-'?1:-1;
		sto=max(sto,stn);
	}
	printf("%d",sto-stn);
}