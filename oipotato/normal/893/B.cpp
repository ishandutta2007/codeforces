#include<bits/stdc++.h>
using namespace std;
int n,ans,k;
int main()
{
	scanf("%d",&n);
	for(int k=1;;k++)
	{
		int x=((1<<k)-1)<<(k-1);
		if(x>n)
		{
			break;
		}
		if(n%x==0)
		{
			ans=x;
		}
	}
	printf("%d\n",ans);
	return 0;
}