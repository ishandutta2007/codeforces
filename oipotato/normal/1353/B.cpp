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
int a[40],b[40];
int main()
{
	int T;
	for(scanf("%d",&T);T--;)
	{
		int n,k;scanf("%d%d",&n,&k);
		rep(i,n)scanf("%d",&a[i]);
		rep(i,n)scanf("%d",&b[i]);
		rep(i,k)
		{
			sort(a+1,a+n+1);
			sort(b+1,b+n+1);
			if(b[n]<=a[1])break;
			swap(a[1],b[n]);
		}
		int sum=0;
		rep(i,n)sum+=a[i];
		printf("%d\n",sum);
	}
    return 0;
}