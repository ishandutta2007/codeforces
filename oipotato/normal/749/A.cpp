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
	int n;scanf("%d",&n);
	if(n&1)
	{
		printf("%d\n3",(n-3)/2+1);
		rep(i,(n-3)/2)printf(" 2");puts("");
	}
	else
	{
		printf("%d\n",n/2);
		rep(i,n/2)printf("2%c"," \n"[i==n/2]);
	}
    return 0;
}