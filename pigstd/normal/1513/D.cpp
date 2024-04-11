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
int vis[M],n,p,ans,a[M];
struct node
{
	int p,a;
}b[M];
bool cmp(node a,node b){return a.a<b.a;}

signed main()
{
//	freopen("qwq.txt","r",stdin);
//    freopen("2.txt","w",stdout);
	WT
	{
		n=read(),p=read(),ans=(n-1)*p;
		for (int i=1;i<=n;i++)
			a[i]=b[i].a=read(),b[i].p=i;
		sort(b+1,b+1+n,cmp);
		for (int i=1;i<=n;i++)vis[i]=0;
		for (int i=1;i<=n;i++)
		{
			if (vis[b[i].p]||b[i].a>=p)continue;
			int cnt=0;vis[b[i].p]=1;
			for (int j=b[i].p+1;j<=n;j++)
			{
				if (a[j]%b[i].a!=0)break;
				cnt++;if (vis[j])break;vis[j]=1;
			}
			for (int j=b[i].p-1;j>=1;j--)
			{
				if (a[j]%b[i].a!=0)break;
				cnt++;if (vis[j])break;vis[j]=1;
			}
			ans-=cnt*(p-b[i].a);
		}
		printf("%lld\n",ans);
	}
	return 0; 
}
/*
1
4 5
5 2 4 9
*/