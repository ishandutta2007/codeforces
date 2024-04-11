#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize("inline","fast-math","unroll-loops","no-stack-protector")
#pragma GCC diagnostic error "-fwhole-program"
#pragma GCC diagnostic error "-fcse-skip-blocks"
#pragma GCC diagnostic error "-funsafe-loop-optimizations"
#pragma GCC diagnostic error "-std=c++14"
#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 998244353
#define F first
#define S second
#define ll int
#define N 100005
#define SZ 300
using namespace std;
ll rint(){
	ll ret=0;
	char c=getchar();
	while(!isdigit(c)) c=getchar();
	while(isdigit(c)) ret=ret*10+(c-'0'),c=getchar();
	return ret;
}
ll n,m,q,jmp[N][12];
bool vis[12];
char grid[N][12];
inline void getcalc(ll id)
{
	ll x;
	queue<ll> q;
	for(register int i=0;i<m;++i)
	{
		if(grid[id][i]=='^')
		{
			q.push(i),vis[i]=true,jmp[id][i]=(id%SZ==1?i:jmp[id-1][i]);
		}
		else
		{
			vis[i]=false;
		}
	}
	if(grid[id][0]=='<')
	{
		jmp[id][0]=-id*2,q.push(0),vis[0]=true;
	}
	if(grid[id][m-1]=='>')
	{
		jmp[id][m-1]=-id*2-1,vis[m-1]=true,q.push(m-1);
	}
	while(!q.empty())
	{
		x=q.front();
		q.pop();
		if(x-1>=0)
		{
			if(grid[id][x-1]=='>'&&(!vis[x-1]))
			{
				q.push(x-1),vis[x-1]=true,jmp[id][x-1]=jmp[id][x];
			}
		}
		if(x+1<m)
		{
			if(grid[id][x+1]=='<'&&(!vis[x+1]))
			{
				q.push(x+1),vis[x+1]=true,jmp[id][x+1]=jmp[id][x];
			}
		}
	}
	for(register int i=0;i<m;++i)
	{
		if(!vis[i])
		{
			jmp[id][i]=-INF;
		}
	}
	return;
}
inline void recalc(ll x)
{
	ll l,r;
	l=x*SZ+1;
	r=min((x+1)*SZ,n);
	for(register int i=l;i<=r;++i)
	{
		getcalc(i);
	}
	return;
}
int main(){
	ll x,y,nxt;
	char c;
	n=rint(),m=rint(),q=rint();
	for(register int i=1;i<=n;++i)
	{
		scanf("%s",&grid[i]);
	}
	for(register int i=0;i<=(n-1)/SZ;++i)
	{
		recalc(i);
	}
	while(q--)
	{
		c=getchar();
		while(c!='A'&&c!='C')
		{
			c=getchar();
		}
		x=rint(),y=rint()-1;
		if(c=='A')
		{
			while(true)
			{
				if(x<=0)
				{
					break;
				}
				nxt=jmp[x][y];
				if(nxt==-INF)
				{
					x=-INF,y=-INF;
					break;
				}
				if(nxt<0)
				{
					nxt=-nxt,x=nxt/2,y=nxt%2;
					y--;
					if(y==0)
					{
						y=m;
					}
					break;
				}
				x=((x-1)/SZ)*SZ;
				y=nxt;
			}
			x=(x==-INF?-1:x);
			y=(y==-INF?-2:y);
			printf("%d %d\n",x,y+1);
		}
		else
		{
			c=getchar();
			while(c!='<'&&c!='>'&&c!='^')
			{
				c=getchar();
			}
			grid[x][y]=c;
			recalc((x-1)/SZ);
		}
	}
	return 0;
}