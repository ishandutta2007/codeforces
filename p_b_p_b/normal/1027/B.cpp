#include<bits/stdc++.h>
using namespace std;
struct FastIO
{
    inline FastIO& operator>>(int& x)
	{
        x=0;char f=0,ch=getchar();
        while(ch>'9'||ch<'0') f|=(ch=='-'),ch=getchar();
        while(ch<='9'&&ch>='0') x=x*10+ch-48,ch=getchar();
        return x=(f?-x:x),*this;
    }
    inline FastIO& operator>>(long long& x)
	{
        x=0;char f=0,ch=getchar();
        while(ch>'9'||ch<'0') f|=(ch=='-'),ch=getchar();
        while(ch<='9'&&ch>='0') x=x*10+ch-48,ch=getchar();
        return x=(f?-x:x),*this;
    }
    inline FastIO& operator>>(double& x)
	{
        x=0;char f=0,ch=getchar();
        double d=0.1;
        while(ch>'9'||ch<'0') f|=(ch=='-'),ch=getchar();
        while(ch<='9'&&ch>='0') x=x*10+ch-48,ch=getchar();
        if(ch=='.')
        {
        	ch=getchar();
			while(ch<='9'&&ch>='0') x+=d*(ch^48),d*=0.1;
        }
        return x=(f?-x:x),*this;
    }
}read;
typedef long long ll;
int main()
{
	ll n,q;
	read>>n>>q;
	while (q--)
	{
		ll x,y,z;
		read>>x>>y;z=x+y;
		if (z%2ll==0)
		{
			if (n%2ll==0) printf("%I64d\n",(x-1)*(n/2)+(y+1)/2);
			else printf("%I64d\n",((x-1)*n+y+1)/2);
		}
		else
		{
			if (n%2ll==0) printf("%I64d\n",(x-1)*(n/2)+(y+1)/2+n*n/2);
			else printf("%I64d\n",((x-1)*n+y)/2+(n*n+1ll)/2);
		}
	}
}