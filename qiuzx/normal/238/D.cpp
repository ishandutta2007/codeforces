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
#define N 100010
using namespace std;
ll rint(){
	ll ret=0;
	char c=getchar();
	while(!isdigit(c)) c=getchar();
	while(isdigit(c)) ret=ret*10+(c-'0'),c=getchar();
	return ret;
}
void rout(ll x){
	if(x<10) putchar(x+48);
	else rout(x/10),putchar((x%10)+48);
	return;
}
struct SegT{
	ll lo[N<<2],hi[N<<2],val[N<<2];
	void build(ll x,ll l,ll r)
	{
		lo[x]=l,hi[x]=r,val[x]=INF;
		if(l==r)
		{
			return;
		}
		ll mid=(l+r)>>1,a=x<<1;
		build(a,l,mid);
		build(a|1,mid+1,r);
		return;
	}
	void update(ll x,ll l,ll r,ll v)
	{
		ll tl=lo[x],tr=hi[x];
		if(l<=tl&&tr<=r)
		{
			val[x]=min(val[x],v);
			return;
		}
		ll mid=(tl+tr)>>1,a=x<<1;
		if(mid>=l)
		{
			update(a,l,r,v);
		}
		if(mid<r)
		{
			update(a|1,l,r,v);
		}
		return;
	}
	ll query(ll x,ll l)
	{
		ll tl=lo[x],tr=hi[x];
		if(tl==l&&tr==l)
		{
			return val[x];
		}
		ll mid=(tl+tr)>>1,a=x<<1;
		if(mid>=l)
		{
			return min(val[x],query(a,l));
		}
		return min(val[x],query(a|1,l));
	}
}segt;
ll n,q,lst[N],nxt[N],din[N],dout[N],sum[N*10][10],cnt=0;
char s[N];
void proc(ll x)
{
	ll d=1,i;
	while(x>=0&&x<n)
	{
		++cnt;
		din[x]=min(din[x],cnt);
		for(i=0;i<10;i++)
		{
			sum[cnt][i]=sum[cnt-1][i]+((s[x]-'0')==i);
		}
		if(s[x]=='0')
		{
			if(lst[x]>=0)
			{
				nxt[lst[x]]=nxt[x];
			}
			if(nxt[x]<n)
			{
				lst[nxt[x]]=lst[x];
			}
		}
		if(s[x]>'0'&&s[x]<='9')
		{
			s[x]--;
		}
		ll y;
		if(s[x]=='<')
		{
			d=0;
		}
		else if(s[x]=='>')
		{
			d=1;
		}
		if(d)
		{
			y=nxt[x];
		}
		else
		{
			if(lst[x]<x)
			{
				segt.update(1,lst[x]+1,x,cnt);
			}
			y=lst[x];
		}
		if(s[x]=='<'||s[x]=='>')
		{
			if(y>=0&&y<n)
			{
				if(s[y]=='<'||s[y]=='>')
				{
					if(lst[x]>=0)
					{
						nxt[lst[x]]=nxt[x];
					}
					if(nxt[x]<n)
					{
						lst[nxt[x]]=lst[x];
					}
				}
			}
		}
		x=y;
	}
	if(x==n)
	{
		din[x]=++cnt;
	}
	return;
}
int main(){
	ll i,l,r;
	n=rint(),q=rint();
	scanf("%s",&s);
	segt.build(1,0,n-1);
	for(i=0;i<n;i++)
	{
		lst[i]=i-1;
		nxt[i]=i+1;
	}
	memset(din,63,sizeof(din));
	for(i=0;i<n;i++)
	{
		if(din[i]>=INF)
		{
			proc(i);
		}
	}
	for(i=0;i<n;i++)
	{
		dout[i]=segt.query(1,i);
	}
	while(q--)
	{
		l=rint()-1,r=rint()-1;
		r=min(din[r+1]-1,dout[l]);
		l=din[l];
		for(i=0;i<10;i++)
		{
			rout(sum[r][i]-(l==0?0:sum[l-1][i])),putchar(' ');
		}
		putchar('\n');
	}
	return 0;
}