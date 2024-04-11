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
int main()
{
	int T;
	for(scanf("%d",&T);T--;)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		if(a==b)puts("0");
		else if(a>b)
		{
			if((a-b)%2==0)puts("1");
			else puts("2");
		}
		else
		{
			if((b-a)%2==1)puts("1");
			else puts("2");
		}
	}
    return 0;
}