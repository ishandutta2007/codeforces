#include<bits/stdc++.h>
using namespace std;
int n,m; 
long long a[200005];
long long ans=0;
long long b[200005];
int main()
{
	cin >> n >> m;
	for (int i=1;i<=n;i++) cin >> a[i];
	sort(a+1,a+n+1);
	for (int i=1;i<=m;i++)
	{
		int x,y;
		cin >> x >> y;
		b[x]++,b[y+1]--;
	}
	for (int i=1;i<=n;i++) 
	{
		b[i]+=b[i-1];
	}
	sort(b+1,b+n+1);
	for (int i=1;i<=n;i++) ans+=b[i]*a[i];
	cout << ans;
 	return 0;
}