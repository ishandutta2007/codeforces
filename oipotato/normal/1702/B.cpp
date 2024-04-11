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
typedef unsigned long long ULL;
int main()
{
	int T;
	for(scanf("%d",&T);T--;)
	{
		char s[200010];scanf("%s",s+1);
		int n=strlen(s+1);
		int c[27],num=0;
		memset(c,0,sizeof(c));
		int ans=1;
		rep(i,n)
		{
			if(!c[s[i]-'a']&&num==3)ans++,memset(c,0,sizeof(c)),num=0;
			if(!c[s[i]-'a'])num++;
			c[s[i]-'a']=1;
		}
		printf("%d\n",ans);
	}
    return 0;
}