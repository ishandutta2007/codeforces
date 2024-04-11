#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;++i)
#define mp make_pair
#define pb push_back
#define x0 gtmsub
#define y0 gtmshb
#define x1 gtmjtjl
#define y1 gtmsf
int a[110][110];
int n,m;
int best=0;
pair<int,int> q[110];
vector<int> ans;
int main()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	for(int j=1;j<=n;j++)
		scanf("%d",&a[i][j]);
		
	best=m;
	ans.clear();
	for(int j=1;j<=m;j++)ans.pb(j);
	
	for(int i=1;i<n;i++)
	{	
		int now1=0,now2=0;
		for(int j=1;j<=m;j++)now1+=a[j][i],now2+=a[j][n];
		
		for(int j=1;j<=m;j++)q[j]=mp(a[j][n]-a[j][i],j);
		sort(q+1,q+m+1);
		reverse(q+1,q+m+1);
		
		if (now1>=now2)
		{
			best=0;
			break;
		}
		
		for(int j=1;j<=m;j++)
		{
			now1-=a[q[j].second][i];
			now2-=a[q[j].second][n];
			if (now1>=now2)
			{
				if (j<best)
				{
					best=j;
					ans.clear();
					for(int k=1;k<=j;k++)ans.pb(q[k].second);
				}
				break;
			}
		}
	}
	printf("%d\n",best);
	for(int i=0;i<best;i++)printf("%d%c",ans[i],i==best-1?'\n':' ');
	return 0;
}