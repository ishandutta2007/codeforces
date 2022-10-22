#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long ll;

int n;

bool isprime(int x)
{
	for(int i=2;i*i<=x;i++)
		if(x%i==0)
			return false;
	return true;
}

int vis[1001];

int main()
{
	scanf("%d",&n);
	for(int i=n;i<=n+n/2;i++)
		if(isprime(i))
		{
			printf("%d\n",i);
			for(int j=1;j<n;j++)
				printf("%d %d\n",j,j+1);
			printf("%d %d\n",n,1);
			int cnt=0;
			for(int j=1;cnt<i-n;j++)
				if(!vis[j])
					printf("%d %d\n",j,j+2),vis[j]=vis[j+2]=1,cnt++;
			return 0;
		}
}