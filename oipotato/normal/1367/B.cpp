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
	int T;
	for(scanf("%d",&T);T--;)
	{
		int cnt[2]={0,0},n;
		int num=0;
		scanf("%d",&n);
		rep(i,n)
		{
			int x;scanf("%d",&x);x^=1;
			cnt[x&1]++;
			if((x&1)!=(i&1))num++;
		}
		if(cnt[0]==n/2&&cnt[1]==(n+1)/2)printf("%d\n",num/2);else puts("-1");
	}
    return 0;
}