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
		scanf("%s",s+1);int n=strlen(s+1);
		int ans=n+1,now=0,cnt=0,num[3]={0,0,0};
		rep(i,n)
		{
			for(;now<n&&cnt<3;)
			{
				now++;
				int x=s[now]-'0'-1;
				num[x]++;
				if(num[x]==1)cnt++;
			}
			if(cnt==3)ans=min(ans,now-i+1);else break;
			int x=s[i]-'0'-1;
			num[x]--;
			if(!num[x])cnt--;
		}
		printf("%d\n",ans==n+1?0:ans);
	}
    return 0;
}