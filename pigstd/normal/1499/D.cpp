#include<bits/stdc++.h>
//#define int long long
//fuck cf
#define pb push_back
using namespace std;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

int T,c,d,x,pcnt;
int p[100000],prime[10000000],ppp[20000010];
bool f[20000010];

signed main()
{
//	freopen("qwq.txt","r",stdin);
//	freopen("233.out","w",stdout);
	T=read();
	memset(ppp,0x3f,sizeof(ppp));
	for (int i=2;i<=2e7;i++)
	{
		if (!f[i])prime[++pcnt]=i,ppp[i]=i;
		for (int j=1;j<=pcnt&&i*prime[j]<=2e7;j++)
		{
			f[i*prime[j]]=1,ppp[i*prime[j]]=min(min(prime[j],ppp[i]),ppp[i*prime[j]]);
			if (i%prime[j]==0)break;
		}
	}
//	for (int i=2;i<=20;i++)cout<<ppp[i]<<' ';
	while(T--)
	{
		c=read(),d=read(),x=read();long long cnt=0,ans=0;
		int g=__gcd(__gcd(c,d),x);c/=g,d/=g,x/=g;
		for (int i=1;i<=sqrt(x);i++)
			if (x%i==0)
			{
				p[++cnt]=i;
				if (x/i!=i)p[++cnt]=x/i;
			}
//		for (int i=1;i<=cnt;i++)cout<<p[i]<<' '; 
		for (int i=1;i<=cnt;i++)
		{
			long long g=p[i];
			long long l=x+d*g;
			if (l%c!=0)continue;l/=c;
			if (l%g!=0)continue;l/=g;int w=0;
			
			while(l!=1)
			{
				if (l==1)break;
				int k=ppp[l];
				while(l%k==0)l/=k;
				w++;
			}
			ans+=1ll<<w;
		}
		printf("%lld\n",ans);
	}
	return 0;
}