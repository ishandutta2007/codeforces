#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<vector>
#include<queue>
#include<bitset>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<map>
#include<cassert>
#include<string>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
int main()
{
	int m,s;scanf("%d%d",&m,&s);
	if(s==0)
	{
		if(m==1)puts("0 0");else puts("-1 -1");
	}
	else
	{
		if(s>m*9)puts("-1 -1");
		else
		{
			int ts=s;
			rep(i,m)
			{
				int tmp=max(i==1?1:0,s-9*(m-i));
				s-=tmp;printf("%d",tmp);
			}
			printf(" ");
			s=ts;
			rep(i,m)
			{
				int tmp=min(9,s);
				s-=tmp;printf("%d",tmp);
			}
			printf("\n");
		}
	}
    return 0;
}