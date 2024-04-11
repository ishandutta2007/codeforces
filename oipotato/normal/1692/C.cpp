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
typedef unsigned long long ULL;
int main()
{
	int T;
	for(scanf("%d",&T);T--;)
	{
		char s[10][10];
		rep(i,8)scanf("%s",s[i]+1);
		int r,c;
		for(int i=2;i<=7;i++)for(int j=2;j<=7;j++)if(s[i][j]=='#'&&s[i-1][j-1]=='#'&&s[i-1][j+1]=='#')r=i,c=j;
		printf("%d %d\n",r,c);
	}
    return 0;
}