#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<stack>

using namespace std; 

int n,x,maxx;

bool hav[100001];

int main()
{
	scanf("%d",&n);
	maxx=n;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		hav[x]=1;
		if(x==maxx)
			for(int i=maxx;hav[i];i--)
				printf("%d ",i),hav[i]=0,maxx--;
		printf("\n");
	}
}