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
struct data
{
	int l,r,id;
	bool operator<(const data&a)const{return l<a.l;}
}a[100010];
int ans[100010];
int main()
{
	int T;scanf("%d",&T);
	for(;T--;)
	{
		int n;
		scanf("%d",&n);
		rep(i,n)scanf("%d%d",&a[i].l,&a[i].r),a[i].id=i;
		sort(a+1,a+n+1);
		int now=a[1].l;
		rep(i,n)
		{
			if(a[i].l<=now)now=max(now,a[i].r);
			else
			{
				rep(j,n)ans[a[j].id]=j<i?1:2;
				rep(j,n)printf("%d%c",ans[j]," \n"[j==n]);
				break;
			}
			if(i==n)puts("-1");
		}
	}
	return 0;
}