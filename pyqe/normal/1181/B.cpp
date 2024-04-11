#include <bits/stdc++.h>

using namespace std;

string ads(string x,string y)
{
	long long lx=x.length(),ly=y.length(),i,ln=max(lx,ly),kx,ky,k;
	bool ny=false;
	string s="";
	
	for(i=1;i<=ln;i++)
	{
		if(lx<i)
		{
			kx=0;
		}
		else
		{
			kx=x[lx-i]-'0';
		}
		if(ly<i)
		{
			ky=0;
		}
		else
		{
			ky=y[ly-i]-'0';
		}
		k=kx+ky+ny;
		if(k>9)
		{
			ny=true;
		}
		else
		{
			ny=false;
		}
		k%=10;
		s=(char)(k+'0')+s;
	}
	if(ny)
	{
		s="1"+s;
	}
	return s;
}

string mns(string x,string y)
{
	long long lx=x.length(),ly=y.length(),i;
	
	if(lx>ly)
	{
		return y;
	}
	else if(lx<ly)
	{
		return x;
	}
	else
	{
		for(i=0;i<lx;i++)
		{
			if(x[i]>y[i])
			{
				return y;
			}
			else if(x[i]<y[i])
			{
				return x;
			}
		}
	}
	return x;
}

int main()
{
	long long ln,i,p,q;
	string s;
	
	scanf("%lld",&ln);
	cin>>s;
	p=ln/2;
	while(s[p]=='0')
	{
		p--;
	}
	q=(ln-1)/2+1;
	while(q<ln&&s[q]=='0')
	{
		q++;
	}
	printf("%s\n",mns(ads(s.substr(0,p),s.substr(p,ln-p)),ads(s.substr(0,q),s.substr(q,ln-q))).c_str());
}