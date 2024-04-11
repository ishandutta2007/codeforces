#include<bits/stdc++.h>
#define sz 101010
#define mod (int)(1e9+7)
using namespace std;
typedef long long ll;
struct FastIO//something
{
    inline FastIO& operator>>(int& x)
	{
        x=0;char f=0,ch=getchar();
        while(ch>'9'||ch<'0') f|=(ch=='-'),ch=getchar();
        while(ch<='9'&&ch>='0') x=x*10+ch-48,ch=getchar();
        return x=(f?-x:x),*this;
    }
    inline FastIO& operator>>(ll& x)
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
			while(ch<='9'&&ch>='0') x+=d*(ch^48),d*=0.1,ch=getchar();
        }
        return x=(f?-x:x),*this;
    }
}read;
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
ll l[sz],r[sz];//something
ll n,K;
ll ksm(ll x,int y)
{
	ll ret;
	for (ret=1;y;y>>=1,x=x*x) if (y&1) ret=ret*x;
	return ret;
}
int main()
{
	ll T,i;//something
	for (i=1;i<=32;i++) l[i]=l[i-1]+ksm(2,i)-1,r[i]=r[i-1]*4ll+1ll;
	read>>T;//something
	while (T--)
	{//something
		read>>n>>K;//something
		if (n>=32ll) printf("YES %I64d\n",K==0?n:n-1);
		else//something
		{//something
			for (i=0;i<=n;i++)
				if (l[n-i]<=K&&r[n]-(2ll*ksm(2,n-i)-1)*r[i]>=K) 
					{ printf("YES %I64d\n",i); break; }
			if (i>n) puts("NO");
		}//something
	}//something
}//something