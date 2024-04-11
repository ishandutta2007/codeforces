#include<bits/stdc++.h>
using namespace std;
int T,n; 
int a[101],b[101];
long long ans;
int main()
{
	cin >> T;
	while (T--)
	{
		cin >> n;
		int mina=1e9+7,minb=1e9+7;
		ans=0;
		for (int i=1;i<=n;i++) 
		{
			cin >> a[i];
			mina=min(a[i],mina);
		}
		for (int i=1;i<=n;i++) 
		{
			cin >> b[i];
			minb=min(b[i],minb);
		}
		for (int i=1;i<=n;i++)
		{
			long long xa=a[i]-mina,xb=b[i]-minb;
			ans+=max(xa,xb);
		}
		cout << ans << endl;
	}
	return 0;
}