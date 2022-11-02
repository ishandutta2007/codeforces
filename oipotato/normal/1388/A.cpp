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
		int n;
		scanf("%d",&n);
		if(n<=6+10+14)puts("NO");
		else if(n-6-10-14==6||n-6-10-14==10||n-6-10-14==14)printf("YES\n6 10 15 %d\n",n-6-10-15);
		else printf("YES\n6 10 14 %d\n",n-6-10-14);
	}
	return 0;
}