#include<bits/stdc++.h>
using namespace std;

int n,m,r,c,T;

int dis(int x,int y)
{
	return abs(x-r)+abs(y-c);
}

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d%d%d",&n,&m,&r,&c);
		printf("%d\n",max(max(dis(1,1),dis(n,m)),max(dis(1,m),dis(n,1))));
	}
	return 0;
}