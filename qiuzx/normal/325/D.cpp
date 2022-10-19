//ANMHLIJKTJIY!
#pragma GCC optimize(2)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline","fast-math","unroll-loops","no-stack-protector")
#pragma GCC diagnostic error "-fwhole-program"
#pragma GCC diagnostic error "-fcse-skip-blocks"
#pragma GCC diagnostic error "-funsafe-loop-optimizations"
#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 998244353
#define F first
#define S second
#define ll int
#define N 18000010
using namespace std;
ll rint(){
	ll ret=0;
	char c=getchar();
	while(!isdigit(c)) c=getchar();
	while(isdigit(c)) ret=ret*10+(c-'0'),c=getchar();
	return ret;
}
ll n,m,q,s,t,fa[N],dx[]={-1,-1,-1,0,0,1,1,1},dy[]={-1,0,1,-1,1,-1,0,1},ans=0;
bool vis[N];
ll getf(ll x){return x==fa[x]?x:fa[x]=getf(fa[x]);}
void merg(ll x,ll y)
{
	if(getf(x)!=getf(y))
	{
		fa[getf(x)]=getf(y);
	}
	return;
}
int main(){
	ll i,j,x,y,tx,ty,vx,vy;
	n=rint(),m=rint()<<1,q=rint();
	if(m==2)
	{
		puts("0");
		return 0;
	}
	for(i=0;i<n*m;++i)
	{
		fa[i]=i;
	}
	while(q--)
	{
		x=rint()-1,y=rint()-1;
		bool ok=true;
		for(i=0;i<8;++i)
		{
			tx=x+dx[i],ty=(y+dy[i]+m)%m;
			if(tx<0||tx>=n||(!vis[tx*m+ty]))
			{
				continue;
			}
			for(j=0;j<8;++j)
			{
				vx=x+dx[j],vy=(y+dy[j]+(m>>1)+m)%m;
				if(vx<0||vx>=n||(!vis[vx*m+vy]))
				{
					continue;
				}
				if(getf(tx*m+ty)==getf(vx*m+vy))
				{
					ok=false;
					break;
				}
			}
		}
		if(ok)
		{
			++ans;
			for(i=0;i<8;++i)
			{
				tx=x+dx[i],ty=(y+dy[i]+m)%m;
				if(tx<0||tx>=n)
				{
					continue;
				}
				if(vis[tx*m+ty])
				{
					merg(tx*m+ty,x*m+y);
				}
				ty=(y+dy[i]+(m>>1)+m)%m;
				if(vis[tx*m+ty])
				{
					merg(tx*m+ty,x*m+y+(m>>1));
				}
			}
			vis[x*m+y]=vis[x*m+y+(m>>1)]=true;
		}
	}
	cout<<ans<<endl;
	return 0;
}