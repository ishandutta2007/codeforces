#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 1000007
#define INF63 1061109567
#define INF127 9187201950435737471
#define F first
#define S second
#define ll long long
using namespace std;
int main(){
	int t,a,b,c,ans,x,y,z;
	cin>>t;
	while(t--)
	{
		ans=0;
		cin>>x>>y>>z;
		if(x>y)
		{
			if(z>x)
			{
				a=z;
				b=x;
				c=y;
			}
			else if(z>y)
			{
				a=x;
				b=z;
				c=y;
			}
			else
			{
				a=x;
				b=y;
				c=z;
			}
		}
		else
		{
			if(z>y)
			{
				a=z;
				b=y;
				c=x;
			}
			else if(z>x)
			{
				a=y;
				b=z;
				c=x;
			}
			else
			{
				a=y;
				b=x;
				c=z;
			}
		}
		if(a>0)
		{
			a--;
			ans++;
		}
		if(b>0)
		{
			b--;
			ans++;
		}
		if(c>0)
		{
			c--;
			ans++;
		}
		if(a>0&&b>0)
		{
			a--;
			b--;
			ans++;
		} 
		if(a>0&&c>0)
		{
			a--;
			c--;
			ans++;
		}
		if(b>0&&c>0)
		{
			b--;
			c--;
			ans++;
		}
		if(a>0&&b>0&&c>0)
		{
			a--;
			b--;
			c--;
			ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}