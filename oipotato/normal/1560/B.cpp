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
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		if(a>b)swap(a,b);
		if(a-1>b-a-1)puts("-1");
		else
		{
			int n=2*(b-a);
			if(c>n)puts("-1");
			else printf("%d\n",c>n/2?c-n/2:c+n/2);
		}
	}
    return 0;
}