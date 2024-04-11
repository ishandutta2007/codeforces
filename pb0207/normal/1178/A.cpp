#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

const int N=1e5+1e3+7;

int n,a[N];

vector<int>v;

int main()
{
	scanf("%d",&n);
	int sum=0;
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]),sum+=a[i];
	int csm=a[1];
	for(int i=2;i<=n;i++)
		if(a[i]*2<=a[1])
			v.push_back(i),csm+=a[i];
	if(csm*2<=sum)
		puts("0");
	else
	{
		printf("%d\n",(int)v.size()+1);
		printf("1 ");
		for(int i=0;i<v.size();i++)
			printf("%d ",v[i]);
	}
}