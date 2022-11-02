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
		int n,a[110],k;scanf("%d%d",&n,&k);
		rep(i,n)scanf("%d",&a[i]);
		int now=0;
		rep(i,n-1)
		{
			int tmp=min(a[i],k);
			a[i]-=tmp;k-=tmp;now+=tmp;
		}
		a[n]+=now;
		rep(i,n)printf("%d%c",a[i]," \n"[i==n]);
	}
    return 0;
}