#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<iostream>
#include<cassert>
#include<set>
using namespace std;
#define pb push_back
#define mp make_pair
#define rep(i,n) for(int i=1;i<=n;i++)
int n,a[200010],b[200010];
int main()
{
    scanf("%d",&n);
    rep(i,n){int x;scanf("%d",&x);a[x]=i;}
    int now=0;
    rep(i,n)
    {
        int x;scanf("%d",&x);
        printf("%d%c",max(0,a[x]-now)," \n"[i==n]);
        now=max(now,a[x]);
    }
	return 0;
}