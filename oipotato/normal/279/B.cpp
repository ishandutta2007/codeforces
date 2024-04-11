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
int n,t,a[100010];
int main()
{
	scanf("%d%d",&n,&t);
	rep(i,n)scanf("%d",&a[i]),a[i]+=a[i-1];
	int now=0,ans=0;
	rep(i,n)
	{
		for(;now<n&&a[now+1]-a[i-1]<=t;now++);
		ans=max(ans,now-i+1);
	}
	printf("%d\n",ans);
    return 0;
}