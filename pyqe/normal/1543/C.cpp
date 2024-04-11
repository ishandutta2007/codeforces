#include <bits/stdc++.h>

using namespace std;

const long long ml=4e4;
long long d;
array<long long,3> a;
bitset<3> b0;
double z;

long long inp()
{
	long long i,ln,sm;
	string s;
	
	scanf("%lld",&sm);
	cin>>s;
	ln=s.length();
	for(i=1;i<=4;i++)
	{
		sm*=10;
		if(i<ln)
		{
			sm+=s[i]-'0';
		}
	}
	return sm*4;
}

void rk(double cw,array<long long,3> ca,bitset<3> vtd)
{
	long long i,j,c,lb;
	array<long long,3> ca2;
	bitset<3> vtd2;
	
	for(i=0;i<3;i++)
	{
		if(!vtd[i])
		{
			z+=cw*((double)ca[i]/ml);
			if(i!=2)
			{
				ca2=ca;
				vtd2=vtd;
				c=0;
				for(j=0;j<3;j++)
				{
					c+=j!=i&&!vtd[j];
				}
				if(ca2[i]>d)
				{
					lb=ca2[i]-d;
				}
				else
				{
					lb=0;
					vtd2[i]=1;
				}
				for(j=0;j<3;j++)
				{
					if(j!=i&&!vtd[j])
					{
						ca2[j]+=(ca2[i]-lb)/c;
					}
				}
				ca2[i]=lb;
				rk(cw*((double)ca[i]/ml),ca2,vtd2);
			}
		}
	}
}

int main()
{
	long long t,rr,i;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		for(i=0;i<3;i++)
		{
			a[i]=inp();
		}
		d=inp();
		z=0;
		rk(1,a,b0);
		printf("%.20lf\n",z);
	}
}