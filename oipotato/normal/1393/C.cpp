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
int cnt[200010];
int main()
{
	int T;
	for(scanf("%d",&T);T--;)
	{
		int n;scanf("%d",&n);
		rep(i,n)cnt[i]=0;
		rep(i,n){int x;scanf("%d",&x);cnt[x]++;}
		sort(cnt+1,cnt+n+1,greater<int>());
		int num=1;
		for(;num<=n&&cnt[num+1]==cnt[1];num++);
		printf("%d\n",num-1+(n-cnt[1]*num)/(cnt[1]-1));
	}
	return 0;
}