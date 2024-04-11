#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

typedef long long ll;

const int N=2e2+1e1+7;

ll n,k;

ll a[N],f[2][N][8001],u[N],v[N],ans;

int main()
{
	cin>>n>>k;
	n++,n--;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		while(a[i]%2==0)
			a[i]/=2,u[i]++;
		while(a[i]%5==0)
			a[i]/=5,v[i]++;
	}
	int cur=0,last=1;
	memset(f[cur],-0x3f,sizeof(f[cur]));
	f[cur][0][0]=0;
	for(int i=1;i<=n;i++)
	{
		swap(cur,last);
		memset(f[cur],-0x3f,sizeof(f[cur]));
		for(int j=0;j<=min((ll)i,k);j++)
			for(int t=8000;t>=0;t--)
			{
				f[cur][j][t]=max(f[cur][j][t],f[last][j][t]);
				if(t>=v[i]&&j)
					f[cur][j][t]=max(f[cur][j][t],f[last][j-1][t-v[i]]+u[i]);
			}
	}
	for(ll t=1;t<=8000;t++)
		ans=max(ans,min(f[cur][k][t],t));
	cout<<ans;
}