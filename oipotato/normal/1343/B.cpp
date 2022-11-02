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
int a[200010];
int main()
{
	int T;
	for(scanf("%d",&T);T--;)
	{
		int n;scanf("%d",&n);
		rep(i,n/2)a[i]=i*2;
		int now=1;
		for(int i=n/2+1;i<n;i++)a[i]=now,now+=2;
		LL sum=0;
		rep(i,n/2)sum+=a[i];
		for(int i=n/2+1;i<n;i++)sum-=a[i];
		if(sum%2==0)puts("NO");
		else
		{
			a[n]=sum;
			puts("YES");
			rep(i,n)printf("%d%c",a[i]," \n"[i==n]);
		}
	}
    return 0;
}