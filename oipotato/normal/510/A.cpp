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
	int n,m;
	scanf("%d%d",&n,&m);
	rep(i,n)
	{
		if(i&1)rep(j,m)putchar('#');
		else
		{
			if(i%4==0)putchar('#');
			rep(j,m-1)putchar('.');
			if(i%4==2)putchar('#');
		}
		puts("");
	}
    return 0;
}