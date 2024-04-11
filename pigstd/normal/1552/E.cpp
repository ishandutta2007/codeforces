//AFO countdown:8 Days
#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define WT int TT=read();while(TT--) 
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

const int M=110;
int n,k,a[M*M],vis[M];
vector<int>v[M];
pair<int,int>ans[M];
vector<pair<int,pair<int,int> > >v2;

signed main()
{
	n=read(),k=read();
	for (int i=1;i<=n*k;i++)
		a[i]=read(),v[a[i]].pb(i);
	for (int i=1;i<=n;i+=k-1)
	{
		v2.clear();
		for (int j=i;j<=min(i+k-2,n);j++)
			for (int w=0;w+1<k;w++)
				v2.pb(mp(v[j][w+1],mp(j,v[j][w])));
		sort(v2.begin(),v2.end());int la=0;
		for (int i=0;i<v2.size();i++)
		{
			if (vis[v2[i].y.x])continue;
			if (v2[i].y.y>la)
				la=v2[i].x,ans[v2[i].y.x]=mp(v2[i].y.y,v2[i].x),vis[v2[i].y.x]=1;
		}
	}
	for (int i=1;i<=n;i++)
		cout<<ans[i].x<<' '<<ans[i].y<<endl;
	return 0;
}