#include<bits/stdc++.h>
#define int long long
using namespace std;

int T;
int l,r,m;

signed main()
{
	cin>>T;
	while(T--)
	{
		cin>>l>>r>>m;
		int b,c;
		bool flag=1;
		for (int a=l;a<=r;a++)
		{
			int n=m/a;
			if (n==0)n=1;
			int k=m-a*n;
			if (k<0)
				c=r,b=c+k;
			else
				b=r,c=b-k;
			if (b<=r&&b>=l&&c<=r&&c>=l)
				{cout<<a<<' '<<b<<' '<<c<<endl;flag=0;break;}
		}
		if (!flag)
			continue;
		for (int a=l;a<=r;a++)
		{
			int n=m/a+1;
			if (n==0)n=1;
			int k=m-a*n;
			if (k<0)
				c=r,b=c+k;
			else
				b=r,c=b-k;
			if (b<=r&&b>=l&&c<=r&&c>=l)
				{cout<<a<<' '<<b<<' '<<c<<endl;break;}
		}
	}
	return 0;
}