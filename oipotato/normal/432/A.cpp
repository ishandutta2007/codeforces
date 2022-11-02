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
	int n,k,ans=0;
	scanf("%d%d",&n,&k);
	rep(i,n)
	{
		int x;
		scanf("%d",&x);
		if(x+k<=5)ans++;
	}
	printf("%d\n",ans/3);
    return 0;
}