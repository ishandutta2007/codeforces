#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

typedef long long ll;

ll a,b,f,k,ans;

/*#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=1e3+1e2+7;

int f[101][101][2001],n,t[N],d[N],p[N];

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>t[i]>>d[i]>>p[i];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=i;j++)
}*/

int main()
{
	cin>>a>>b>>f>>k;
	ll cur=b;
	if(k==1)
	if(b<f||b<a-f)
	{
		cout<<-1;
		return 0;
	}
	if(k==1)
	{
		if(b>=a)
			cout<<0;
		else
			cout<<1;
		return 0;
	}
	if(k==2)
	{
		if(b<f||b<(a-f)*2)
		{
			cout<<-1;
			return 0;
		}
		for(int i=0;i<=k-2;++i)
		{
			if(i%2==0)
			{
				if(cur<a*2-f)
				{
					ans++;
					cur=b-a+f;
				}
				else 
					cur-=a;
			}
			else
			{
				if(cur<a+f)
				{
					ans++;
					cur=b-f;
				}
				else 
					cur-=a;
			}
		}
		if(cur<a)
			ans++;
		cout<<ans;
		return 0;
	}
	if(b<2*f||b<(2*(a-f)))
	{
		cout<<-1;
		return 0;
	}
	for(int i=0;i<=k-2;++i)
	{
		if(i&1)
		{
			if(cur<a+f)
			{
				ans++;
				cur=b-f;
			}
			else 
				cur-=a;
		}
		else
		{
			if(cur<a+a-f)
			{
				ans++;
				cur=b-(a-f);
			}
			else 
				cur-=a;
		}
	}
	if(cur<a)
		ans++;
	cout<<ans;
}