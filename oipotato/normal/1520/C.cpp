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
		int n;
		scanf("%d",&n);
		if(n==2)puts("-1");
		else
		{
			int now=1;
			rep(i,n)rep(j,n)printf("%d%c",now," \n"[j==n]),now=now+2<=n*n?now+2:2;
		}
	}
    return 0;
}