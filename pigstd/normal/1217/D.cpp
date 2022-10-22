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

const int M=5010;
int n,m,u[M],v[M],in[M];
vector<int>e[M];
queue<int>q;

signed main()
{
	n=read(),m=read();
	for (int i=1;i<=m;i++)
	{
		u[i]=read(),v[i]=read();
		e[u[i]].pb(v[i]);in[v[i]]++;
	}int cnt=0;
	for (int i=1;i<=n;i++)
		if (in[i]==0)q.push(i),cnt++;
	while(!q.empty())
	{
		int u=q.front();q.pop();
		for (int i=0;i<e[u].size();i++)
		{
			int to=e[u][i];in[to]--;
			if (in[to]==0)cnt++,q.push(to);
		}
	}
	if (cnt==n)
	{
		cout<<1<<endl;
		for (int i=1;i<=m;i++)cout<<1<<' ';
		return 0;
	}
	cout<<2<<endl;
	for (int i=1;i<=m;i++)
		if (u[i]>v[i])cout<<1<<' ';
		else cout<<2<<' ';
	return 0;
}