#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
 
const int M=1005;
map<int,int>t;
int T,n,s,k,a[M];
 
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		memset(a,0,sizeof(a));
		t.clear();
		scanf("%d%d%d",&n,&s,&k);
		for (int i=1;i<=k;i++)
			scanf("%d",&a[i]),t[a[i]]=1;
		for (int i=0;i<=n;i++)
		{
			if (s-i>0)
			{
				if (!t[s-i])
					{printf("%d\n",i);break;}
			}
			if (s+i<=n)
			{
				if (!t[s+i])
					{printf("%d\n",i);break;}
			}
		}
	}
	return 0;
}