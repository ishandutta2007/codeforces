#include <bits/stdc++.h>

using namespace std;


int n, d, a[100005];
int f[10005][2005];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int t;
	cin >> t;
	while (t--)
	{
		cin >> n;
		memset(f[0], 0x3f, sizeof f[0]);
		int mx=0;
		for (int i = 1; i <= n; ++i)
		{
			memset(f[i], 0x3f, sizeof f[i]);
			cin >> a[i];
			mx=max(mx,a[i]);
		}
		f[0][0]=0;
		for (int i = 0; i <= n; ++i)
		{
			for (int j = 0; j <= 2*mx; ++j)
			{
				int l = a[i+1];
				f[i+1][j+l]=min(f[i+1][j+l],max(f[i][j],j+l));
				if (j - l > 0)
				{
					f[i+1][j-l]=min(f[i+1][j-l],f[i][j]);
				}
				else
				{
					f[i+1][0]=min(f[i+1][0],f[i][j]+l-j);
				}
			}
		}
		int ans=1e9;
		for(int i=0;i<=2000;++i)ans=min(ans,f[n][i]);
		printf("%d\n",ans);
	}

}