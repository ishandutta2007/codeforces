#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
int n,m,mx;
ll ans;
void solve(vector<int> a)
{
	int len=a.size();
	if(!len) return;
	sort(a.begin(),a.end());
	for(int i=0;i<len;i++)
	{
//		printf("i=%d,%d,%d\n",i,(i*2ll-len-1),a[i]);
		ans+=1ll*(i*2ll-len+1)*a[i]; 
	}
}
vector<int> val[1000005][2];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			int x;
			scanf("%d",&x);
			val[x][0].push_back(i);
			val[x][1].push_back(j);
			mx=max(mx,x);
		}
	for(int i=1;i<=mx;i++)
	{
		solve(val[i][0]);
		solve(val[i][1]);
	}
	printf("%lld\n",ans);
	return 0;
}