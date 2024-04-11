#include<bits/stdc++.h>
using namespace std;
int n,q;
int a[100005];
int flag2=0,flag4=0,flag6=0,flag8=0;
int main()
{
	cin >> n;
	for (int i=1;i<=n;i++)
	{
		int x;
		cin >> x;
		a[x]++;
		if (a[x]==2) flag2++;
		if (a[x]==4) flag4++;
		if (a[x]==6) flag6++;
		if (a[x]==8) flag8++;
	}
	cin >> q;
	while (q--)
	{
		char x;
		int y;
		cin >> x >> y;
		if (x=='+') 
		{
			a[y]++;
			if (a[y]==2) flag2++;
			if (a[y]==4) flag4++;
			if (a[y]==6) flag6++;
			if (a[y]==8) flag8++;
		}
		else
		{
			if (a[y]==2) flag2--;
			if (a[y]==4) flag4--;
			if (a[y]==6) flag6--;
			if (a[y]==8) flag8--;
			a[y]--;
		}
		if (flag8!=0)
		{
			cout << "YES" << endl;
		}
		else if (flag6!=0)
		{
			if (flag2>=2) cout << "YES" << endl;
			else cout << "NO" << endl;
		}
		else if (flag4==0) cout << "NO" << endl;
		else if (flag4<2&&flag2<3) cout << "NO" << endl;
		else cout << "YES" << endl;
	 } 
	return 0;
}