#include<bits/stdc++.h>
#define int long long
#define MAXN 5*1e18+10
using namespace std;

const int M=1e5+10;
int n,a[M],k;
int son[M][45],minn[M][45],sum[M][45];
//2^30=1000^3=10^9
//2^40=1000^4=10^12
// 

signed main()
{
	cin>>n>>k;
	for (int i=0;i<n;i++)
		cin>>son[i][0];
	for (int i=0;i<n;i++)
		cin>>a[i],minn[i][0]=sum[i][0]=a[i];
	for (int t=1;t<=40;t++) 
		for (int i=0;i<n;i++)//
			son[i][t]=son[son[i][t-1]][t-1];
	for (int t=1;t<=40;t++)
		for (int i=0;i<n;i++)
			sum[i][t]=sum[i][t-1]+sum[son[i][t-1]][t-1];
	for (int t=1;t<=40;t++)
		for (int i=0;i<n;i++)
			minn[i][t]=min(minn[i][t-1],minn[son[i][t-1]][t-1]);
	for (int i=0;i<n;i++)
	{
		int sums=0,now=0,nnn=i;
		for (int t=40;t>=0;t--)
			if ((1ll<<t)+now<=k)
				now+=1ll<<t,sums+=sum[nnn][t],nnn=son[nnn][t];
		cout<<sums<<' ';
		int Minn=MAXN;
		now=0,nnn=i;
		for (int t=40;t>=0;t--)
			if ((1ll<<t)+now<=k)
				now+=1ll<<t,Minn=min(Minn,minn[nnn][t]),nnn=son[nnn][t];
		cout<<Minn<<endl;
	}
	return 0;
}