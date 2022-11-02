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
int bas[32],cnt;
int main()
{
	int n;
	scanf("%d",&n);
	int now=0;
	rep(i,n)
	{
		int x;scanf("%d",&x);
		now^=x;
		int y=now;
		for(int j=30;j>=0;j--)if(y&(1<<j)){if(!bas[j]){bas[j]=y;cnt++;break;}else y^=bas[j];}
	}
	printf("%d\n",now?cnt:-1);
	return 0;
}