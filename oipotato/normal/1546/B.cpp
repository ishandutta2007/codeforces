#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<cassert>
#include<set>
#include<map>
#include<iostream>
using namespace std;
#define pb push_back
#define mp make_pair
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
int cnt[30],n,m;
vector<int>a[100010],b[100010];
char s[100010];
int main()
{
	int T;
	for(scanf("%d",&T);T--;)
	{
		scanf("%d%d",&n,&m);
		rep(i,n)
		{
			scanf("%s",s);
			a[i].clear();
			rep(j,m)a[i].pb(s[j-1]-'a');
		}
		rep(i,n-1)
		{
			scanf("%s",s);
			b[i].clear();
			rep(j,m)b[i].pb(s[j-1]-'a');
		}
		rep(i,m)
		{
			rep(j,n)cnt[a[j][i-1]]++;
			rep(j,n-1)cnt[b[j][i-1]]--;
			rep(j,26)if(cnt[j-1])cnt[j-1]=0,putchar(j-1+'a');
		}
		puts("");
	}
    return 0;
}