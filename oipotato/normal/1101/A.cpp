#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<iostream>
#include<cassert>
#include<set>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;i++)
#define pb push_back
#define mp make_pair
int main()
{
	int T;scanf("%d",&T);
	for(;T--;)
	{
		int l,r,d;
		scanf("%d%d%d",&l,&r,&d);
		if(l>d)printf("%d\n",d);
		else
		{
			int x=r/d*d;
			for(;x<=r;x+=d);
			printf("%d\n",x);
		}
	}
	return 0;
}