#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<string>
#include<cstring>
#include<queue>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<set>
#include<map>
#include<ctime>
using namespace std;
#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i=1;i<=n;i++)
#define x1 fuckcjb
#define y1 fucksub
#define x2 fuckjtjl
#define y2 fucksf
int a[200010];
int main()
{
	int T;scanf("%d",&T);
	for(;T--;)
	{
		int n;
		scanf("%d",&n);
		rep(i,n)scanf("%d",&a[i]);
		bool flag=0;
		for(int i=1;i<n;i++)
		if(abs(a[i+1]-a[i])>=2)
		{
			puts("YES");
			printf("%d %d\n",i,i+1);
			flag=1;break;
		}
		if(!flag)puts("NO");
	}
	return 0;
}