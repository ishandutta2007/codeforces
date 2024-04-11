#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,a1,a2,b1,b2;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		if(x%2) a1++;
		else a2++; 
	}
	for(int i=1;i<=m;i++)
	{
		int x;
		scanf("%d",&x);
		if(x%2) b1++;
		else b2++; 
	}
	printf("%d",min(a1,b2)+min(a2,b1));
	return 0;
}