#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,i,j,k,t,t1,u,v,a,b,cur,dir,len,iter;
ll arr[200001];
map<ll,ll> br;
vector<ll> po;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for (i=1;i<=n;i++)
	{
		cin>>arr[i];
		br[arr[i]]=i;
		po.push_back(arr[i]);
	}
	po.push_back(-1e18);
	po.push_back(1e18);
	sort(po.begin(),po.end());
	for (i=1;i<=m;i++)
	{
		cin>>cur>>len;
		cur=arr[cur];
		dir=0;
		iter=0;
		while(true)
		{
			iter++;
			if (dir==0)
			{
			auto it=upper_bound(po.begin(),po.end(),cur+len);
			
			it--;
			v=it-po.begin();
			u=lower_bound(po.begin(),po.end(),cur)-po.begin();
			if (((*it)==cur)and(po[u]-po[u-1]>len)) break;
			else 
			{
				if (len-(po[v]-po[u])-(po[v]-po[u-1])<0)
				{
					dir+=(len/(po[v]-po[u]));
					dir%=2;
					len%=po[v]-po[u];
					if (dir==1) cur=po[v];
				}
				else
				{
					dir++;
					dir%=2;
					len-=po[v]-po[u];
					if (dir==1) cur=po[v];
				}
			}
			}
			else
			{
			auto it=lower_bound(po.begin(),po.end(),cur-len);
			
			u=it-po.begin();
			v=lower_bound(po.begin(),po.end(),cur)-po.begin();
			if (((*it)==cur)and(po[v+1]-po[v]>len)) break;
			else 
			{
				if (len-(po[v]-po[u])-(po[v+1]-po[u])<0)
				{
					dir+=(len/(po[v]-po[u]));
					dir%=2;
					len%=po[v]-po[u];
					if (dir==0) cur=po[u];
				}
				else
				{
					dir++;
					dir%=2;
					len-=po[v]-po[u];
					if (dir==0) cur=po[u];
				}
			}
			}
			
			}
			cout<<br[cur]<<endl;
		}
}