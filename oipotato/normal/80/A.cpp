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
bool check(int x)
{
	for(int i=2;i<x;i++)if(x%i==0)return 0;
	return 1;
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=n+1;i<=m;i++)if(check(i))
	{
		if(i==m)puts("YES");
		else puts("NO");
		return 0;
	}
	puts("NO");
    return 0;
}