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
bool vis[30010];
int main()
{
	int t,n;
	scanf("%d%d",&n,&t);
	vis[1]=1;
	rep(i,n)
	{
		if(i==t){puts(vis[i]?"YES":"NO");return 0;}
		int x;scanf("%d",&x);
		if(!vis[i])continue;
		vis[i+x]=1;
	}
    return 0;
}