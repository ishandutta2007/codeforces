#include<bits/stdc++.h>
using namespace std;
int T,n; 
int a[101];
int main()
{
	cin >> T;
	while (T--)
	{
		memset(a,0,sizeof(a));
		cin >> n;
		for (int i=1;i<=n;i++) 
		{
			int x;
			cin >> x;
			a[i]=x;
		}
		sort(a+1,a+n+1);
		for (int i=2;i<=n;i++)
		{
			if (a[i]!=a[i-1]&&a[i]!=a[i-1]+1)
			{
				cout << "NO" << endl;
				goto yyy;
			}
		}
		cout <<"YES" << endl;
		yyy:;
	}
	return 0;
}