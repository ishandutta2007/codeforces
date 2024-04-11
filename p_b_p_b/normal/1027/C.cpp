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
long long a[1010001];
int cnt[10101];
int main()
{
	int T,n;
	read>>T;
	while (T--)
	{
		read>>n;
		int i,j,k,x,y,z,mx1,mx2;
		long double mx=INT_MAX;
		for (i=1;i<=n;i++) read>>a[i],cnt[a[i]]++;
		sort(a+1,a+n+1);
		for (i=1,j=0;i<=n;i+=cnt[a[i]])
		{
			if (cnt[a[i]]>=4)
			{
				j=a[i];
				long double cur=4ll*(a[i]+j)*(a[i]+j);
				cur/=1ll*a[i]*j;
				if (cur<mx){mx=cur;mx1=a[i];mx2=j;}
				continue;
			}
			if (!j)
			{
				if (cnt[a[i]]>=2) j=a[i];
				continue;
			}
			if (cnt[a[i]]>=2)
			{
				long double cur=4ll*(a[i]+j)*(a[i]+j);
				cur/=1ll*a[i]*j;
				if (cur<mx){mx=cur;mx1=a[i];mx2=j;}
				j=a[i];
			}
		}
		printf("%d %d %d %d\n",mx1,mx1,mx2,mx2);
		for (i=1;i<=n;i++) cnt[a[i]]=0,a[i]=0;
	}
}