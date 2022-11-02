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
		int n,k;scanf("%d%d",&n,&k);
		if(n%2==1)
		{
			puts(k<=n&&k%2==1?"YES":"NO");
			if(k<=n&&k%2==1)rep(i,k)printf("%d%c",i<k?1:n-k+1," \n"[i==k]);
		}
		else
		{
			puts(2*k<=n||k%2==0&&k<=n?"YES":"NO");
			if(2*k<=n)rep(i,k)printf("%d%c",i<k?2:n-2*k+2," \n"[i==k]);
			else if(k%2==0&&k<=n)rep(i,k)printf("%d%c",i<k?1:n-k+1," \n"[i==k]);
		}
	}
    return 0;
}