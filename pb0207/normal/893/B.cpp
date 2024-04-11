#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=1e6+1e3+7;

int n;

bool vis[N];

int main()
{
	cin>>n;
	for(int i=1;i<=10;i++)
		vis[((1<<i)-1)*(1<<(i-1))]=1;
	for(int i=n;i>=1;i--)
		if(n%i==0&&vis[i])
		{
			printf("%d",i);
			return 0;
		}
}