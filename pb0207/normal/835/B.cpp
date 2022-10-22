#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N=1e5+1e3+7;

int k;

char a[N];

int main()
{
	cin>>k;
	scanf("%s",a);
	int i=strlen(a);
	for(int j=0;j<i;j++)
		a[j]-=48;
	sort(a,a+i);
	for(int j=0;j<i;j++)
	{
		k-=a[j];
	}
	if(k<=0)
	{
		cout<<0;
		return 0;
	}
	for(int j=0;j<i;j++)
	{
		k-=9-a[j];
		if(k<=0)
		{
			cout<<j+1;
			break;
		}
	}
}