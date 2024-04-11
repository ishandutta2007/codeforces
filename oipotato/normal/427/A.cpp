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
	int rest=0,ans=0,n;
	scanf("%d",&n);
	rep(i,n)
	{
		int x;scanf("%d",&x);
		if(x<0)
		{
			if(rest)rest--;else ans++;
		}
		else rest+=x;
	}
	printf("%d\n",ans);
    return 0;
}