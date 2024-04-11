#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int T,n,b[100005];
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		int bt=0;
		while(n)
		{
			b[++bt]=n%10;
			n/=10;
		}
		int mn=1e9;
		for(int i=1;i<=bt;i++)
			mn=min(mn,b[i]);
		if(bt==2) printf("%d\n",b[1]);
		else printf("%d\n",mn);
	}
	return 0;
}