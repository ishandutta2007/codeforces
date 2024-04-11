#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<queue>
#include<vector>
#include<map>
#include<cmath>
#include<set>
#include<iostream>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;i++)
#define pb push_back
#define mp make_pair
set<int>S;
int ans[10010],n;
int main()
{
	scanf("%d",&n);
	rep(i,n)S.insert(i);
	rep(i,n-1)
	{
		auto it=S.begin();
		int x=*it;it++;
		int y=*it;
		printf("? %d %d\n",x,y);fflush(stdout);
		int a,b;scanf("%d",&a);
		printf("? %d %d\n",y,x);fflush(stdout);
		scanf("%d",&b);
		if(a<b)swap(x,y),swap(a,b);
		ans[x]=a;S.erase(x);
	}
	ans[*S.begin()]=n;
	printf("!");
	rep(i,n)printf(" %d",ans[i]);puts("");fflush(stdout);
	return 0;
}