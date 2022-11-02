#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<queue>
#include<set>
#include<map>
#include<cassert>
#include<iostream>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;i++)
#define pb push_back
#define mp make_pair
#define hash hsh
typedef long long LL;
int a[110],n;
vector<int>tmp;
vector<vector<int>>ans;
void work(const vector<int>&v)
{
	int now=1;
	for(const auto&i:v)reverse(a+now,a+now+i),now+=i;
	reverse(a+1,a+n+1);
}
int main()
{
	scanf("%d",&n);
	rep(i,n)scanf("%d",&a[i]);
	rep(i,n-1)
	{
		tmp.clear();
		rep(j,i-1)tmp.pb(1);
		if(i&1)
		{
			for(int j=n-i+1;j;j--)
			if(a[j]==i)
			{
				tmp.pb(n-i+1-j+1);
				if(j!=1)tmp.pb(j-1);
			}
			reverse(tmp.begin(),tmp.end());
		}
		else
		{
			for(int j=i;j<=n;j++)
			if(a[j]==i)
			{
				tmp.pb(j-i+1);
				if(j!=n)tmp.pb(n-j);
			}
		}
		if(tmp.size()>1)
		{
			ans.pb(tmp);
			work(tmp);
		}
	}
	if(a[1]!=1)
	{
		tmp.clear();
		rep(i,n)tmp.pb(1);
		ans.pb(tmp);
		work(tmp);
	}
	printf("%d\n",(int)ans.size());
	for(const auto&i:ans)
	{
		printf("%d",(int)i.size());
		for(const auto&j:i)printf(" %d",j);
		printf("\n");
	}
    return 0;
}