#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int n;

int visa,visb;

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		if(x<0)
			visa++;
		if(x>0)
			visb++;
	}
	if(visa<=1||visb<=1)
		printf("Yes");
	else
		printf("No");
}