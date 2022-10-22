#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define WT int T=read();while(T--) 
#define NO puts("NO");
#define YES puts("YES");
using namespace std;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

const int M=2e5+10;
int n,cnt1,cnt2,v[M],ans[M],vis[M];

bool cmp(int a,int b){return a>b;}

signed main()
{
	WT
	{
		n=read();cnt1=cnt2=0;
		for (int i=2;i*i<=n;i++)
			if (n%i==0)
			{
				v[++cnt1]=i;
				if (n!=i*i)v[++cnt1]=n/i;
			}sort(v+1,v+1+cnt1);
		for (int i=1;i<=cnt1;i++)vis[i]=0;
		ans[++cnt2]=n;int fans=0;
		for (int i=1;i<=cnt1;i++)
		{
			int f=0;
			for (int j=1;j<=cnt1;j++)
			{
				if (vis[j])continue;
				if (__gcd(v[j],ans[cnt2])!=1)
					{ans[++cnt2]=v[j],f=1,vis[j]=1;break;}
			}if (f==0)
			{
				fans++;
				for (int j=cnt1;j>=1;j--)
					if (!vis[i]){ans[++cnt2]=v[j],vis[j]=1;break;}
			}
		}for (int i=1;i<=cnt2;i++)
			cout<<ans[i]<<' ';puts("");
		cout<<fans<<endl;
	}
	return 0;
}