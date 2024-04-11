#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<iostream>
#include<cassert>
#include<set>
#include<stack>
using namespace std;
#define pb push_back
#define mp make_pair
#define rep(i,n) for(int i=1;i<=n;i++)
int n,k,a[200010],ans;
int main()
{
    scanf("%d%d",&n,&k);
    rep(i,n)scanf("%d",&a[i]);
    sort(a+1,a+n+1,greater<int>());
    int now=0,sum=0;
    for(int i=200000;i>=a[n];i--)
    {
        if(sum+now>k)ans++,sum=0;
        sum+=now;
        for(;now<n&&a[now+1]==i;now++);
    }
    printf("%d\n",ans+(sum>0));
	return 0;
}