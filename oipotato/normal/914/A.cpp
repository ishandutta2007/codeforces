#include<cstdio>
#include<iostream>
#include<cmath>
#include<cassert>
#include<cstdlib>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<vector>
using namespace std;
#define pb push_back
#define x0 fuckcjb
#define x1 fuckshb
#define y0 fucksub
#define y1 fuckjtjl
bool check(int x)
{
	int p=sqrt(x);
	return p*p==x;
}
int main()
{
	int n,ans;
	scanf("%d",&n);
	ans=-1000001;
	for(int i=1;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		if(x<0||!check(x))
		{
			ans=max(ans,x);
		}
	}
	printf("%d\n",ans);
	return 0;
}