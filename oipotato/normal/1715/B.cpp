#include<bits/stdc++.h>
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
		LL n,k,b,s;
		scanf("%lld%lld%lld%lld",&n,&k,&b,&s);
		if(b*k<=s&&s<=b*k+n*(k-1))
		{
			LL rest=s-b*k;
			rep(i,n)
			{
				LL tmp=min(rest,k-1);
				rest-=tmp;
				if(i==n)tmp+=b*k;
				printf("%lld%c",tmp," \n"[i==n]);
			}
		}
		else puts("-1");
	}
    return 0;
}