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
	int n,k,a[510];
	scanf("%d%d",&n,&k);
	rep(i,n)scanf("%d",&a[i]);
	int ans=0;
	rep(i,n-1)if(a[i]+a[i+1]<k)ans+=k-a[i]-a[i+1],a[i+1]=k-a[i];
	printf("%d\n",ans);
	rep(i,n)printf("%d%c",a[i]," \n"[i==n]);
    return 0;
}