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
int a[100010];
int main()
{
	int n;
	scanf("%d",&n);
	int mx=0;
	rep(i,n){scanf("%d",&a[i]);mx=max(mx,a[i]);}
	int now=0,ans=0;
	rep(i,n)if(a[i]==mx)now++,ans=max(ans,now);else now=0;
	printf("%d\n",ans);
	return 0;
}