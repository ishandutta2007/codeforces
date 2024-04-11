#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<queue>
#include<set>
#include<map>
#include<cassert>
#include<iostream>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;i++)
#define pb push_back
#define mp make_pair
#define hash hsh
typedef long long LL;
int a[100010];
char s[100010];
int main()
{
	int T;
	for(scanf("%d",&T);T--;)
	{
		int n,k;
		scanf("%d%d",&n,&k);
		scanf("%s",s+1);
		int sum=0,cnt=0;
		rep(i,n)
		{
			int j=i;
			for(;j<=n&&s[j]==s[i];j++);
			if(s[i]=='W')sum+=2*(j-i)-1;
			else if(i!=1&&j!=n+1)a[++cnt]=j-i;
			i=j-1;
		}
		if(!sum&&k)sum++,k--;
		sort(a+1,a+cnt+1);
		rep(i,cnt)if(k>=a[i])k-=a[i],sum+=2*a[i]+1;
		printf("%d\n",min(2*n-1,sum+2*k));
	}
    return 0;
}