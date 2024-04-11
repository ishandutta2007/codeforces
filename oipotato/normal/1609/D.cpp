#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
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
int c[1010],fa[1010],siz[1010],n,d;
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
int main()
{
	scanf("%d%d",&n,&d);
	rep(i,n)fa[i]=i,siz[i]=1;
	int rest=0;
	rep(i,d)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		int a=find(x),b=find(y);
		if(a==b)rest++;else fa[b]=a,siz[a]+=siz[b];
		int cnt=0;
		rep(j,n)if(find(j)==j)c[++cnt]=siz[j];
		sort(c+1,c+cnt+1,greater<int>());
		int ans=0;
		rep(j,min(rest+1,cnt))ans+=c[j];
		printf("%d\n",ans-1);
	}
    return 0;
}