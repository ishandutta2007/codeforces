#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<vector>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;i++)
#define pb push_back
#define mp make_pair
const int inf=(int)1e9+10;
vector<pair<int,int>>ans;
long long a[30][30],mx[30][30],mi[30][30];
int main()
{
	int n;
	scanf("%d",&n);
	rep(i,n+n-1)
	{
		if(i<=2)continue;
		rep(x,n)
		{
			if(x==1)continue;
			int y=i-x;
			if(y<1||y>=n)continue;
			a[x][y]=a[x-1][y+1]+mx[x-1][y]-mi[x-1][y]+1;
		}
		rep(x,n)
		{
			int y=i-x;
			if(y<1||y>n)continue;
			mx[x][y]=(y>1?mx[x][y-1]:mx[x-1][y])+a[x][y];
			mi[x][y]=(x>1?mi[x-1][y]:mi[x][y-1])+a[x][y];
		}
	}
	rep(i,n)rep(j,n)printf("%lld%c",a[i][j]," \n"[j==n]);
	fflush(stdout);
	int q;
	scanf("%d",&q);
	rep(i,q)
	{
		long long k;
		scanf("%lld",&k);
		int x=n,y=n;
		ans.clear();
		ans.pb(mp(x,y));
		rep(j,2*n-2)
		{
			k-=a[x][y];
			if(x>1&&mx[x-1][y]>=k)x--;else y--;
			ans.pb(mp(x,y));
		}
		reverse(ans.begin(),ans.end());
		for(auto j:ans)printf("%d %d\n",j.first,j.second);fflush(stdout);
	}
    return 0;
}