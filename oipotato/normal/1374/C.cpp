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
char s[110];
int main()
{
	int T;
	for(scanf("%d",&T);T--;)
	{
		int n,ans=0,now=0;
		scanf("%d%s",&n,s+1);
		rep(i,n)
		{
			if(s[i]=='(')now++;else now--;
			ans=max(ans,-now);
		}
		printf("%d\n",ans);
	}
    return 0;
}