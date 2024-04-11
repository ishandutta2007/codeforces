#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<ctime>
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
	int n,last=0,ans=0,now=0;
	scanf("%d",&n);
	rep(i,n)
	{
		int x;scanf("%d",&x);
		if(x>last)now++;else now=1;
		last=x;ans=max(ans,now);
	}
	printf("%d\n",ans);
    return 0;
}