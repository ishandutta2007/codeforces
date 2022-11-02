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
int a[100010],ans[100010],n,m;
bool vis[100010];
int main()
{
	scanf("%d%d",&n,&m);
	rep(i,n)scanf("%d",&a[i]);
	int cnt=0;
	for(int i=n;i;i--)
	{
		if(!vis[a[i]])cnt++;
		ans[i]=cnt;vis[a[i]]=1;
	}
	rep(i,m){int x;scanf("%d",&x);printf("%d\n",ans[x]);}
    return 0;
}