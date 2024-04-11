#include<bits/stdc++.h>
//#define int long long
using namespace std;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

const int M=2e5+10;
int T,n,a[M],t[M];

struct graph
{
	struct edge{int to,next;}e[M<<4];int cnt,head[M];
	int out[M],dp[M],sum[M];
	void add(int u,int to){out[to]++,e[++cnt].to=to,e[cnt].next=head[u],head[u]=cnt;}
	void clear(int n)
	{
		for (int i=1;i<=n;i++)head[i]=out[i]=sum[i]=dp[i]=t[a[i]]=0;
		cnt=0;
	}
	int tp()
	{
		queue<int>q;
		for (int i=1;i<=n;i++)
			if (out[i]==0&&t[a[i]]==i)q.push(i),dp[i]=sum[i];
		while(!q.empty())
		{
			int k=q.front();q.pop();
			for (int i=head[k];i;i=e[i].next)
			{
				int to=e[i].to;
				dp[to]=max(dp[to],dp[k]);
				out[to]--;
				if (out[to]==0)
					q.push(to),dp[to]+=sum[to];
			}
		}
		int ans=0;
		for (int i=1;i<=n;i++)ans=max(ans,dp[i]);
		return ans;
	}
}G;

signed main()
{
	T=read();
	while(T--)
	{
		n=read();
		for (int i=1;i<=n;i++)
		{
			a[i]=read();
			if (!t[a[i]])t[a[i]]=i;
			G.sum[t[a[i]]]++;
		}
		for (int i=1;i<=n;i++)
			if (G.sum[i]!=0)
				for (int j=a[i];j<=2e5;j+=a[i])
					if (t[j]&&t[j]!=i)G.add(t[j],i);//,cout<<t[j]<<' '<<i<<endl;
		cout<<n-G.tp()<<endl;
		G.clear(n);
	}
	return 0;
}
/*
1
5
7 9 3 14 63
*/