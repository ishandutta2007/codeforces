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
		int n,m;scanf("%d%d",&n,&m);
		if((n&1)&&(m&1))rep(i,n){rep(j,m)putchar((i+j)%2?'W':'B');puts("");}
		else
		{
			rep(i,n){rep(j,m)putchar((i+j)%2||i==1&&j==1?'B':'W');puts("");}
		}
	}
    return 0;
}