#include<bits/stdc++.h>
#defin\
e q\
aq f\
or
using namespace std;

const int M=15;
int f[M][M],n,ans=-1000000;

int main()
{
	cin>>n;
	qaq (int i=1;i<=n;i++)qaq (int j=1;j<=n;j++)cin>>f[i][j];
	qaq (int k=1;k<=n;k++)qaq (int i=1;i<=n;i++)qaq (int j=1;j<=n;j++)
		f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	qaq (int i=1;i<=n;i++)qaq (int j=1;j<=n;j++)ans=max(ans,f[i][j]);
	cout<<ans;
	return 0;
}