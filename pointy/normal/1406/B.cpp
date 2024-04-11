#include<bits/stdc++.h>
using namespace std;
int t,n; 
long long a[100005],b[100005],c;
int cnta,cntb;
long long f(int x,int y,int z)
{
	long long res=1;
	if (x==1)
	{
		if (y==1)
		{
			for (int i=1;i<=z;i++) res*=a[i];
			return res;
		}
		else
		{
			for (int i=cnta;i>=cnta-z+1;i--) res*=a[i];
			return res;
		}
	}
	else
	{
		if (y==1)
		{
			for (int i=1;i<=z;i++) res*=b[i];
			return res;
		}
		else
		{
			for (int i=cntb;i>=cntb-z+1;i--) res*=b[i];
			return res;
		}
	}
}
int main()
{
	cin >> t;
	while (t--)
	{
		cin >> n;
		cnta=0,cntb=0,c=0;
		for (int i=1;i<=n;i++) 
		{
			long long x;
			cin >> x;
			if (x>0) a[++cnta]=x;
			else if (x<0) b[++cntb]=x;
			else c++;
		}
		sort(a+1,a+cnta+1);
		sort(b+1,b+cntb+1);
		if (cnta+cntb<5)
		{
			cout << 0 << endl;
			continue;
		}
		long long ans=-1000000000000000000;
		for (int i=0;i<=5;i++)
		{
			int j=5-i;
			if (i>cnta) continue;
			if (j>cntb) continue;
			long long yy;
			if (j%2==1) 
			{
				yy=f(1,1,i)*f(2,2,j);
			}
			else yy=f(1,2,i)*f(2,1,j);
			ans=max(ans,yy);
			//cout << i << " " << j << " " << yy << endl;
		}
		if (c!=0) ans=max(0ll,ans);
		cout << ans << endl;
	}
	return 0;
}