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
int n,a,b,f[M],vis[M],ans;

queue<int>q;

void bfs(int s)
{
	q.push(s);vis[s]=1;
	while(!q.empty())
	{
		int x=q.front();q.pop(),f[s]++;
		if (x+a<=s&&!vis[x+a])
			vis[x+a]=1,q.push(x+a);
		if (x-b>=0&&!vis[x-b])
			vis[x-b]=1,q.push(x-b);
	}
}

int F(int n,int d)
{
	int sum=((n+1)/d)*((n+1)/d+1)*d/2;
	sum+=(n+1)%d*((n/d)+1);
	return sum;
}

signed main()
{
	n=read(),a=read(),b=read();
	f[0]=1,vis[0]=1;
	for (int i=1;i<=2*max(a,b);i++)
	{
		f[i]=f[i-1];
		if (i-a>=0&&vis[i-a])
			bfs(i);
	}
	for (int i=0;i<=min(n,2*max(a,b));i++)ans+=f[i];
	if (n>2*max(a,b))ans+=F(n,__gcd(a,b))-F(2*max(a,b),__gcd(a,b));
	cout<<ans<<endl;
	return 0;
}