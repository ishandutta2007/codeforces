#include<bits/stdc++.h>
using namespace std;
int n,k; 
int a[109];
int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		cin >> n >> k;
		for (int i=1;i<=n;i++) cin >> a[i];
		if (k==1)
		{
			for (int i=2;i<=n;i++)
			{
				if (a[i]!=a[i-1]) 
				{
					cout << -1 << endl;
					goto yy;
				}
			}
			cout << 1 << endl;
			yy:;
			continue; 
		}
		int cnt=1;
		for (int i=2;i<=n;i++) if (a[i]!=a[i-1]) cnt++;
		int ans=(cnt+k-3)/(k-1);
		if (ans==0) ans++;
		cout << ans << endl;
	}
	return 0;
}