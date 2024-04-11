#include <iostream>

using namespace std;

int main()
{
	long long a=0,b=0,c=0,d=0,n,k,i;
	
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>k;
		if(k==1)
		{
			a++;
		}
		if(k==2)
		{
			b++;
		}
		if(k==3)
		{
			c++;
		}
		if(k==4)
		{
			d++;
		}
	}
	while(a>0&&c>0)
	{
		a--;
		c--;
		d++;
	}
	while(b>1)
	{
		b-=2;
		d++;
	}
	while(a>1&&b>0)
	{
		a-=2;
		b--;
		d++;
	}
	while(a>3)
	{
		a-=4;
		d++;
	}
	if(b==1)
	{
		a=0;
		b=0;
		d++;
	}
	if(a>0)
	{
		a=0;
		d++;
	}
	d+=c;
	c=0;
	cout<<d<<endl;
}