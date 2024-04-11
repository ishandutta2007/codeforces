#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
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
int n,u[M],s[M],ans[M],len[M];
vector<int>v[M],sum[M];

bool cmp(int a,int b){return a>b;}

signed main()
{
	WT
	{
		n=read();
		for (int i=1;i<=n;i++)u[i]=read(),ans[i]=0,v[i].clear(),sum[i].clear();
		for (int i=1;i<=n;i++)s[i]=read(),v[u[i]].pb(s[i]);
		for (int i=1;i<=n;i++)
			if (v[i].size())
			{
				len[i]=v[i].size();
				sort(v[i].begin(),v[i].end(),cmp);
				sum[i].pb(0);
				for (int j=1;j<=len[i];j++)
					sum[i].pb(sum[i][j-1]+v[i][j-1]);
			}
		for (int i=1;i<=n;i++)
			if (v[i].size())
				for (int j=1;j<=len[i];j++)
					ans[j]+=sum[i][len[i]/j*j];
		for (int i=1;i<=n;i++)
			cout<<ans[i]<<' ';
		puts("");
	}
	return 0;
}