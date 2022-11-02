#include <iostream>
#include <cmath>
using namespace std;
long long x,y,s,ans,p,a[1000];
int len,q,b[1000],tot;
int main()
{
	cin>>x>>y;
	len=(int)sqrt(x);
	for(int i=2;i<=len;i++)
		if(x%i==0)
		{
			a[++tot]=i;
			for(;x%i==0;x/=i)
				b[tot]++;
		}
	if(x)
	{
		a[++tot]=x;
		b[tot]=1;
		x=1;
	}
	for(;;)
	{
		q=-1;
		p=y;
		for(int i=1;i<=tot;i++)
			if(b[i]&&y-y/a[i]*a[i]<p)
			{
				q=i;
				p=y-y/a[i]*a[i];
			}
		if(q==-1)
			break;
		ans+=p;
		y/=a[q];
		b[q]--;
	}
	cout<<ans+y<<endl;
	return 0;
}