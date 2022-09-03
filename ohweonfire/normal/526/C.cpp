#include <bits/stdc++.h>
using namespace std;
long long c,wr,wb,hr,hb;
int main()
{
	cin>>c>>hr>>hb>>wr>>wb;
	c=c/__gcd(wr,wb)*__gcd(wr,wb);
	if(wr*hb>wb*hr)
	{
		swap(wr,wb);
		swap(hr,hb);
	}
	else if(wr*hb==wb*hr&&wr>wb)
	{
		swap(wr,wb);
		swap(hr,hb);
	}
	long long t=0;
	if(wr>=10000)
	{
		for(int i=0;i*wr<=c;i++)
		{
			long long tt=c-i*wr;
			t=max(t,i*hr+tt/wb*hb);
		}
	}
	else
	{
		for(int i=0;i<=wr&&i*wb<=c;i++)
		{
			long long tt=c-i*wb;
			t=max(t,i*hb+tt/wr*hr);
		}
	}
	cout<<t<<endl;
}