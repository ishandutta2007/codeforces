#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mem(x) memset(x,0,sizeof(x))

const int N=200005;
int n,m,T; 
ll a[N],s[N];

inline int read()
{
	char C=getchar();
	int F=1,ANS=0;
	while (C<'0'||C>'9')
	{
		if (C=='-') F=-1;
		C=getchar();
	}
	while (C>='0'&&C<='9')
	{
		ANS=ANS*10+C-'0';
		C=getchar();
	}
	return F*ANS;
} 
int find(int x)
{
	int l=1,r=n;
	while (l<=r)
	{
		int mid=(l+r)/2;
		if (s[mid]<x) l=mid+1;
		else r=mid-1;
	}
	return l;
}
void work()
{
	n=read(),m=read();
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	ll p=s[n];
	for (int i=2;i<=n;i++) s[i]=max(s[i-1],s[i]);
	//for (int i=1;i<=n;i++) cout << s[i] << " ";
	//cout << endl;
	while (m--)
	{
		ll x=read();
		if (p<=0)
		{
			if (s[n]<x) 
			{
				cout << -1 << " ";
			}
			else cout << find(x)-1 << " ";
		}
		else
		{
			ll ans=0;
			if (x<=s[n]) 
			{
				cout << find(x)-1 << " ";
			}
			else
			{
				ll w=x-s[n];
				ll o=(w+p-1)/p;
				ans=o*n;
				cout << ans+find(x-o*p)-1 << " ";		
			}
			
		}
		
	}
	cout << endl;
	return;
}

int main()
{
	T=read();
	while (T--)
	{
		work();
	}
	return 0;
}