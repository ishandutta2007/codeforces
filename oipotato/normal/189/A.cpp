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
	int ans=0;
	int n,a,b,c;
	scanf("%d%d%d%d",&n,&a,&b,&c);
	for(int i=0;i<=n;i++)
	{
		if(i*a>n)break;
		for(int j=0;j<=n;j++)
		{
			if(i*a+j*b>n)break;
			int x=n-i*a-j*b;
			if(x%c)continue;
			x/=c;
			ans=max(ans,i+j+x);
		}
	}
	printf("%d\n",ans);
    return 0;
}