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
int x[1010],y[1010],n;
int main()
{
	scanf("%d",&n);
	rep(i,n)scanf("%d%d",&x[i],&y[i]);
	for(;;)
	{
		int cnt0=0,cnt1=0;
		rep(i,n)
		{
			if((x[i]&1)==(y[i]&1))cnt0++;else cnt1++;
		}
		if(cnt0&&cnt1)
		{
			printf("%d\n",cnt0);
			rep(i,n)if((x[i]&1)==(y[i]&1)){printf("%d",i);cnt0--;if(!cnt0)puts("");else putchar(' ');}
			break;
		}
		if(!cnt0)rep(i,n)x[i]--;else rep(i,n){int a=(x[i]+y[i])/2,b=(x[i]-y[i])/2;x[i]=a;y[i]=b;}
	}
	return 0;
}