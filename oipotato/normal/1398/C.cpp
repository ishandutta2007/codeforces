#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<queue>
#include<vector>
#include<map>
#include<cmath>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;i++)
#define pb push_back
#define mp make_pair
map<int,int>cnt;
char s[100010];
int main()
{
	int T;
	for(scanf("%d",&T);T--;)
	{
		cnt.clear();
		cnt[0]++;
		int n;
		scanf("%d",&n);
		scanf("%s",s+1);
		int sum=0;
		long long ans=0;
		rep(i,n)
		{
			int x=s[i]-'0';
			sum+=x;
			ans+=cnt[sum-i];
			cnt[sum-i]++;
		}
		printf("%lld\n",ans);
	}
    return 0;
}