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

const int M=3e5+10;
int n,m;
int k[M],c[M],t[M];

priority_queue<int,vector<int>,greater<int> >q;

signed main()
{
	WT
	{
		n=read(),m=read();while(!q.empty())q.pop();int ans=0;
		for (int i=1;i<=m;i++)t[i]=0;
		for (int i=1;i<=n;i++)k[i]=read(),t[k[i]]++;
		for (int i=1;i<=m;i++)c[i]=read();
		sort(k+1,k+1+n);int l=1;
		for (int i=1;i<=n;i++)
		{
			while(l<=k[i])
			{
				for (int j=1;j<=t[l]+1;j++)
					q.push(c[l]);
				l++;
			}
			ans+=q.top();q.pop();
		}cout<<ans<<endl;
	}
	return 0;
}