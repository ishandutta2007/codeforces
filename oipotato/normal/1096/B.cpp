#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<iostream>
#include<cassert>
#include<set>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;i++)
#define pb push_back
#define mp make_pair
char s[200010];
int main()
{
	int n;scanf("%d",&n);
	scanf("%s",s+1);
	long long ans=1;
	int now=1;for(;s[now+1]==s[now];now++);
	int l=now;
	ans+=l;
	now=n;for(;s[now-1]==s[now];now--);
	int r=n-now+1;
	ans+=r;
	if(s[1]==s[n])ans+=1ll*l*r;
	printf("%lld\n",ans%998244353);
	return 0;
}