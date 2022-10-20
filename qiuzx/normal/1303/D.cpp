#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 1000007
#define INF63 1061109567
#define INF127 9187201950435737471
#define F first
#define S second
#define ll long long
using namespace std;
ll n,m,hv[70];
int main(){
	ll t,i,j,k,x,ans,sum;
	scanf("%I64d",&t);
	while(t--)
	{
		scanf("%I64d%I64d",&n,&m);
		ans=0;
		sum=0;
		memset(hv,0,sizeof(hv));
		for(i=0;i<m;i++)
		{
			scanf("%I64d",&x);
			sum+=x;
			for(j=0;j<=60;j++)
			{
				if((x&((ll)1<<j))!=0)
				{
					hv[j]++;
					break;
				}
			}
		}
		if(sum<n)
		{
			cout<<-1<<endl;
			continue;
		}
		for(i=0;i<=60;i++)
		{
			if(n==0)
			{
				break;
			}
			if((n&((ll)1<<i))!=0)
			{
				if(hv[i]==0)
				{
					for(j=i+1;j<=60;j++)
					{
						if(hv[j]!=0)
						{
							hv[j]--;
							for(k=j-1;k>=i;k--)
							{
								ans++;
								hv[k]++;
							}
							break;
						}
					}
				}
				hv[i]--;
			}
			hv[i+1]+=hv[i]/2;
		}
		cout<<ans<<endl;
	}
	return 0;
}