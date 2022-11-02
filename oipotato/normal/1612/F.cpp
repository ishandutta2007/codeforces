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
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
const int N=200010;
int tans,ans,n,m,q,f1[N],f2[N],f[30][N];
pair<int,int>p[N];
bool check(int x,int y)
{
	int t=lower_bound(p+1,p+q+1,mp(x,y))-p;
	return p[t]==mp(x,y);
}
void update(int&x,int y){x=max(x,y);}
int main()
{
	scanf("%d%d",&n,&m);
	scanf("%d",&q);
	rep(i,q)scanf("%d%d",&p[i].first,&p[i].second);
	sort(p+1,p+q+1);
	for(int i=m-1;i;i--)
	{
		int nxt=n+i;
		if(check(n,i))nxt++;
		f1[i]=f1[min(m,nxt)]+1;
	}
	for(int i=n-1;i;i--)
	{
		int nxt=m+i;
		if(check(i,m))nxt++;
		f2[i]=f2[min(n,nxt)]+1;
	}
	ans=n+m;
	f[0][1]=1;
	for(int i=0;i<29;i++)
	rep(j,n)if(f[i][j])
	{
		int nxt=j+f[i][j]+check(j,f[i][j]);
		update(f[i+1][min(nxt,n)],f[i][j]);
		update(f[i+1][j],min(nxt,m));
	}
	rep(i,29)
	{
		if(f[i][n])ans=min(ans,i+f1[f[i][n]]);
		rep(j,n)if(f[i][j]==m)ans=min(ans,i+f2[j]);
	}
	printf("%d\n",ans);
    return 0;
}