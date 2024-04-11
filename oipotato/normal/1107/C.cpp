#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<iostream>
#include<cassert>
#include<set>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;i++)
#define pb push_back
#define mp make_pair
long long ans;
int a[200010],n,k;
char st[200010];
int main()
{
	scanf("%d%d",&n,&k);
	rep(i,n)scanf("%d",&a[i]);
	scanf("%s",st+1);
	rep(i,n)
	{
		int j=i;
		for(;j<=n&&st[j]==st[i];j++);
		j--;
		sort(a+i,a+j+1,greater<int>());
		rep(t,min(k,j-i+1))ans+=a[i+t-1];
		i=j;
	}
	printf("%lld\n",ans);
	return 0;
}