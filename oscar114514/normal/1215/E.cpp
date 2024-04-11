#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[455555],cnt[23],tot[23],nxd[23][23];
long long f[1111111];
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];tot[a[i]]++;
	}
	for(int i=1;i<=n;i++)
	{
		cnt[a[i]]++;
		for(int j=1;j<=20;j++)
		{
//			cerr<<i<<' '<<j<<' '<<cnt[j]<<' '<<tot[j]<<endl;
			nxd[j][a[i]]+=tot[j]-cnt[j];
			nxd[a[i]][j]+=cnt[j];
		}
	}
	for(int i=1;i<=20;i++)for(int j=1;j<=20;j++)nxd[i][j]/=2;
//	for(int i=1;i<=5;i++)for(int j=1;j<=5;j++)cout<<i<<' '<<j<<' '<<nxd[i][j]<<endl;
	memset(f,0x3f,sizeof(f));
	f[0]=0;
	for(int b=0;b<(1<<20)-1;b++)
	{
		for(int i=0;i<20;i++)
		{
			if((1<<i)&b)continue;
			long long tmp=f[b];
			for(int j=0;j<20;j++)
			{
				if((1<<j)&b)
				{
					tmp+=nxd[j+1][i+1];
				}
			}
			f[b|(1<<i)]=min(f[b|(1<<i)],tmp);
		}
	}
	cout<<f[(1<<20)-1]<<endl;
	return 0;
}