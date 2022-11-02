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
	int T;
	for(scanf("%d",&T);T--;)
	{
		int n,m,x,y;scanf("%d%d%d%d",&n,&m,&x,&y);y=min(y,2*x);
		int ans=0;
		rep(i,n)
		{
			char s[1010];
			scanf("%s",s+1);
			rep(j,m)if(s[j]=='.')
			{
				int k=j;
				for(;k<=m&&s[k]=='.';k++);
				ans+=(k-j)/2*y+(k-j)%2*x;
				j=k;
			}
		}
		printf("%d\n",ans);
	}
    return 0;
}