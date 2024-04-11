#include<bits/stdc++.h>
using namespace std;
int n; 
int a[101][3];
int p[101];
int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		cin >> n;
		for (int i=1;i<=n;i++) cin >> a[i][0];
		for (int i=1;i<=n;i++) cin >> a[i][1];
		for (int i=1;i<=n;i++) cin >> a[i][2];
		p[1]=a[1][0];
		for (int i=2;i<=n;i++)
		{
			if (i!=n)
			{
				for (int k=0;k<=2;k++) if (a[i][k]!=p[i-1]) p[i]=a[i][k];
			}
			else
			{
				for (int k=0;k<=2;k++) if (a[i][k]!=p[i-1]&&a[i][k]!=p[1]) p[i]=a[i][k];
			}
		}
		for (int i=1;i<=n;i++) cout << p[i] << " ";
		cout << endl;
	}
	return 0;
}