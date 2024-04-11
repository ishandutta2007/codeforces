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
	int n,cnt=0;
	scanf("%d",&n);
	rep(i,n)
	{
		int x,y;scanf("%d%d",&x,&y);
		if(x>y)cnt++;else if(x<y)cnt--;
	}
	if(cnt)puts(cnt>0?"Mishka":"Chris");
	else puts("Friendship is magic!^^");
    return 0;
}