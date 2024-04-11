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
		int n;
		scanf("%d",&n);
		int cnt[2]={0,0};
		rep(i,n)
		{
			int x;scanf("%d",&x);
			cnt[x&1]++;
		}
		cnt[0]&=1;
		if((cnt[0]*2+cnt[1])%2)puts("NO");
		else if(cnt[0])puts(cnt[1]?"YES":"NO");
		else puts("YES");
	}
    return 0;
}