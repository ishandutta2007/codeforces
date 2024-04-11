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
	int n,k,l=0,r;
	scanf("%d%d",&n,&k);
	rep(i,n)
	{
		int x;scanf("%d",&x);
		if(x>k)
		{
			if(!l)l=i;
			r=i;
		}
	}
	printf("%d\n",!l?n:l-1+n-r);
    return 0;
}