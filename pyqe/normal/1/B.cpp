#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long n,r,i,ln,a,b,u;
	bool g;
	string s,t;
	
	scanf("%lld",&n);
	for(r=0;r<n;r++)
	{
		cin>>s;
		ln=s.length();
		u=0;
		g=true;
		t="";
		a=0;
		b=0;
		for(i=0;i<ln;i++)
		{
			if(u==0)
			{
				if(s[i]>='0'&&s[i]<='9')
				{
					u=1;
				}
				else
				{
					t=t+s[i];
				}
			}
			if(u==1)
			{
				if(s[i]>='A'&&s[i]<='Z')
				{
					g=false;
					u=2;
				}
				else
				{
					a*=10;
					a+=s[i]-48;
				}
			}
			if(u==2)
			{
				if(s[i]>='0'&&s[i]<='9')
				{
					u=3;
				}
			}
			if(u==3)
			{
				b*=10;
				b+=s[i]-48;
			}
		}
		if(g)
		{
			ln=t.length();
			for(i=0;i<ln;i++)
			{
				b*=26;
				b+=s[i]-64;
			}
			printf("R%lldC%lld\n",a,b);
		}
		else
		{
			t="";
			while(b>0)
			{
				b-=1;
				t=(char)(b%26+65)+t;
				b/=26;
			}
			printf("%s%lld\n",t.c_str(),a);
		}
	}
}