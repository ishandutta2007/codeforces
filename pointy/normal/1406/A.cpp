#include<bits/stdc++.h>
using namespace std;
int t,n; 
int a[100005];
int main()
{
	cin >> t;
	while (t--)
	{
		cin >> n;
		for (int i=0;i<=101;i++) a[i]=0;
		for (int i=1;i<=n;i++)
		{
			int x;
			cin >> x;
			a[x]++;
		 } 
		int ansx=-1,ansy=-1;
		for (int i=0;i<=101;i++)
		{
			if (a[i]<2&&ansx==-1) ansx=i;
			if (a[i]<1&&ansy==-1) ansy=i;
		}
		cout << ansx+ansy << endl;
	}
	return 0;
}