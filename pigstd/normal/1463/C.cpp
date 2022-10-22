#include<bits/stdc++.h>
#define WT int T=read();while(T--)
#define int long long
#define pb push_back
#define YES puts("YES")
#define NO puts("NO")
using namespace std;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

const int inf=1e18;
const int M=1e5+10;
int n,x[M],t[M];

signed main()
{
	WT
	{
		n=read();int to=0,now=0,ans=0;
		for (int i=1;i<=n;i++)
			t[i]=read(),x[i]=read();t[n+1]=inf;
		for (int i=1;i<=n;i++)
		{
			if (to==now)
			{
				to=x[i];
				int t1=t[i+1]-t[i],t2=abs(now-to);
				if (t1>=t2)
				{
					ans++;now=to;
					continue;
				}
				else
				{
					if (now<to)
						now+=t1;
					else now-=t1;
				}
			}
			else
			{
				if (abs(now-to)<=t[i+1]-t[i])
				{
					if ((x[i]-to)*(now-x[i])>=0)ans++;
					now=to;
				}
				else
				{
					if (now<to)
					{
						if (x[i]>=now&&x[i]<=now+t[i+1]-t[i])ans++;
						now+=t[i+1]-t[i];
					}
					else
					{
						if (x[i]<=now&&x[i]>=now-t[i+1]+t[i])ans++;
						now-=t[i+1]-t[i];
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
/*
3
1 5
2 4
10 -5
*/