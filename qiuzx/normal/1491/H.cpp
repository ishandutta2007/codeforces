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
#define ll long long
#define N 150010
#define B 350
using namespace std;
ll rint(){
	ll ret=0;
	char c=getchar();
	while(!isdigit(c)) c=getchar();
	while(isdigit(c)) ret=ret*10+(c-'0'),c=getchar();
	return ret;
}
ll n,q,fa[N],nxt[N],cnt[B],tg[B];
void bruteupd(ll l,ll r,ll v)
{
	ll d=l/B,i;
	for(i=l;i<=r;i++)
	{
		cnt[d]-=(fa[i]>=d*B);
		fa[i]=max((ll)0,fa[i]-v);
		if(fa[i]<d*B)
		{
			nxt[i]=fa[i];
		}
		else
		{
			cnt[d]++;
			nxt[i]=nxt[fa[i]];
		}
	}
	for(i=r+1;i<(d+1)*B;i++)
	{
		cnt[d]-=(fa[i]>=d*B);
		if(fa[i]<d*B)
		{
			nxt[i]=fa[i];
		}
		else
		{
			cnt[d]++;
			nxt[i]=nxt[fa[i]];
		}
	}
	return;
}
int main(){
	ll i,l,r,x,tp;
	n=rint(),q=rint();
	for(i=1;i<n;i++)
	{
		fa[i]=rint()-1;
	}
	nxt[0]=0;
	for(i=1;i<n;i++)
	{
		if(fa[i]<(i/B)*B)
		{
			nxt[i]=fa[i];
		}
		else
		{
			cnt[i/B]++;
			nxt[i]=nxt[fa[i]];
		}
	}
	while(q--)
	{
		tp=rint(),l=rint()-1,r=rint()-1;
		if(tp==1)
		{
			x=rint();
			if(l/B==r/B)
			{
				bruteupd(l,r,x);
			}
			else
			{
				bruteupd(l,((l/B)+1)*B-1,x);
				bruteupd((r/B)*B,r,x);
			}
			for(i=l/B+1;i<r/B;i++)
			{
				if(cnt[i]==0)
				{
					tg[i]+=x;
				}
				else
				{
					bruteupd(i*B,(i+1)*B-1,x);
				}
			}
		}
		else
		{
			while(l!=r)
			{
				if(max((ll)0,nxt[l]-tg[l/B])!=max((ll)0,nxt[r]-tg[r/B]))
				{
					if(r==0||max((ll)0,nxt[l]-tg[l/B])>max((ll)0,nxt[r]-tg[r/B]))
					{
						swap(l,r);
					}
					r=max((ll)0,nxt[r]-tg[r/B]);
				}
				else
				{
					if(r==0||max((ll)0,fa[l]-tg[l/B])>max((ll)0,fa[r]-tg[r/B]))
					{
						swap(l,r);
					}
					r=max((ll)0,fa[r]-tg[r/B]);
				}
			}
			printf("%lld\n",l+1);
		}
	}
	return 0;
}