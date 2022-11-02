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
char s[200010];
int main()
{
	int T;
	for(scanf("%d",&T);T--;)
	{
		int last=0,ans=0;scanf("%s",s+1);
		int n=strlen(s+1);
		rep(i,n)if(s[i]=='R')ans=max(ans,i-last),last=i;
		ans=max(ans,n+1-last);
		printf("%d\n",ans);
	}
    return 0;
}