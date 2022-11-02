#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<queue>
#include<vector>
#include<map>
#include<cmath>
#include<set>
#include<iostream>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;i++)
#define pb push_back
#define mp make_pair
int cal(unsigned long long x)
{
	int ans=0;
	for(;x;x/=10)ans+=x%10;
	return ans;
}
int main()
{
	int T;
	for(scanf("%d",&T);T--;)
	{
		unsigned long long n;int s;
		scanf("%llu%d",&n,&s);
		unsigned long long pw=1,ans=0;
		for(;cal(n)>s;)
		{
			int tmp=(n/pw)%10;
			if(tmp){n+=(10-tmp)*pw;ans+=(10-tmp)*pw;}
			pw*=10;
		}
		printf("%llu\n",ans);
	}
	return 0;
}