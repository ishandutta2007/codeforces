#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<queue>
#include<vector>
#include<map>
#include<cmath>
#include<set>
#include<iostream>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;i++)
#define pb push_back
#define mp make_pair
int main()
{
	int T;
	for(scanf("%d",&T);T--;)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		if(l*2>r)puts("-1 -1");else printf("%d %d\n",l,l*2);
	}
	return 0;
}