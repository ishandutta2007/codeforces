#include<cstdio>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N=2e3+1e2+7;

typedef long long ll;

ll n,k,a[N],b[N],f[N][N],p;

int main()
{
	cin>>n>>k>>p;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=k;i++)
		cin>>b[i];	
	sort(a+1,a+n+1);
	sort(b+1,b+k+1);
	for(int i=0;i<=n;i++)
		for(int j=0;j<=k;j++)
			f[i][j]=0x7fffffffff;
	for(int i=1;i<=k;i++)
		f[1][i]=min(f[1][i],abs(a[1]-b[i])+abs(b[i]-p));
	for(int i=2;i<=n;i++)
		for(int j=1;j<=k;j++)
			f[i][j]=min(f[i][j-1],max(f[i-1][j-1],abs(a[i]-b[j])+abs(b[j]-p)));
	ll ans=0x7fffffffff;
	for(int i=1;i<=k;i++)
		ans=min(ans,f[n][i]);
	cout<<ans;
}